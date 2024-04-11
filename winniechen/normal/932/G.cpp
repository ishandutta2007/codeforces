#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1000005
#define ll long long
#define mod 1000000007
char s[N],t[N];int f[N],g[N],n;
int ch[N][26],len[N],fa[N],cnt,lst,anc[N],diff[N];
void init(){cnt=1;len[1]=-1,fa[0]=fa[1]=anc[0]=1;}
void extend(int x,int n,char *s)
{
	int p=lst,np,nq;
	while(s[n]!=s[n-len[p]-1])p=fa[p];
	if(!ch[p][x])
	{
		len[np=++cnt]=len[p]+2;nq=fa[p];
		while(s[n]!=s[n-len[nq]-1])nq=fa[nq];nq=ch[nq][x];fa[np]=nq;ch[p][x]=np;
		diff[np]=len[np]-len[nq];anc[np]=(diff[np]==diff[nq]?anc[nq]:nq);
	}lst=ch[p][x];
}
int main()
{
	scanf("%s",t+1);n=strlen(t+1);init();if(n&1)return puts("0"),0;
	for(int i=1,l=1,r=n;i<=n;i++)if(i&1)s[i]=t[l++];else s[i]=t[r--];g[0]=1;
	for(int i=1;i<=n;i++)
	{
		extend(s[i]-'a',i,s);
		for(int p=lst;p;p=anc[p])
		{
			f[p]=g[i-len[anc[p]]-diff[p]];
			if(anc[p]!=fa[p])(f[p]+=f[fa[p]])%=mod;
			if(!(i&1))(g[i]+=f[p])%=mod;
		}
	}printf("%d\n",g[n]);
}