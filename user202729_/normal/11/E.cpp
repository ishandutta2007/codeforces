// eliminated all occurrences of floating point numbers.
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct FixedPoint{
	int64_t value;

	FixedPoint(int it=0): value(it*(int64_t)100000000){}
	private:
	static FixedPoint make(int64_t value){ FixedPoint it; it.value=value; return it; }
	public:

	FixedPoint operator+(FixedPoint other) const{return make(value+other.value);}
	FixedPoint operator-(FixedPoint other) const{return make(value-other.value);}
	FixedPoint operator-() const{return make(-value);}
	FixedPoint operator*(int other) const{return make(value*other);}
	friend FixedPoint operator*(int other, FixedPoint it){return it*other;}
	FixedPoint floorDivision(int other) const{return make(value/other);}

	FixedPoint operator+=(FixedPoint other){return *this=*this+other;}
	FixedPoint operator-=(FixedPoint other){return *this=*this-other;}
	FixedPoint operator*=(int other){return *this=*this*other;}

#define compare(OP) bool operator OP(FixedPoint other) const{return value OP other.value;}
	compare(<) compare(>) compare(<=) compare(>=) compare(==) compare(!=)
#undef compare
};

FixedPoint solve(std::string const& steps){
	std::vector<char> correct; // char=bool. Value=1 if step is correct
	for(int index=0; index<(int)steps.size(); ++index){
		if(steps[index]!='X')
			correct.push_back((index%2!=0 ? 'R': 'L')==steps[index]);
	}

	auto const check=[&](FixedPoint factor){
		// equivalent: check if maximum(number of correct-factor*length)>=0
		// where length==steps.size()+number of added

		if(factor>1) return false;
		std::array<FixedPoint, 2> value; // [flipped] -> maximum value
		// only resulting even length is valid (resulting odd length is considered in the assignment to result below)
		// note that (number of added)%2==flipped

		for(int flipped=0; flipped<2; ++flipped)
			value[flipped]=-factor*((int)steps.size()+flipped);

		for(auto const correct1: correct){
			for(int flipped=0; flipped<2; ++flipped)
				value[flipped]+=correct1 xor flipped;
			for(int flipped=0; flipped<2; ++flipped)
				value[flipped]=std::max(value[flipped], value[not flipped]-factor);
		}
		return value[steps.size()%2]>=0;
	};

	FixedPoint result=FixedPoint((int)correct.size()).floorDivision(2*int((steps.size()+1)&~1));
	// ^ if final length is odd

	for(FixedPoint step=FixedPoint(1<<30).floorDivision(100000000); result.value!=(result+step).value; step=step.floorDivision(2)){
		if(check(result+step)) result+=step;
	}
	return result;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string steps; std::cin>>steps;
	{
		std::string steps1(1, steps[0]);
		std::for_each(1+begin(steps), end(steps),[&](auto ch){
			if(ch!='X' and ch==steps1.back()) steps1+='X';
			steps1+=ch;
		});
		steps=std::move(steps1);
	}

	FixedPoint result;
	if(steps[0]==steps.back()){
		result=solve('X'+steps);
		result=std::max(result, solve(steps+='X'));
	}else{
		result=solve(steps);
	}
	// print result*100
	std::cout<<result.value/1000000<<'.'<<std::setw(6)<<std::setfill('0')<<result.value%1000000<<'\n';
}