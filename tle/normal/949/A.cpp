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
char s[SZ];
vector<int> rs[SZ]; int rn=0;
vector<int> o,l;
int ma[SZ];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1),v=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0')
		{
			if(l.size())
			{
				int x=l.back();
				l.pop_back();
				rs[x].pb(i);
				o.push_back(x);
			}
			else
			{
				++rn; rs[rn].pb(i); o.pb(rn);
			}
		}
		else
		{
			if(!o.size())
			{
				puts("-1");
				return 0;
			}
			int x=o.back();
			o.pop_back();
			rs[x].pb(i);
			l.push_back(x);
		}
	}
	if(l.size())
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",int(o.size()));
	for(auto w:o)
	{
		printf("%d ",(int)rs[w].size());
		for(auto x:rs[w]) printf("%d ",x);
		puts("");
	}
}