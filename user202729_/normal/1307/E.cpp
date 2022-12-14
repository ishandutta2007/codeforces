// <s>The problems are harder than</s> My codes are more buggy than I expected.
// 
// Again, my implementation speed was very slow. At least for this problem there was not any
// significant bug.
// I don't know if it's because I'm not yet familiar with the steno keyboard.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
int const MOD=1000000007;
struct modular {
	int val;
	explicit constexpr operator int() const { return val; }
	constexpr modular():val(){}
#if MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE
	constexpr modular(auto v):val(int(v%MOD)){ if(val<0)val+=MOD; }
#else
	constexpr modular(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) bool constexpr operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	friend modular operator-(modular x) { x.val=x.val?MOD-x.val:0; return x; }
	modular constexpr& operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular constexpr& operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular constexpr& operator*=(modular m) {
		if(__builtin_constant_p(m.val)){
			switch(m.val){
				case 1: return *this;
				case 2: return *this+=*this;
				case 3: return *this+=*this+*this;
				case 0: return *this=0;
				case -1: return *this=-*this;
			}
		}else if(__builtin_constant_p(val)){
			*this=m**this;
		}
		val = int((int64_t)val*m.val%MOD);
		return *this;
	}
	modular constexpr pow(int p) const {
		modular a=*this;
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	modular constexpr inv() const {
		int a=val,b=MOD, ax=1,bx=0;
		while(b){
			int q=a/b, t=a%b;
			a=b; b=t;
			t=ax-bx*q; ax=bx; bx=t;
		}
		assert(a==1);
		if(ax<0)ax+=MOD;
		return ax;
	}
	modular constexpr& operator/=(modular m) { return (*this) *= m.inv(); }

#define ARITHBINARYOP(OP) friend modular constexpr operator OP(modular a, modular b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numGrass, numCows; std::cin>>numGrass>>numCows;
	std::vector<int> typeAt(numGrass);
	std::vector<int> time; time.reserve(numGrass);

	std::vector<int> countByType(numGrass+1);
	std::vector<std::vector<int>> positionsByType(numGrass+1);
	for(int pos=0;pos<numGrass;++pos) {
		auto& type=typeAt[pos];
		std::cin>>type;
		positionsByType[type].push_back(pos);
		time.push_back(countByType[type]++);
	}

	std::unordered_map<int, std::vector<int>> hungerByType;
	for(int _=0;_<numCows;++_) {
		int type, hunger; std::cin>>type>>hunger;
		hungerByType[type].push_back(hunger);
		//auto& value=*minimumHunger.insert({type,{{INT_MAX, INT_MAX}}}).first;
		//value[1]=std::min(value[1], hunger);
		//if(value[1]<value[0]) std::swap(value[0], value[1]);
	}

	for(auto & [type, values]: hungerByType) std::sort(begin(values), end(values));

	int maxSleep=0; modular totalWay=0;

	for(int split=0;split<=numGrass;++split) {	
		int numSleep=0; modular numWay=1;
		if(split!=0 and not hungerByType.count(typeAt[split-1])){
			 continue;
		}
		for(auto const& [type, values]: hungerByType) {
			if(split!=0 and type==typeAt[split-1]){
				auto const maxHungry1=time[split-1]+1;
				if(not std::binary_search(begin(values),end(values), maxHungry1)){
					// no cow of required type and hunger to split at this position
					goto continue_outer;
				}
				auto const maxHungry2=countByType[type]-maxHungry1;

				auto const numChoice1=std::upper_bound(begin(values),end(values),maxHungry1)-begin(values);
				assert(numChoice1>0);
				auto numChoice2=std::upper_bound(begin(values),end(values),maxHungry2)-begin(values);
				if(numChoice2==numChoice1)--numChoice2;
				if(numChoice2==0){
					++numSleep;
				}else{
					numSleep+=2; numWay*=numChoice2-(numChoice2>numChoice1);
				}
			}else{
				auto maxHungry1=std::lower_bound(begin(positionsByType[type]),end(positionsByType[type]),
						split)-begin(positionsByType[type]); // could be slightly faster by keeping pointers
				auto maxHungry2=countByType[type]-maxHungry1;
				if(maxHungry1>maxHungry2) std::swap(maxHungry1, maxHungry2);

				auto const numChoice1=std::upper_bound(begin(values),end(values),maxHungry1)-begin(values);
				auto const numChoice2=std::upper_bound(begin(values),end(values),maxHungry2)-begin(values);

				assert(numChoice1<=numChoice2);
				if(numChoice2==0){
				}else if(numChoice1==0) {
					++numSleep; numWay*=numChoice2;
				}else if(numChoice2==1){
					assert(numChoice1==1);
					numSleep+=1;
					numWay*=2;
				}else{
					numSleep+=2;
					numWay*=numChoice1;
					numWay*=numChoice2-1;
				}
			}
		}

		if(numSleep==maxSleep) totalWay+=numWay;
		else if(numSleep>maxSleep){ totalWay=numWay; maxSleep=numSleep; }

continue_outer:;
	}
	std::cout<<maxSleep<<' '<<(int)totalWay<<'\n';
}