// Optimization. Not benchmarked.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

template<class T,class U>
struct point{
	T x,y;
	point constexpr operator+(point p)const{return {x+p.x,y+p.y};}
	point constexpr operator-(point p)const{return {x-p.x,y-p.y};}
	point constexpr operator*(T f)const{return {x*f,y*f};}

	point constexpr& operator+=(point p){return *this=*this+p;}
	point constexpr& operator-=(point p){return *this=*this-p;}
	point constexpr& operator*=(T f    ){return *this=*this*f;}

	template<class T1,class U1>
	constexpr operator point<T1,U1>() const {return {(T1)x,(T1)y};}

#define COMPAREOP(OP) bool constexpr operator OP(point p) const {return std::tie(x,y) OP std::tie(p.x,p.y);}
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	U constexpr cross(point p)const{return x*(U)p.y-y*(U)p.x;}
	U constexpr dot  (point p)const{return x*(U)p.x+y*(U)p.y;}
	U constexpr sqrlen()const{return dot(*this);}

	friend U cross(point a,point b,point c){
		return (b-a).cross(c-a);
	} // >0: ccw

	friend std::istream& operator>>(std::istream& str,point& p){
		return str>>p.x>>p.y;
	}
};

using L=double;

using Point=point<L,L>;



int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	struct car{Point start, velocityDenormalized; double multiplier;};
	std::vector<car> cars(number);
	for(auto &[start, velocityDenormalized, multiplier]: cars){
		std::array<int, 5> stuff;for(auto & it: stuff) std::cin>>it;
		start={(L)stuff[0], (L)stuff[1]};
		velocityDenormalized={(L)stuff[2], (L)stuff[3]};
		multiplier=(L)stuff[4]/std::sqrt(velocityDenormalized.sqrlen());
	}

	L result=DBL_MAX;

	for(auto const& first: cars)
	for(auto const& sec: cars){
		if(&sec==&first) break;
		auto const cross=first.multiplier* sec.multiplier* first.velocityDenormalized.cross( sec.velocityDenormalized);
		auto const d=sec.start-first.start;
		if(first.velocityDenormalized.cross(sec.velocityDenormalized)==0) {
			if(first.velocityDenormalized.cross(d)!=0) continue;
			auto a=first.multiplier*first.velocityDenormalized.dot(d);
			auto b=sec.multiplier*sec.velocityDenormalized.dot(d);
			a/=d.sqrlen();
			b/=d.sqrlen();

			b=-b;
			if(first.velocityDenormalized.dot(d)>0 or sec.velocityDenormalized.dot(d)<0){
				result=std::min(result, 1./(std::max(a, (L)0)+ std::max(b, (L)0)));
			}
			continue;
		}

		auto a=
				sec.multiplier*
			d.cross(
				sec.velocityDenormalized)/cross;
		auto b=first.multiplier*first.velocityDenormalized.cross(d)/cross;
		b=-b;
		if(d.cross(sec.velocityDenormalized)*cross>=0 and first.velocityDenormalized.cross(d)*cross<=0){
			result=std::min(result, std::max(a, b));
		}
	}

	if(result==DBL_MAX)
		std::cout<<"No show :(\n";
	else
		std::cout<<std::fixed<<std::setprecision(15)<<result<<'\n';
}