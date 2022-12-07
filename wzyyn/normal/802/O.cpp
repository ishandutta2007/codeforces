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
const int N=500005;
int n,m,a[N],b[N];
priority_queue<pll,vector<pll>,greater<pll> > Q; 
ll ans;
int solve(int x){
	ans=0;
	int num=0;
	For(i,1,n){
		Q.push(pll(a[i],0));
		ll t=Q.top().fi,now=b[i]-x;
		if (now+t<0){
			ans+=now+t; Q.pop();
			Q.push(pll(-now,1));
		}
	}
	for (;!Q.empty();num+=Q.top().se,Q.pop());
	return num;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	ll l=0,r=2e9;
	while (l<=r){
		ll mid=(l+r)/2;
		int sum=solve(mid);
		if (sum==m){
			printf("%lld\n",ans+1ll*m*mid);
			return 0;
		}
		if (sum<m) l=mid+1;
		else r=mid-1;
	}
}