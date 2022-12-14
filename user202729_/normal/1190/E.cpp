#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cfloat>
#include<iomanip>

double sqr(int x){
	return x*(double)x;
}

double const PI=std::acos(-1);

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m;std::cin>>n>>m;

	struct pt{
		int x,y;
		double angle;
	};
	std::vector<pt> points(n);

	double mind=DBL_MAX;

	for(pt& p:points){
		std::cin>>p.x>>p.y;
		if(p.x==0&&p.y==0){
			std::cout<<"0\n";
			return 0;
		}
		p.angle=std::atan2(p.y,p.x);
		if(p.angle<0)p.angle+=2*PI;
		mind=std::min(mind,std::hypot(p.x,p.y));
	}

	double r=mind; // r + eps is invalid
	double step=1e6;
	for(int _=0;_<50;++_,step/=2){ // find min invalid r + eps
		if(r-step<=0)
			continue;

		r-=step;
		bool valid;

		struct event{
			bool isleft;
			double angle;
			double right; // if isleft = true
			int index;
		};
		std::vector<event> evs;evs.reserve(4*n);

		for(int i=0;i<n;++i){
			pt const p=points[i];
			double angle=p.angle;
			double delta=std::acos(r/std::hypot(p.x,p.y));
			if(angle-delta<0)
				angle+=2*PI;
			double l=angle-delta,r=angle+delta;

			evs.push_back({true,l,r,i});
			evs.push_back({false,r,-1,i});
			evs.push_back({true,l+2*PI,r+2*PI,i});
			evs.push_back({false,r+2*PI,-1,i});
		}
		std::sort(begin(evs),end(evs),[](event a,event b){
				return a.angle>b.angle;
				});

		std::vector<int> nextindex(n,-1);
		std::vector<double> min_r_gap(n,DBL_MAX);

		double minr=DBL_MAX;int minr_ind=-1;
		for(auto e:evs){
			if(e.isleft){
				if(e.right<minr){
					minr=e.right;minr_ind=e.index;
				}
			}else{
				double& gap=min_r_gap[e.index];
				double newgap=minr-e.angle;
				if(newgap<gap){
					gap=newgap;
					nextindex[e.index]=minr_ind;
				}
			}
		}

		int a=0,b=0;
		do{
			a=nextindex[a];a=nextindex[a];
			b=nextindex[b];
		}while(a!=b);

		int min_n_barrier=0;
		double total_len=0;
		double const EPS=1e-8;
		do{
			total_len+=min_r_gap[a];
			a=nextindex[a];
			++min_n_barrier;
		}while(total_len<PI*2-EPS);
		valid=min_n_barrier<=m;

		if(valid)
			r+=step;
	}

	std::cout<<std::fixed<<std::setprecision(10)<<r<<'\n';
}