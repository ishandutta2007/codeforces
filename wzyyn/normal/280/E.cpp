#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;

const int N=6005;
#define pdd pair<double,double>
int n,mx,A,B,top,k;
double x[N],ans[N],tmp;
pdd q[N*2];
int main(){
	scanf("%d%d%d%d",&n,&mx,&A,&B);
	For(i,1,n){
		scanf("%lf",&x[i]);
		if (i==1){
			q[++top]=pdd(1,2*(1-x[i]));
			q[++top]=pdd(1e18,2*(1e18-x[i]));
			k=1; 
		}
		else{
			Rep(j,top,k+1) q[j+2]=q[j];
			top+=2; k++;
			q[k]=q[k+1]=pdd(tmp,0);
			For(j,1,k) q[j].fi+=A;
			For(j,k+1,top) q[j].fi+=B;
			For(j,1,top) q[j].se+=2*(q[j].fi-x[i]);
		}
		if (q[1].se>0) k=0,tmp=q[1].fi;
		else{
			for (k=1;k<=top;k++)
				if (q[k].se<=0&&q[k+1].se>0) break;
			tmp=q[k].fi-q[k].se/(q[k+1].se-q[k].se)*(q[k+1].fi-q[k].fi);
		}
		ans[i]=tmp;
	}
	ans[n]=min(ans[n],1.0*mx);
	Rep(i,n,2) ans[i-1]=max(ans[i]-B,min(ans[i]-A,ans[i-1]));
	For(i,1,n) printf("%.15lf ",ans[i]);
	double sum=0; puts("");
	For(i,1,n) sum+=(x[i]-ans[i])*(x[i]-ans[i]);
	printf("%.15lf\n",sum);
}