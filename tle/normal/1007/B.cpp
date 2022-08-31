#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 233333
ll ys[SZ];
vector<int> x1[233333],x2[233333]; int n1=0,n2=0;
int main()
{
	int w[3];
	for(w[0]=1;w[0]<8;++w[0])
		for(w[1]=1;w[1]<8;++w[1])
			for(w[2]=1;w[2]<8;++w[2])
			{
				bool ok=0;
				int s[3]={0,1,2};
				do
				{
					bool co=1;
					for(int p=0;p<3;++p)
						co&=(w[s[p]]>>p)&1;
					ok|=co;
					if(ok) break;
				}while(next_permutation(s,s+3));
				if(ok) x1[++n1]={w[0],w[1],w[2]};
			}
	for(w[1]=1;w[1]<8;++w[1])
		for(w[2]=1;w[2]<8;++w[2])
		{
			bool ok=0;
			int s[3]={1,1,2};
			do
			{
				bool co=1;
				for(int p=0;p<3;++p)
					co&=(w[s[p]]>>p)&1;
				ok|=co;
			}while(next_permutation(s,s+3));
			if(ok) x2[++n2]={w[1],w[2]};
		}
	for(int i=1;i<SZ;++i)
		for(int j=i;j<SZ;j+=i) ++ys[j];
	int T; ll t[3],gg[8],hh[8];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&t[0],&t[1],&t[2]);
		for(int i=0;i<8;++i)
		{
			ll g=0;
			for(int j=0;j<3;++j) if(i&(1<<j)) g=__gcd(g,t[j]);
			gg[i]=ys[g];
		}
		for(int i=1;i<8;++i)
		{
			hh[i]=0;
			for(int j=0;j<8;++j)
				if((j&i)==i)
				{
					if(__builtin_popcount(j^i)&1)
						hh[i]-=gg[j];
					else hh[i]+=gg[j];
				}
		}
		ll aa[3]={0,0,0};
		for(int i=1;i<=n1;++i)
		{
			auto&w=x1[i];
			aa[0]+=hh[w[0]]*hh[w[1]]*hh[w[2]];
		}
		for(int i=1;i<=n2;++i)
		{
			auto&w=x2[i];
			aa[1]+=hh[w[0]]*hh[w[1]];
		}
		aa[2]=hh[7];
		printf("%lld\n",(aa[0]+aa[1]*3+aa[2]*2)/6);
	}
}