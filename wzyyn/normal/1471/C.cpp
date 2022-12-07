#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
int n,m;
int a[500005];
int b[500005];
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m) scanf("%d",&b[i]);
	sort(a+1,a+n+1,greater<int>());
	ll res=0;
	For(i,1,n) res+=min(b[a[i]],b[min(m,i)]);
	cout<<res<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}