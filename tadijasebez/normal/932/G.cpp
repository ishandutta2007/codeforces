#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
struct EERTREE
{
	int go[N][26],len[N],link[N],dif[N],jump[N],ZERO,IMAG,tsz,sz,at;
	char s[N];
	void init()
	{
		IMAG=++tsz;link[IMAG]=IMAG;dif[IMAG]=-1;jump[IMAG]=IMAG;len[IMAG]=-1;
		ZERO=++tsz;link[ZERO]=IMAG;dif[ZERO]=-1;jump[ZERO]=IMAG;len[ZERO]=0;
		at=ZERO;
	}
	EERTREE(){ init();}
	void Grow(char c)
	{
		s[++sz]=c;
		while(s[sz]!=s[sz-len[at]-1]) at=link[at];
		if(!go[at][c-'a'])
		{
			int to=++tsz;len[to]=len[at]+2;link[to]=link[at];
			while(s[sz]!=s[sz-len[link[to]]-1]) link[to]=link[link[to]];
			if(at==IMAG) link[to]=ZERO;
			else link[to]=go[link[to]][c-'a'];
			dif[to]=len[to]-len[link[to]];
			if(dif[to]==dif[link[to]]) jump[to]=jump[link[to]];
			else jump[to]=link[to];
			go[at][c-'a']=to;
		}
		at=go[at][c-'a'];
	}
} Tree;
char s[N];
const int mod=1e9+7;
int dp[N],tmp[N];
void inc(int &a, int b){ a+=b;if(a>=mod) a-=mod;}
int main()
{
	int n,i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	dp[0]=1;
	int l=1,r=n;
	for(i=1;i<=n;i++)
	{
		if(i&1) Tree.Grow(s[l++]);
		else Tree.Grow(s[r--]);
		for(j=Tree.at;j>2;j=Tree.jump[j])
		{
			tmp[j]=0;
                  inc(tmp[j],dp[i-Tree.len[Tree.jump[j]]-Tree.dif[j]]);
                  if(Tree.dif[j]==Tree.dif[Tree.link[j]]) inc(tmp[j],tmp[Tree.link[j]]);
                  if(!(i&1)) inc(dp[i],tmp[j]);
		}
	}
	printf("%i\n",dp[n]);
	return 0;
}