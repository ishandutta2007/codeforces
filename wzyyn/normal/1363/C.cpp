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
#define double long double
using namespace std;

void solve(){
	int n,x,y,s=0;
	scanf("%d%d",&n,&x);
	For(i,1,2*(n-1)){
		scanf("%d",&y);
		if (y==x) ++s;
	}
	if (s==0||s==1) puts("Ayush");
	else puts(n&1?"Ashish":"Ayush");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}