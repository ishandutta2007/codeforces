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
const int N=200005;
const double pi=acos(-1);
int n,d,Q,a[N];
int main(){
	scanf("%d%d",&n,&d);
	For(i,1,n) scanf("%d",&a[i]);
	scanf("%d",&Q);
	while (Q--){
		int x;
		scanf("%d",&x);
		int p=lower_bound(a+1,a+n+1,x)-a;
		if (a[p-1]==x-1&&a[p]==x) printf("%.15lf\n",pi);
		else if (a[p-1]==x-1||a[p]==x) printf("%.15lf\n",pi/2);
		else{
			double ans=0;
			if (p!=n+1) ans=max(ans,atan2(1,a[p]-x));
			if (p!=1) ans=max(ans,atan2(1,x-a[p-1]-1));
			int pl=p-1,pr=p,d=min(a[p]-x,x-a[p-1]-1);
			for (;pl>=1&&pr<=n&&a[pr]-a[pl]<=5*d+10;){
				int d1=a[pr]-x,d2=x-a[pl]-1;
				if (abs(d1-d2)<=1){
					ans=max(ans,2*atan2(1,max(d1,d2)));
					break;
				}
				d1>d2?pl--:pr++;
			}
			printf("%.15lf\n",ans);
		}
	}
}