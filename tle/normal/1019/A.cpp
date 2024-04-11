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
#define SZ 666666
int n,m,cr[SZ],ts[SZ]; pii g[SZ];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>g[i].se>>g[i].fi;
	sort(g+1,g+1+n);
	reverse(g+1,g+1+n);
	ll ans=8e18;
	for(int j=0;j<=n;++j)
	{
		for(int t=1;t<=m;++t) cr[t]=0;
		int aa=0,tn=0; ll co=0;
		for(int i=1;i<=n;++i)
		{
			if(g[i].se==1) ++aa;
			else
			{
				++cr[g[i].se];
				if(cr[g[i].se]>j)
					--cr[g[i].se],++aa,co+=g[i].fi;
				else ts[++tn]=g[i].fi;
			}
		}
		while(aa<=j&&tn) co+=ts[tn--],++aa;
		if(aa<=j) continue;
		ans=min(ans,co);
	}
	cout<<ans<<"\n";
}