// https://vjudge.net/contest/260037#problem/B
#include<cassert>
#include<iostream>
#include<iomanip>
#include<array>
#include<vector>
#include<algorithm>

#define double long double

struct point{
	int x,y;
	int64_t constexpr operator*(point p)const{ // cross product
		return x*(int64_t)p.y-y*(int64_t)p.x;
	}
	point constexpr operator-(point p)const{
		return {x-p.x,y-p.y};
	}
};
bool constexpr strict_ccw(point a,point b,point c){
	return (a-b)*(a-c)>0;
}
bool collinear(point a,point b,point c){
	return (a-b)*(a-c)==0;
}
static_assert(strict_ccw({0,0},{1,0},{0,1}),"");

std::array<unsigned,2000001> nPointAtX;
int nPoint;
std::vector<point> points;

void fillNPointAtX(){
	std::fill(nPointAtX.begin(),nPointAtX.end(),0);
	if(strict_ccw(points[0],points[1],points[2]))
		std::reverse(points.begin(),points.end());
	// now (points) are in clockwise order

	point a=points.back();
	int maxXCoord=-1;
	for(point b:points){
		maxXCoord=std::max(maxXCoord,b.x);

		// segment AB is clockwise w.r.t. polygon (points)
		if(a.x==b.x){
			if(a.y>b.y){ // segment pointing downwards --> rightmost
				assert(a.x==maxXCoord);
				nPointAtX[a.x]+=a.y-b.y;
			}
		}else if(a.x<b.x){ // segment pointing rightwards
			for(int x=a.x;x<b.x;++x) // including the point on edge
				nPointAtX[x]+=unsigned((a.y*int64_t(b.x-x)+b.y*int64_t(x-a.x))/(b.x-a.x));
		}else{ // segment pointing leftwards
			for(int x=b.x;x<a.x;++x) // excluding the point on edge (ceil div, minus 1)
				nPointAtX[x]-=unsigned((b.y*int64_t(a.x-x)+a.y*int64_t(x-b.x)+a.x-b.x-1)/(a.x-b.x)-1);
		}

		// set a for next iteration
		a=b;
	}
	++nPointAtX[maxXCoord];
}

double expectedSquaredDiffX(){
	// compute based on nPointAtX.
	// let x to be an array of integers, for all n, number of (n)s in x is nPointAtX[n]
	// the return value is E((x[i]-x[j])^2) for 0<=i<j<x.size(), E: expected value
	double nValues=0,sumX=0,sumSquaredX=0;
	for(unsigned x=0;x<nPointAtX.size();++x){
		double n=nPointAtX[x];
		nValues+=n;
		sumX+=n*x;
		sumSquaredX+=n*x*x;
	}
	return 2*(nValues*sumSquaredX-sumX*sumX)/(nValues*(nValues-1));
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>nPoint;
	points.reserve(nPoint);
	for(int i=0;i<nPoint;++i){
		point p;
		std::cin>>p.x>>p.y;
		p.x+=1000000;p.y+=1000000;
		// this does not change the result, while it ensures that all coordinates are non-negative

		if(points.size()>1&&collinear(p,points.back(),*----points.end())){
			points.pop_back();
		}
		points.push_back(p);
	}


	assert(points.size()>=3);
	if(collinear(points[0],points.back(),points[1])){
		points.erase(points.begin());
		assert(points.size()>=3);
	}
	if(collinear(points[0],points.back(),points.rbegin()[1])){
		points.pop_back();
		assert(points.size()>=3);
	}
	// simplify the polygon

	
	// note that d^2 == (dx^2+dy^2)/2
	fillNPointAtX();
	double expSqrDiffX=expectedSquaredDiffX();
	for(point& p:points)
		std::swap(p.x,p.y);
	fillNPointAtX();
	double expSqrDiffY=expectedSquaredDiffX();

	std::cout<<std::fixed<<std::setprecision(10)<<(expSqrDiffX+expSqrDiffY)/2<<std::endl;
}