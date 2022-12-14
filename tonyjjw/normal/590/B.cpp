//*

#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

const double eps = 1e-9;

int main(){
	int x1,x2,y1,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	int dx=x2-x1;
	int dy=y2-y1;
	int v,t;
	scanf("%d%d",&v,&t);
	int vx,vy,wx,wy;
	scanf("%d%d%d%d",&vx,&vy,&wx,&wy);

	double l=0,m,r=1e18;
	double ans;
	for(int it=0;it<100000;it++){
		m=(l+r)/2;
		double x,y;
		if(m<t+eps){
			x=x1+vx*m;
			y=y1+vy*m;
		}
		else{
			x=x1+vx*t+wx*(m-t);
			y=y1+vy*t+wy*(m-t);
		}
		double len=(x2-x)*(x2-x)+(y2-y)*(y2-y);
		if(m*m*v*v>len-eps){
			ans=m;
			r=m;
		}
		else{
			l=m;
		}
	}
	printf("%.12lf\n",ans);
	return 0;
}

//*/