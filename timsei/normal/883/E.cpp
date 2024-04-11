#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
int n,m;
char s[100],t[100];
bitset<500> ans,g,hg;
int main(){
	scanf("%d%s",&n,s+1);
	for (int i='a';i<='z';++i) ans[i]=1;
	for (int i=1;i<=n;++i) if (s[i]!='*') hg[s[i]]=1;
	scanf("%d",&m);
	for (int i=1;i<=m;++i){
		scanf("%s",t+1);
		for (int j=1;j<=n;++j) if (s[j]!='*'&&s[j]!=t[j]) goto OvO;
		for (int j=1;j<=n;++j) if (s[j]=='*'&&hg[t[j]]) goto OvO;
		g=0;
		for (int j=1;j<=n;++j) if (s[j]=='*') g[t[j]]=1;
		ans=ans&g;
		OvO:;
	}
	printf("%d\n",ans.count());
	return 0;
}