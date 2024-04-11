#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N=500005;
ll a[N],sum[N],n;
#define Rep(i,a,b) for(int i=(a);i<=(b);++i)
double ans=0;
double f(int w,int i)
{
	return w-1.0*(sum[i]+w)/(i+1);
}
int main()
{
	int Q;
	scanf("%d",&Q);
	n=0;
	while (Q--)
	 {
		int op;
		scanf("%d",&op);
		if (op==1)
		 {
		 	int w;
			scanf("%d",&w);
			a[++n]=w;sum[n]=sum[n-1]+w;
			int L=1,R=n-1;
			while (R-L>=3)
			 {
				int Lmid=L+(R-L)/3;
				int Rmid=R-(R-L)/3;
				if (Lmid==Rmid) break;
				if (f(w,Lmid)>f(w,Rmid))R=Rmid;
				else L=Lmid;
			 }
			Rep(i,L,R) ans=max(ans,f(w,i));
		 }
		else printf("%.10lf\n",ans);
	 }
	return 0;
}