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
#include <assert.h>
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
const int MOD=1e9+7;
#define SZ 1234567
#define S 26
int rot=1,ch[SZ][S],C=1,cw[SZ];
int cu[SZ];
int ml[SZ],fail[SZ],lst=1,cl=0;
void ins(char c,int u)
{
    int x=++C,len=++cl,p=lst;
    lst=x; ml[x]=len; cw[x]=u; cu[x]=cl;
    for(;p&&!ch[p][c];p=fail[p]) ch[p][c]=x;
    if(!p) fail[x]=rot;
    else if(ml[ch[p][c]]==ml[p]+1) fail[x]=ch[p][c];
    else
    {
        int chh=ch[p][c],cm=++C;
        ml[cm]=ml[p]+1; fail[cm]=fail[chh];
        for(int i=0;i<S;i++) ch[cm][i]=ch[chh][i];
        fail[chh]=fail[x]=cm;
        for(;ch[p][c]==chh;p=fail[p]) ch[p][c]=cm;
    }
}
vector<int> oo;
void sep()
{
    int x=++C,len=++cl,p=lst; oo.pb(cl);
    lst=x; ml[x]=len; fail[x]=rot;
}
int n; char buf[SZ];
ll v[SZ],vv[SZ];
int qzh[SZ],od[SZ];
void topo()
{
    for(int i=0;i<SZ;i++) qzh[i]=0;
    for(int i=1;i<=C;i++) qzh[ml[i]]++;
    for(int i=1;i<SZ;i++) qzh[i]+=qzh[i-1];
    for(int i=1;i<=C;i++) od[qzh[ml[i]]--]=i;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",buf);
		for(int j=0;buf[j];++j)
			ins(buf[j]-'a',i);
		sep();
	}
	for(int i=1;i<=n;++i)
		scanf("%lld",v+i);
	for(int i=1;i<=C;++i)
		if(cw[i]) vv[i]=v[cw[i]];
	ll ans=0; topo();
	for(int i=C;i>=1;--i)
	{
		int o=od[i];
		if(!ml[o]) continue;
		//[cu[o]-ml[o]+1,cu[o]]
		int g=upper_bound(oo.begin(),oo.end(),cu[o])-oo.begin();
		int L=ml[o];
		if(g) L=min(L,cu[o]-oo[g-1]);
		if(L>ml[fail[o]])
			ans=max(ans,vv[o]*(ll)L);
		vv[fail[o]]+=vv[o];
		cu[fail[o]]=max(cu[fail[o]],cu[o]);
	}
	printf("%lld\n",ans);
}