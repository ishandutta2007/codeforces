%:pragma GCC optimize(4)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int son[700001][4];
int n,m,k;
char s[600001];
int sz;
int root;
int zhuan='a'-1;
bool dance[700001];
bool have[700001];
bool hack(int ll,int rr,int it)
{
	int p=it;
	for(int i=ll;i<=rr;i++)
	{
		if(son[p][s[i]-zhuan])
		p=son[p][s[i]-zhuan];else return 0;
	}
	if(dance[p]) return 1;
	return 0;
}
bool check()
{
	int len=strlen(s+1);
	//RE 
	int p=root;
	if(!have[len]) return 0;
	for(int i=1;i<=len;i++)
	{
		for(int kk=1;kk<=3;kk++)
		{
			if(kk!=s[i]-zhuan&&son[p][kk])
			if(hack(i+1,len,son[p][kk])||(i==len&&dance[son[p][kk]]))
			return 1;
		}
		if(son[p][s[i]-zhuan])p=son[p][s[i]-zhuan];else return 0;
	}
	return 0;
}
int main()
{
	cin>>n>>m;
	root=++sz;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		have[len]=1;
		int p=root;
		for(int j=1;j<=len;j++)
		{
			if(!son[p][s[j]-zhuan]) son[p][s[j]-zhuan]=++sz;
			p=son[p][s[j]-zhuan];
		}
		dance[p]=1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s+1);
		if(check())
		{
			puts("YES");
		}
		else puts("NO");
	}
}