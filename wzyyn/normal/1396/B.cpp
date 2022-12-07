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
	int mx=0,s=0,n;
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		s+=x; mx=max(mx,x);
	}
	if (mx*2>s) puts("T");
	else puts(s&1?"T":"HL");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}