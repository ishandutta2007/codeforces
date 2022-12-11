#include<bits/stdc++.h>
using namespace std;
int n,m;
const int max_n=1e5+5;
const int max_m=1e5+5;
char s[max_n],t[max_m];
int pi[max_m],f[max_n],g[max_n];
inline bool check(int p)
{
	if(p<m)
		return false;
	for(int j=0;j<m;++j)
	{
		if(s[p-j]!='?'&&s[p-j]!=t[m-j])
			return false;
	}
	return true;
}
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	pi[1]=0;
	for(int i=2;i<=m;++i)
	{
		int j=pi[i-1];
		while(j>0&&t[i]!=t[j+1])
			j=pi[j];
		j+=(t[i]==t[j+1]);
		pi[i]=j;
	}
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1];
		if(check(i))
		{
			g[i]=f[i-m]+1;
			for(int k=pi[m];k>0;k=pi[k])
				g[i]=max(g[i],g[i-(m-k)]+1);
			f[i]=max(f[i],g[i]);
		}
	}
	printf("%d\n",f[n]);
	return 0;
}