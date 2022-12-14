#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const double PI=3.14159265358979323846264;
const double eps=1e-9;

int xs[22],ys[22],ang[22];

double getNxt(int id,double a){
	double x=xs[id],y=ys[id],theta=(double)ang[id]*PI/180;
	if(y<0) y*=-1;
	double dx=a-x;
	double phi=atan(dx/y);
	if(phi+theta>PI/2-eps){
		return -(1e8);
	}
//	printf("%d %f %f\n",id,a,y*tan(phi+theta)+x);
	return y*tan(phi+theta)+x;
}

double dp[1<<20];

int main(){
	int N,l,r;
	scanf("%d%d%d",&N,&l,&r);
	for(int i=0;i<N;i++){
		scanf("%d%d%d",xs+i,ys+i,ang+i);
	}
	for(int i=0;i<(1<<N);i++) dp[i]=-(1e7);
	dp[0]=l;
	for(int i=0;i<(1<<N);i++){
		for(int j=0;j<N;j++){
			if((i&(1<<j))!=0) continue;
			double nxt=getNxt(j,dp[i]);
			if(nxt<-1e7){
				printf("%.9f\n",(double)r-l);
				return 0;
			}
			dp[i|(1<<j)]=max(dp[i|(1<<j)],nxt);
		}
	}
	if(dp[(1<<N)-1]>r) dp[(1<<N)-1]=r;
	printf("%.9f\n",dp[(1<<N)-1]-l);
	return 0;
}