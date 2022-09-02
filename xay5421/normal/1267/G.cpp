#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=105,M=10005;
int n,x,c[N],allv;
double f[N][M];
int main(){
	scanf("%d%d",&n,&x);
	f[0][0]=1;
	rep(i,1,n){
		scanf("%d",&c[i]);
		allv+=c[i];
		per(j,i,1){
			per(k,allv,c[i]){
				f[j][k]+=f[j-1][k-c[i]]*j/(n-j+1);
			}
		}
	}
	double ans=0;
	rep(i,0,n-1)rep(j,0,allv){
		ans+=f[i][j]*min((double(n)/(n-i)+1)*x*.5,double(allv-j)/(n-i));
	}
	printf("%.20f\n",ans);
	return 0;
}