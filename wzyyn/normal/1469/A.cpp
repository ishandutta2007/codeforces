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

char s[105];
int n;
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n%2==1) puts("NO");
	else if (s[1]==')'||s[n]=='(') puts("NO");
	else puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}