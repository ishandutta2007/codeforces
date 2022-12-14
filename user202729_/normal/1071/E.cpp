/*
 * Unl)e problem D, I know how to solve this problem immediately. Only the implementation is more difficult.
 *
 * I didn't try generating large test to check for integer overflow
 * but int this problem width and height is only 1000, so it's unlikely to overflow.
 *
 * UPD: changed the algorithm a little. NOTE if still WA try to add some EPS.
 */
#include<functional>
#include<vector>
#include<cassert>
#include<iostream>
#include<tuple>
#include<iomanip>

double constexpr EPS=1e-9;

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
using ptd=point<double,double>;

std::pair<double,double> constexpr decompose(ptd c,ptd a,ptd b,double a_cross_b){
	assert(a_cross_b==a.cross(b));
	return {c.cross(b)/a_cross_b,a.cross(c)/a_cross_b};
}
std::pair<double,double> constexpr decompose(ptd c,ptd a,ptd b){
	return decompose(c,a,b,a.cross(b));
}

struct line{
	ptd a,b;

	std::pair<bool,std::pair<double,double>> constexpr intersect_pos(line s)const{
		// Return: {single intersect point, {position on line 1, position on line 2}}
		// use pos_to_point to get the point if necessary.
		ptd v1=b-a,v2=s.a-s.b,target=s.a-a;
		double d=v1.cross(v2);
		if(std::abs(d)<EPS)
			return {false,{0,0}};
		return {true,decompose(target,v1,v2,d)};
	}

	std::pair<double,double> constexpr must_intersect_pos(line s)const{
		ptd v1=b-a,v2=s.a-s.b,target=s.a-a;
		return decompose(target,v1,v2);
	}

	// position = 0 if point == a, 1 if point == b, linear
	ptd constexpr pos_to_point(double pos)const{
		return a+(b-a)*pos;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int n,width,height;std::cin>>n>>width>>height;

	ptd start; // int ud coordinate
	// note that int this code the direction of axis y is reversed
	// with respect to the image provided int the problem.
	std::cin>>start.y>>start.x;

	struct event{ int time;pt p; };
	std::vector<event> evs;evs.reserve(n);
	for(int z=n;z--;){
		int time,x,y;std::cin>>time>>x>>y;
		pt p{x,y};
		if(not evs.empty()){
			assert(time>=evs.back().time);
			if(time==evs.back().time){
				if(y==evs.back().p.y){
					if(x==evs.back().p.x) continue;
					std::cout<<"-1\n";
					return 0;
				}
				if(evs.size()>=2 and evs.end()[-2].time==time){
					if(cross(evs.end()[-2].p,evs.back().p,p)==0) continue;
					std::cout<<"-1\n";
					return 0;
				}
			}
		}
		evs.push_back({time,p});
	}

	struct req{
		int time;
		ptd a,b;
	}; // at time (time) the (u, d) point must be on the line segment ab
	std::vector<req> reqs;reqs.reserve(evs.size());
	auto iter=begin(evs);
	while(iter!=end(evs)){
		auto nxt=std::next(iter);
		if(nxt!=end(evs) and iter->time==nxt->time){
			pt a=iter->p,b=nxt->p;
			assert(a.y!=b.y);
			if(a.y<b.y)std::swap(a,b);
			if(not (
				cross(a,b,{0,0})<=0 and cross(a,b,{width,0})>=0 and 
				cross(a,b,{0,height})<=0 and cross(a,b,{width,height})>=0
			)){
				std::cout<<"-1\n";
				return 0;
			}

			line l{a,b};

			ptd ud_pos={
				l.must_intersect_pos(line{{0,(double)height},{1,(double)height}}).second,
				l.must_intersect_pos(line{{0,0},{1,0}}).second
			};
			for(double& coord:{std::ref(ud_pos.x),std::ref(ud_pos.y)}){
				coord=std::min(std::max(0.,coord),(double)(double)width); // avoid possible precision error
			}
			reqs.push_back({iter->time,ud_pos,ud_pos});

			iter=++nxt;
		}else{
			pt a=iter->p;

			line d_line{{0,0},{1,0}};
			ptd c={0,    d_line.must_intersect_pos({{0,(double)height},a}).first};
			ptd d={(double)width,d_line.must_intersect_pos({{(double)width,(double)height},a}).first};
			// d pos may overflow range [0..(double)width] for points c and d

			line u_line{{0,(double)height},{1,(double)height}};
			if(c.y>(double)width)
				c={u_line.must_intersect_pos({{(double)width,0},a}).first,(double)width};
			if(d.y<0)
				d={u_line.must_intersect_pos({{0,0},a}).first,0};

			assert(c.x>=-EPS and c.x<=(double)width+EPS);
			assert(c.y>=-EPS and c.y<=(double)width+EPS);
			assert(d.x>=-EPS and d.x<=(double)width+EPS);
			assert(d.y>=-EPS and d.y<=(double)width+EPS);
			reqs.push_back({iter->time,c,d});

			iter=nxt;
		}
	}

	evs.clear();

	double maxspeed=(double)width;
	for(double step=1024;step>1e-8;step/=2)if(maxspeed-step>0){
		maxspeed-=step;
		if(false){
invalid_v:
			maxspeed+=step;
			continue;
		}

		int lasttime=0;
		ptd c=start,d=start;
		for(auto [time,a,b]:reqs){
			auto newc=a,newd=b;
			int const dtime=time-lasttime;
			assert(dtime>0);
			double const rad=dtime*maxspeed;

			// restrict line newc..newd by polygon (segment c d) + (square with radius rad)
			auto proc=[&newc,&newd](line split,ptd ref)->bool{
				// Segment (newc,newd) := segment part of (newc,newd) int halfplane contains ref of split
				// Returns false if new segment is empty.
				line const cd{newc,newd};

				auto const [not_parallel_1,pos_1]=line{newc,ref}.intersect_pos(split);
				auto const newc_removed=not_parallel_1 and 0<pos_1.first and pos_1.first<1; // TODO use < without EPS here ok?

				auto const [not_parallel_2,pos_2]=line{newd,ref}.intersect_pos(split);
				auto const newd_removed=not_parallel_2 and 0<pos_2.first and pos_2.first<1;

				if(newc_removed and newd_removed)
					return false;
				if(not newc_removed and not newd_removed)
					return true;

				(newd_removed ? newd : newc)=cd.pos_to_point(split.must_intersect_pos(cd).second);
				return true;
			};

			assert(c.x<=d.x);
			auto const [miny,maxy]=std::minmax(c.y,d.y);

			if(not(
				proc(line{{c.x-rad,0},{c.x-rad,1}}  ,c) and
				proc(line{{d.x+rad,0},{d.x+rad,1}}  ,c) and
				proc(line{{0,miny-rad},{1,miny-rad}},c) and
				proc(line{{0,maxy+rad},{1,maxy+rad}},c)
			))
				goto invalid_v;

			if(c.x<d.x){
				if(c.y<d.y){
					ptd vec{-rad,rad};
					if(not (
						proc(line{c+vec,d+vec},c) and
						proc(line{c-vec,d-vec},c)
					))goto invalid_v;
				}
				if(c.y>d.y){
					ptd vec{rad,rad};
					if(not (
						proc(line{c+vec,d+vec},c) and
						proc(line{c-vec,d-vec},c)
					))goto invalid_v;
				}
			}

			c=newc;d=newd;
			lasttime=time;
		}
	}

	std::cout<<std::fixed<<std::setprecision(10)<<maxspeed<<'\n';
}