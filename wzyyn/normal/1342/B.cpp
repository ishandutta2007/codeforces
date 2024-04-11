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
	char s[105];
	scanf("%s",s+1);
	bool fl=1;
	int n=strlen(s+1);
	For(i,1,n) if (s[i]!=s[1]) fl=0;
	if (fl) For(i,1,n*2) putchar(s[1]);
	else For(i,1,n*2) putchar('0'+(i&1));
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}