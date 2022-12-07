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
char s[200005];
void solve(){
	int s0=0,s1=0,s2=0;
	scanf("%s",s+1);
	int n=strlen(s+1);
	For(i,1,n)
		if (s[i]=='R') s0++;
		else if (s[i]=='S') s1++;
		else s2++;
	int v=max(max(s0,s1),s2);
	For(i,1,n)
		if (s0==v) putchar('P');
		else if (s1==v) putchar('R');
		else putchar('S');
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}