#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int mul(int x, int y){ return (ll)x*y%mod;}
void ckmul(int &x, int y){ x=mul(x,y);}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
void ckadd(int &x, int y){ x=add(x,y);}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
void cksub(int &x, int y){ x=sub(x,y);}
const int N=18;
const int M=1<<N;
int cnt[M];
int go[N],ed[N],n;
bool ok[M];
int main()
{
	int m;
	scanf("%i %i",&n,&m);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%i %i",&u,&v);
		u--;v--;
		go[u]|=1<<v;
		ed[u]|=1<<v;
		ed[v]|=1<<u;
	}
	for(int mask=0;mask<1<<n;mask++)
	{
		int o=0;
		for(int i=0;i<n;i++) if(mask>>i&1)
			o|=ed[i];
		if(o&mask) ok[mask]=0;
		else ok[mask]=1;
	}
	cnt[0]=1;
    for(int mask=1;mask<1<<n;mask++)
	{
		for(int sub=mask;sub;sub=(sub-1)&mask) if(ok[sub])
		{
			if(__builtin_popcount(sub)&1) ckadd(cnt[mask],cnt[mask^sub]);
			else cksub(cnt[mask],cnt[mask^sub]);
		}
	}
	printf("%i\n",mul(cnt[(1<<n)-1],mul(m,(mod+1)/2)));
	return 0;
}