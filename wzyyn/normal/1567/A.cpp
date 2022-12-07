#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;

int n;
char s[105];
void solve(){
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++)
		if (s[i]=='U') s[i]='D'; 
		else if (s[i]=='D') s[i]='U';
	printf("%s\n",s+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}