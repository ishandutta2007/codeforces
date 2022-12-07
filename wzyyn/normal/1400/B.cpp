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

void solve(){
	int a,b;
	int s1,s2;
	int t1,t2;
	scanf("%d%d%d%d%d%d",&a,&b,&s1,&s2,&t1,&t2);
	if (t1>t2)
		swap(t1,t2),swap(s1,s2);
	int res=0;
	For(i,0,s1){
		int ans=0,ra=a,rb=b,r1=s1,r2=s2,v;
		v=min(i,ra/t1);
		ra-=v*t1; r1-=v; ans+=v;
		v=min(r2,ra/t2);
		ra-=v*t2; r2-=v; ans+=v;
		v=min(r1,rb/t1);
		rb-=v*t1; r1-=v; ans+=v;
		v=min(r2,rb/t2);
		rb-=v*t2; r2-=v; ans+=v;
		res=max(res,ans);
	}
	cout<<res<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}