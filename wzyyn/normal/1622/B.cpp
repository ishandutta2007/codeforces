#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n;
char s[N];
int p[N],loc[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]),loc[p[i]]=i;
	scanf("%s",s+1);
	long long ans=0;
	int v=0;
	for (int i=1;i<=n;i++)
		if (s[loc[i]]=='0')
			p[loc[i]]=++v;
	for (int i=1;i<=n;i++)
		if (s[loc[i]]=='1')
			p[loc[i]]=++v;
	for (int i=1;i<=n;i++)
		printf("%d%c",p[i],i==n?'\n':' ');
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}