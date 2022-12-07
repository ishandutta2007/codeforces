#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;


char s[300005];
int n;
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int p=-1;
	for (int i=1;i<=n;i++)
		if (s[i]!='a'){
			if (i<(n+2)-i) p=(n+2)-i;
			else p=(n+1)-i;
		}
	if (p==-1) puts("NO");
	else{
		puts("YES");
		for (int i=1;i<p;i++)
			putchar(s[i]);
		putchar('a');
		for (int i=p;i<=n;i++)
			putchar(s[i]);
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}