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
int n,m,s1[105],s2[105];
void solve(){
	scanf("%d%d",&n,&m);
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	For(i,1,n) For(j,1,m){
		int x;
		scanf("%d",&x);
		int p=abs(n+m+2-2*(i+j));
		s1[p]++; s2[p]+=(x?1:-1);
	}
	int ans=0;
	For(i,1,n+m) ans+=(s1[i]-abs(s2[i]))/2;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}