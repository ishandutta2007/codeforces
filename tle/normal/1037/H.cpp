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
#define SZ 1200000
#define rank rank_
int n,sa[SZ],t[SZ],rank[SZ],qzh[SZ],tmpsa[SZ],tmpr[SZ],h[SZ];
char s[SZ];
bool same(int a,int b,int p) {return t[a]==t[b]&&t[a+p]==t[b+p];}
void getsa(int m=500)
{
    s[++n]=0;
    for(int i=0;i<n;i++) rank[i]=s[i], ++qzh[rank[i]];
    for(int i=1;i<m;i++) qzh[i]+=qzh[i-1];
    for(int i=n-1;i>=0;i--) sa[--qzh[rank[i]]]=i;
    for(int j=1;j<=n;j<<=1)
    {
        int cur=-1;
        for(int i=n-j;i<n;i++) tmpsa[++cur]=i;
        for(int i=0;i<n;i++) if(sa[i]>=j) tmpsa[++cur]=sa[i]-j;
        for(int i=0;i<n;i++) tmpr[i]=rank[tmpsa[i]];
        for(int i=0;i<m;i++) qzh[i]=0;
        for(int i=0;i<n;i++) ++qzh[tmpr[i]];
        for(int i=1;i<m;i++) qzh[i]+=qzh[i-1];
        for(int i=n-1;i>=0;i--) t[i]=rank[i], sa[--qzh[tmpr[i]]]=tmpsa[i];
        m=0;
        for(int i=0;i<n;i++)
            rank[sa[i]]=(i>0&&same(sa[i],sa[i-1],j))?m:++m;
        ++m;
    }
    for(int i=0;i<n;i++) rank[sa[i]]=i;
    int p=0;
    for(int i=0;i<n;i++)
    {
        if(p) --p;
        if(!rank[i]) continue;
        int ls=sa[rank[i]-1];
        while(s[ls+p]==s[i+p]) p++;
        h[rank[i]]=p;
    }
    --n;
    for(int i=1;i<=n;i++) sa[i-1]=sa[i];
    for(int i=0;i<n;i++) rank[sa[i]]=i;
    for(int i=2;i<=n;i++) h[i-1]=h[i];
    h[n]=sa[n]=0;
}
char S[233333];
int sn,q,ql[233333],qr[233333],ps[SZ],al[SZ];
int v1[SZ],v2[SZ];
vector<int> qs[SZ];
const int M=131072;
struct Seg
{
int mi[SZ];
void insert(int g)
{
	int v=rank[g]; ++g; g+=M;
	for(;g;g>>=1) mi[g]=min(mi[g],v);
}
void clr(int g)
{
	++g; g+=M;
	for(;g;g>>=1) mi[g]=2e9;
}
int qry(int l,int r)
{
	if(l>r) return 2e9;
	++l, ++r;
	int ans=2e9;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) ans=min(ans,mi[l^1]);
		if(r&1) ans=min(ans,mi[r^1]);
	}
	return ans;
}
Seg() {memset(mi,127/3,sizeof mi);}
}L,R;
void fz(int l,int r)
{
	if(l==r) return;
	int m=(l+r)>>1;
	fz(l,m); fz(m+1,r);
	v1[m+1]=v2[m]=2e9;
	for(int i=m+1;i<=r;++i)
		v2[i]=min(v2[i-1],h[i]);
	for(int i=m;i>=l;--i)
		v1[i]=min(v1[i+1],h[i+1]);
	for(int i=m+1;i<=r;++i)
		if(sa[i]<sn) L.insert(sa[i]);
	vector<pii> so,qq;
	for(int i=m+1;i<=r;++i)
		if(sa[i]<sn) so.pb(mp(v2[i]+sa[i],sa[i]));
	for(int i=m;i>=l;--i)
	{
		//v1[i]<rq+1-u,u>=lq,min u
		for(auto q:qs[i])
		{
			qq.pb(mp(qr[q]+1,q));
			int L=ql[q],R=qr[q]-v1[i];
			if(L>R) continue;
			al[q]=min(al[q],::L.qry(L,R));
		}
	}
	sort(so.begin(),so.end());
	sort(qq.begin(),qq.end());
	int t=0;
	for(auto q_:qq)
	{
		int q=q_.se;
		while(t<so.size()&&so[t].fi<q_.fi)
			R.insert(so[t++].se);
		al[q]=min(al[q],R.qry(ql[q],sn-1));
	}
	for(int i=m+1;i<=r;++i)
		if(sa[i]<sn) L.clr(sa[i]),R.clr(sa[i]);
}
string ts[SZ],os;
int main()
{
	scanf("%s%d",S,&q); os=S; os.pb('0');
	for(int i=0;S[i];++i) s[n++]=S[i];
	sn=n; s[n++]='0';
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d%s",ql+i,qr+i,S);
		--ql[i]; --qr[i];
		ps[i]=n; for(int i=0;S[i];++i) s[n++]=S[i];
		s[n++]='0'; al[i]=2e9;
		ts[i]=S; ts[i].pb('0');
	}
	getsa();
	for(int i=1;i<=q;++i)
		qs[rank[ps[i]]].pb(i);
	fz(0,n-1);
	for(int i=1;i<=q;++i)
	{
		if(al[i]>=n)
		{
			puts("-1");
			continue;
		}
		for(int j=sa[al[i]];;++j)
		{
			putchar(os[j]);
			if(os[j]!=ts[i][j-sa[al[i]]]) break;
		}
		puts("");
	}
}