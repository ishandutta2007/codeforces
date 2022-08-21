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
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int n,k;
Edgc
ll rt[SZ],down[SZ];
typedef pair<ll,ll> pll;
void dp(int x,int f=0)
{
	vector<pll> vu;
    for es(x,e)
    {
        int b=vb[e];
		if(b==f) continue;
		dp(b,x); vu.pb(pll(rt[b]+vc[e],down[b]+vc[e]));
    }
    sort(vu.begin(),vu.end());
    for(int i=max(int(vu.size())-(k-1),0);i<vu.size();i++)
    	rt[x]+=vu[i].fi;
    ll ext=0; down[x]=max(down[x],rt[x]);
    if(int(vu.size())-k>=0) ext=vu[vu.size()-k].fi;
    for(int i=max(int(vu.size())-(k-1),0);i<vu.size();i++)
    	down[x]=max(down[x],rt[x]-vu[i].fi+ext+vu[i].se);
    for(int i=0;i<max(int(vu.size())-(k-1),0);i++)
    	down[x]=max(down[x],vu[i].se+rt[x]);
}
int ea[SZ],eb[SZ],ec[SZ];
int main()
{
	down[0]=-1;
	scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        ++x,++y; adde(x,y,z);
        ea[i]=x;eb[i]=y;ec[i]=z;
    }
    dp(1);
	cout<<max(down[1],rt[1])<<"\n";
}