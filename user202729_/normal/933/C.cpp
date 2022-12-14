// Turns out this problem was hard. Anyway.
// Failed system test? Really?............
// (I'm not supposed to know this during the contest, but I probably could not solve D anyway.)
//
//
//
// ====
// It's still me implementing circle-circle intersection wrong. :((((

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

template<class T,class U>
struct Point_{
	T x,y;
	Point_ constexpr operator+(Point_ p)const{return {x+p.x,y+p.y};}
	Point_ constexpr operator-(Point_ p)const{return {x-p.x,y-p.y};}
	Point_ constexpr operator*(T f)const{return {x*f,y*f};}

	Point_ constexpr& operator+=(Point_ p){return *this=*this+p;}
	Point_ constexpr& operator-=(Point_ p){return *this=*this-p;}
	Point_ constexpr& operator*=(T f    ){return *this=*this*f;}

	template<class T1,class U1>
	constexpr operator Point_<T1,U1>() const {return {(T1)x,(T1)y};}

#define COMPAREOP(OP) bool constexpr operator OP(Point_ p) const {return std::tie(x,y) OP std::tie(p.x,p.y);}
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	U constexpr cross(Point_ p)const{return x*(U)p.y-y*(U)p.x;}
	U constexpr dot  (Point_ p)const{return x*(U)p.x+y*(U)p.y;}
	U constexpr squaredLength()const{return dot(*this);}
	U constexpr squaredDistance(Point_ p)const{return (*this-p).squaredLength();}

	friend U cross(Point_ a,Point_ b,Point_ c){
		return (b-a).cross(c-a);
	} // >0: ccw

	friend std::istream& operator>>(std::istream& str,Point_& p){
		return str>>p.x>>p.y;
	}

	auto constexpr atan() const{ return std::atan2(1.*y/x); }
};

__attribute__((const)) int square(int it){ return it*it; }

using point=Point_<int, int>;
using pointd=Point_<double, double>;
struct circle{
	point center; int r;
	std::vector<pointd> intersect(circle const& other) const{
		// (perhaps I should copy some code online instead of reimplementing it?)

		auto squaredDistance=center.squaredDistance(other.center);
		if(squaredDistance>square(r+other.r)) return {};
		if(squaredDistance>square(r+other.r) or squaredDistance<square(std::abs(r-other.r)))
			return {};

		bool const touch=squaredDistance==square(r+other.r);
		double const distance=std::sqrt(squaredDistance);

		auto const cosAngle=(squaredDistance+square(r)-square(other.r))
			/(2*r*distance); // half angle at center of this circle, <=pi
		auto const sinAngle=std::sqrt(1-cosAngle*cosAngle);


		auto const v=pointd(other.center-center)*(r/distance);
		std::vector<pointd> result{
			pointd(center)+pointd{v.x*cosAngle-v.y*sinAngle, v.x*sinAngle+v.y*cosAngle}
		};
		if(not touch) result.push_back(
				pointd(center)+pointd{v.x*cosAngle+v.y*sinAngle, -v.x*sinAngle+v.y*cosAngle}
				);

		for(auto & it: result){
			assert(std::abs(std::sqrt(it.squaredDistance(center))-r)<=1e-11);
			assert(std::abs(std::sqrt(it.squaredDistance(other.center))-other.r)<=1e-11);
		}
		return result;
	}

};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numCircle; std::cin>>numCircle;
	std::vector<circle> circles(numCircle);
	for(auto & it: circles){
		std::cin>>it.center.x>>it.center.y>>it.r;
	}

	int numComponent{}, numEdge{}, numVertex{};
	//std::vector<std::vector<int>> add((int)circles.size());

	auto const makeUnique=[&](std::vector<pointd>& points){
		auto out=points.begin();
		for(auto next: points){
			if(not std::any_of(points.begin(), out, [&](pointd p){
				return p.squaredDistance(next)<=1e-22;
			}))
				*out++=next;
		}
		points.erase(out, points.end());
	};

	std::vector<pointd> points;
	for(int index=0;index<(int)circles.size();++index) {
		std::vector<pointd> intersections;
		for(int other=0;other<(int)circles.size();++other) if(other!=index){
			for(auto p: circles[index].intersect(circles[other]))
				intersections.push_back(p);
		}

		if(intersections.empty()){
			++numComponent;
			continue;
		}

		makeUnique(intersections);

		numEdge+=(int)intersections.size();
		for(auto p: intersections) points.push_back(p);
	}

	makeUnique(points);
	numVertex=(int)points.size();

	// now numComponent is the number of circles that doesn't touch anything
	// because numCircle<=3 it's possible to compute number of components from that number only
	if(numComponent<numCircle){
		assert(numCircle==1 or numComponent!=numCircle-1);
		++numComponent;
	}

	std::cout<<
		1+numComponent+numEdge-numVertex
		<<'\n';
}