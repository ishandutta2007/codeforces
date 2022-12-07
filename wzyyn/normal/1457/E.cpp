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

priority_queue<ll> Q;
int n,k,a[500005];
ll ans;
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	For(i,1,k+1) Q.push(0);
	For(i,1,n){
		ll x=Q.top(); Q.pop();
		ans+=x;
		Q.push(x+a[i]);
	}
	cout<<ans<<endl;
}