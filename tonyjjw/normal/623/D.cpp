//*

#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

const int MN = 100+1;
const int MM = 400000+1;

double mypow(double a,int n){
	double res=1;
	while(n>0){
		if(n&1) res=res*a;
		a=a*a;
		n>>=1;
	}
	return res;
}

int N;
double p[MN];
int c[MN];

double prob(int i,int j){
	return 1-mypow(1-p[i],j);
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		p[i]=(double)x/100;
	}
	for(int i=0;i<N;i++)c[i]=1;
	double ans=N;
	for(int it=0;it<MM;it++){
		double maxp=0;
		int pp=-1;
		for(int i=0;i<N;i++){
			double hv=prob(i,c[i]+1)/prob(i,c[i]);
			if(maxp<hv){
				maxp=hv;
				pp=i;
			}
		}
		double v=1;
		for(int i=0;i<N;i++){
			v*=prob(i,c[i]);
		}
		ans+=1-v;
		c[pp]++;
	}
	printf("%.12lf\n",ans);
	return 0;
}

//*/