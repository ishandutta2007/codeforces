#include<bits/stdc++.h>
using namespace std;
int n,q,mod;
inline void add(int &a,int b)
{
	a+=b,a-=a>=mod?mod:0;
}
inline void sub(int &a,int b)
{
	a-=b,a+=a<0?mod:0;
}
const int max_n=3e5+5;
int C[max_n],D[max_n],F[max_n],cnt0;
inline void modify(int pos,int v)
{
	if(pos<=n)
	{
		cnt0-=!D[pos];
		add(D[pos],v);
		cnt0+=!D[pos];
	}
}
int main()
{
	scanf("%d%d%d",&n,&q,&mod);
	for(int i=1;i<=n;++i)
		scanf("%d",C+i);
	for(int i=1;i<=n;++i)
	{
		int B;
		scanf("%d",&B);
		sub(C[i],B);
	}
	D[1]=C[1],D[2]=C[2];
	sub(D[2],C[1]);
	for(int i=3;i<=n;++i)
	{
		D[i]=C[i];
		sub(D[i],C[i-1]);
		sub(D[i],C[i-2]);
	}
	for(int i=1;i<=n;++i)
		cnt0+=!D[i];
	F[1]=F[2]=mod>1?1:0;
	for(int i=3;i<=n;++i)
	{
		F[i]=F[i-1];
		add(F[i],F[i-2]);
	}
	while(q--)
	{
		char c[4];
		int l,r;
		scanf("%s%d%d",c,&l,&r);
		if(c[0]=='A')
		{
			modify(l,1);
			modify(r+1,mod-F[r-l+2]);
			modify(r+2,mod-F[r-l+1]);
		}
		else
		{
			modify(l,mod-1);
			modify(r+1,F[r-l+2]);
			modify(r+2,F[r-l+1]);
		}
		puts(cnt0==n?"YES":"NO");
	}
	return 0;
}