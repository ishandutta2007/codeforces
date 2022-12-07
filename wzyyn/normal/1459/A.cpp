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
char s[1005],t[1005];
void solve(){
	int n,ss=0;
	scanf("%d%s%s",&n,s+1,t+1);
	For(i,1,n)
		if (s[i]>t[i]) ++ss;
		else if (s[i]<t[i]) --ss;
	if (ss>0) puts("RED");
	else if (ss==0) puts("EQUAL");
	else puts("BLUE");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}