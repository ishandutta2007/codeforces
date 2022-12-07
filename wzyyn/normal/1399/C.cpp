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
int a[105],s[105];
void solve(){
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	int n,x;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&x),++a[x];
	For(i,1,n) For(j,i+1,n) s[i+j]+=min(a[i],a[j]);
	For(i,1,n) s[i+i]+=a[i]/2;
	cout<<*max_element(s+1,s+n+n+1)<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}