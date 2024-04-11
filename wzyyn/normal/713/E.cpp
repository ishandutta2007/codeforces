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
const int N=100005;
int f[N][2],a[N],n,m;
bool check(int x){
	int st0=0,st1=0;
	for (;st0<=x;){
		f[1][0]=(!st0?-x:st0);
		f[1][1]=st1;
		For(i,2,n+1) f[i][0]=1e9,f[i][1]=0;
		For(i,1,n){
			if (f[i][0]>x) return 0;
			
			int l1;
			if (f[i][0]>0) l1=a[i+1]-a[i]+f[i][0];
			else l1=a[i+1]-a[i]-x;
			if (l1>0&&f[i][0]<=0) --l1;
			if (l1<0) f[i+1][0]=-x;
			else f[i+1][0]=min(f[i+1][0],l1);
			
			int l2=a[i+1]-a[i]+f[i][1];
			if (l2>0) l2--;
			if (l2<0) f[i+1][0]=-x;
			else f[i+1][0]=min(f[i+1][0],l2);
			
			if (l1<=x) f[i+1][1]=min(f[i+1][1],a[i+1]-a[i]-x);
			f[i+1][1]=min(f[i+1][1],l2);
		}
		if (f[n+1][0]<=st0&&f[n+1][1]<=st1) return 1;
		st0=f[n+1][0]; st1=f[n+1][1];
	}
	return 0;
}
/*
f[i][0]:
f[i][1]: 
*/
int main(){
	scanf("%d%d",&m,&n);
	For(i,1,n) scanf("%d",&a[i]);
	a[n+1]=a[1]+m;
	int l=0,r=m-n,ans=0;
	while (l<=r){
		//cout<<l<<' '<<r<<endl; 
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}