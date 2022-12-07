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
const int N=3000005;
char s[N];
int n,k;
void solve(){
	scanf("%d%d%s",&n,&k,s+1);
	For(i,k+1,n)
		if (s[i-k]!='?')
			if (s[i]=='?') s[i]=s[i-k];
			else if (s[i]!=s[i-k]) return puts("NO"),void(0);
	Rep(i,n,k+1)
		if (s[i]!='?')
			if (s[i-k]=='?') s[i-k]=s[i];
			else if (s[i]!=s[i-k]) return puts("NO"),void(0);
	int s0=0,s1=0;
	For(i,1,k)
		if (s[i]=='0') ++s0;
		else if (s[i]=='1') ++s1;
	puts(2*max(s0,s1)<=k?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}