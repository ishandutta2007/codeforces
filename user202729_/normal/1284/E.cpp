#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>

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

using pt=point<int,int64_t>;

bool ccw_compare(pt a,pt b){
	return a.cross(b)>0;
}

int64_t constexpr c3(int x){
	return x *(x-1LL) *(x-2LL)/6;
}
int64_t constexpr c4(int x){
	return x *(x-1LL) *(x-2LL) *(x-3LL)/24; 
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int npt;std::cin>>npt;
	std::vector<pt> pts(npt);
	for(auto& x:pts)std::cin>>x;

	int64_t out=0;

	for(int z=npt;z--;){
		auto const base=pts[z];

		// find f(base)
		int64_t f_base=c4(int(npt-1));

		auto tmp=pts; // location of other points relative to base
		tmp.erase(z+begin(tmp));
		for(auto& p:tmp){
			p-=base;
			assert((p!=pt{0,0}));
		}

		{
			auto iter=std::partition(begin(tmp),end(tmp),[](pt a){return a>pt{0,0};});
			std::sort(begin(tmp),iter,ccw_compare);
			std::sort(iter,end(tmp),ccw_compare);
		}

		for(unsigned l=0,r=1,lrsize=1;
				l<tmp.size();
				++l,assert(lrsize!=0),--lrsize
				){
			auto const inc_r=[&]{
				++r;
				++lrsize;
				if(r==tmp.size()) r=0;
			};
			if(l==r) inc_r();
			while(tmp[l].cross(tmp[r])>0){
				assert(l!=r);
				inc_r();
			}

			assert(lrsize!=0);
			f_base-=c3(lrsize-1);
		}

		assert(f_base>=0);
		out+=f_base;
	}
	std::cout<<out<<'\n';
}