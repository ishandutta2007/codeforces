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
int n,k,a[N],f[N];
priority_queue<pll> Q;
ll F(int x,int y){
	if (x<y) return 1ll<<40;
	ll c=x/y,s1=x%y,s2=y-s1;
	return (c+1)*(c+1)*s1+c*c*s2;
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]),f[i]=1;
	For(i,1,n) Q.push(pll(F(a[i],f[i])-F(a[i],f[i]+1),i));
	For(i,n+1,k){
		int x=Q.top().se;
		Q.pop();
		++f[x];
		Q.push(pll(F(a[x],f[x])-F(a[x],f[x]+1),x));
	}
	ll ans=0;
	For(i,1,n)
		ans+=F(a[i],f[i]);
	cout<<ans<<endl;
}