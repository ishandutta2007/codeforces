// time-limit: 3000
// problem-url: https://codeforces.com/contest/1588/problem/E


// ... what kind of bug is that.


#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
// { ==== Begin library Point.h ====
// (local note) see also: geometry.cpp

template<class T,class U>
struct Point_{
	T x,y;
	Point_ constexpr operator+(Point_ p)const{return {x+p.x,y+p.y};}
	Point_ constexpr operator-(Point_ p)const{return {x-p.x,y-p.y};}
	Point_ constexpr operator-()const{return {-x,-y};}
	Point_ constexpr operator*(T f)const{return {x*f,y*f};}

	Point_ constexpr& operator+=(Point_ p){return *this=*this+p;}
	Point_ constexpr& operator-=(Point_ p){return *this=*this-p;}
	Point_ constexpr& operator*=(T f    ){return *this=*this*f;}

	template<class T1,class U1>
	constexpr operator Point_<T1,U1>() const {return {(T1)x,(T1)y};}

#define COMPAREOP(OP) bool constexpr operator OP(Point_ p) const {return std::tie(x,y) OP std::tie(p.x,p.y);}
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	[[nodiscard]] U constexpr cross(Point_ p)const{return x*(U)p.y-y*(U)p.x;}
	[[nodiscard]] U constexpr dot  (Point_ p)const{return x*(U)p.x+y*(U)p.y;}
	[[nodiscard]] U constexpr norm()const{return dot(*this);}
	[[nodiscard]] U constexpr squaredLength()const{return norm();}
	[[nodiscard]] U constexpr squaredDistance(Point_ p)const{return (*this-p).norm();}
	[[nodiscard]] double constexpr length()const{return std::sqrt(norm());}
	[[nodiscard]] double constexpr distance(Point_ p)const{return std::sqrt(squaredDistance(p));}

	friend U cross(Point_ a,Point_ b,Point_ c){
		return (b-a).cross(c-a);
	} // >0: ccw

	Point_ rotateRight() const{return {y, -x};}
	Point_ rotateLeft() const{return {-y, x};}

	friend std::istream& operator>>(std::istream& str,Point_& p){
		return str>>p.x>>p.y;
	}
};

// } ==== End library Point.h ====

// { ==== Begin library ConvexHull.h ====

// return points in *clockwise* order
template<class PointT>
std::vector<PointT> convexHull(std::vector<PointT> points){

	std::vector<PointT> result;
	result.reserve(points.size());

	std::sort(begin(points),end(points),[&](PointT first, PointT sec){
		auto const tied=[&](PointT const& it){return std::tie(it.x, it.y);};
		return tied(first)<tied(sec);
	});
	points.erase(std::unique(begin(points), end(points)), end(points));
	if(points.size()<=1) return points;

	for(auto point: points){
		while(result.size()>=2 and cross(result.back(), result.end()[-2], point)<=0)
			result.pop_back();
		result.push_back(point);
	}
	auto const upperSize=result.size();
	std::for_each(1+points.rbegin(), points.rend(), [&](PointT point){
		while(result.size()>upperSize and cross(result.back(), result.end()[-2], point)<=0)
			result.pop_back();
		result.push_back(point);
	});
	result.pop_back();
	return result;
}

// } ==== End library ConvexHull.h ====

// { ==== Begin library ConvexHullMaxDot.h ====

template<class P> auto maxDot(std::vector<P> const& hull, P point){
	// return the index i such that hull[i].dot(point) is the maximum.
	int i=0;
	for(int step=2<<(31^__builtin_clz((int)hull.size())); step; step>>=1){
		int j;
		j=(i+step)%(int)hull.size();
		if(hull[j].dot(point)>hull[i].dot(point))
			i=j;
		else{
			j=(i-step)%(int)hull.size();
			if(j<0) j+=(int)hull.size();
			if(hull[j].dot(point)>hull[i].dot(point)) i=j;
		}
	}
	struct ReturnType{
		int index;
		P point;
		decltype(point.dot(point))  value;
	};
	return ReturnType{i, hull[i], hull[i].dot(point)};
};

// } ==== End library ConvexHullMaxDot.h ====

// { ==== Begin library PointSortAngle.h ====
template<class P> void sortPointsByAngle(std::vector<P>& points, P pivot){
	// sort all points by angle around the pivot. Handle the whole round.
	// Angle 0 (points right) is first.
	auto it=std::partition(begin(points), end(points), [&](auto const& it){
		assert(it!=pivot);
		return std::tie(it.y, it.x)>std::tie(pivot.y, pivot.x);
	});
	auto const compare=[&](auto const& first, auto const& sec){
		return cross(pivot, first, sec)>0;
	};
	std::sort(begin(points), it, compare);
	std::sort(it, end(points), compare);
}


// } ==== End library PointSortAngle.h ====

// { ==== Begin library PointDistanceToSegment.h ====
template<class P> double distanceSegment(P x, P a, P b){
	if((x-a).dot(b-a)<=0) return a.distance(x);
	if((x-b).dot(b-a)>=0) return b.distance(x);
	return std::abs((double)(x-a).cross(b-a)/a.distance(b));
}

// } ==== End library PointDistanceToSegment.h ====
using P=Point_<int, int64_t>;


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	
	int n; std::cin>>n;
	int _rad; std::cin>>_rad;
	auto const radSquared=_rad*(int64_t)_rad;
	
	std::vector<P> points(n);
	for(auto& [x, y]: points) std::cin>>x>>y;

	auto const hull=convexHull(points);
	std::vector suitable(n, std::vector<bool>(n, true));
	for(int i=0; i<n; ++i){

		std::vector<P> far;
		for(int j=0; j<n; ++j) if(points[j].squaredDistance(points[i])>radSquared)
			far.push_back(points[j]);
		sortPointsByAngle(far, points[i]);
		// now far=set of points far from i sorted by angle

		if(not far.empty()){
			// some points are not suitable as outside-circle
			// mark suitable[i][j] as false correspondingly


			std::vector<std::pair<P, P>> freeRanges; // each element is (a, b)
			// where a, b are vectors from i that denotes a range of angles that is strictly > /2 radians
			// without any points inbetween
			for(int k=0; k<(int)far.size(); ++k){
				auto const cur=far[k]-points[i], next=far[k+1==(int)far.size() ? 0: k+1]-points[i];
				auto const cross=cur.cross(next);
				if(cross<0){
					freeRanges.push_back({cur, next}); // don't need to consider exactly 180 degrees
				}
			}
			
			// special case  only one direction
			{
				auto const a=far[0]-points[i], b=far.back()-points[i];
				if(a.cross(b)==0 and a.dot(b)>0){
					freeRanges.push_back({a, a});
				}
			}

			assert(freeRanges.size()<=1);

			if(freeRanges.empty()){
				// none are suitable
				suitable[i].assign(n, false);
				continue;
			}

			auto const [a, b]=freeRanges[0];
			for(int j=0; j<n; ++j)
				if(not(
							a.dot(points[j]-points[i])>=0 and
							b.dot(points[j]-points[i])>=0
					  ))
					suitable[i][j]=false;
		}

	}

	// now, suitable[i][j] is false \iff
	// there's some point on the opposite side of j far from i (etc.)

	int result {};
	for(int i=0; i<n; ++i)
		for(int j=0; j<i; ++j){
			bool okay=false;
			if(suitable[i][j] and suitable[j][i]){
				auto const v=(points[j]-points[i]).rotateLeft();
				if(
						(double)(maxDot(hull, v).point-points[i]).dot(v)/v.length()   < (double)_rad and
						(double)(maxDot(hull, -v).point-points[i]).dot(-v)/v.length() < (double)_rad)
					okay=true;
			}

			result+=okay;

			assert(([&]{
				double const epsilon=1e-2;
				auto const a=points[i], b=points[j];
				bool anyR=false;
				for(auto k: points){
					auto const d=distanceSegment(k, a, b);
					if(d>_rad+epsilon){
						assert(not okay);
						return true;
					}
					if(d>_rad-epsilon)
						anyR=true;
				}
				if(not anyR) assert(okay);
				return true;
			}()));
		}

	std::cout<<result<<'\n';
}