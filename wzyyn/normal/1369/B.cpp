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
#define all(v) v.begin(),v.end()
using namespace std;
int n;
char s[500005];
void solve(){
	scanf("%d%s",&n,s+1);
	int l=1,r=n;
	for (;s[l]=='0';++l);
	for (;s[r]=='1';--r);
	For(i,1,l-1) cout<<'0';//<<endl;
	if (l<=r) cout<<'0';//<<endl;
	For(i,r+1,n) cout<<'1';
	cout<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}