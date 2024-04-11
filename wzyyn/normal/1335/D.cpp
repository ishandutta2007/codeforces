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
char s[15][15];
int p[]={0,1,4,7,2,5,8,3,6,9};
void solve(){
	For(i,1,9) scanf("%s",s[i]+1);
	For(i,1,9) s[i][p[i]]=(s[i][p[i]]=='9'?'1':s[i][p[i]]+1);
	For(i,1,9) printf("%s\n",s[i]+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}