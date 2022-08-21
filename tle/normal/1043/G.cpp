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
#define SZ 200005
//#PleaseStopWritingProblems
//copy & paste all your templates and you're done
int n; char s[SZ];
struct seq
{
int u,v,d;
bool chk(int x)
{return (x-u)%d==0&&x>=u&&x<=v;}
int len() {return (u<=v)?((v-u)/d+1):0;}
};
seq operator + (seq a,int x)
{a.u+=x; a.v+=x; return a;}
seq operator - (seq a,int x)
{a.u-=x; a.v-=x; return a;}
seq operator - (int x,seq a)
{return seq{x-a.v,x-a.u,a.d};}
seq operator & (seq a,seq b)
{
	if(a.d==b.d)
	{
		seq w=a;
		w.u=max(w.u,b.u);
		w.v=min(w.v,b.v);
		return w;
	}
	if(b.len()<=3) swap(a,b);
	if(a.len()<=3)
	{
		vector<int> s;
		for(int x=a.u;x<=a.v;x+=a.d)
			if(b.chk(x)) s.pb(x);
		if(s.size()==0) return seq{2,1,1};
		if(s.size()==1) return seq{s[0],s[0],1};
		return seq{s[0],s.back(),
		(s.back()-s[0])/((int)s.size()-1)};
	}
	throw "bu hui";
}
#define U 19
int od[U][SZ];
set<int> ap[U][SZ];
pair<pii,int> t[SZ];
int ys[SZ];
seq fi(pii a,pii b,int k)
{
	if(b.se-b.fi+1!=(1<<k)) throw 0.233;
	int L=a.fi,R=a.se-(b.se-b.fi);
	set<int>&s=ap[k][od[k][b.fi]];
	vector<int> v;
	set<int>::iterator it=s.lower_bound(L);
	while(v.size()<2&&it!=s.end()&&*it<=R)
		v.push_back(*it), ++it;
	it=s.upper_bound(R);
	if(it!=s.begin())
	{
		int x=*(--it);
		if(x>=L&&x!=v.back()) v.pb(x);
	}
	if(v.size()==0) return seq{2,1,1};
	if(v.size()==1) return seq{v[0],v[0],1};
	if(v.size()==2) return seq{v[0],v[1],v[1]-v[0]};
	return seq{v[0],v[2],v[1]-v[0]};
}
seq lps(pii a,pii b,int k)
{
	seq A=fi(b,pii(a.fi,a.fi+(1<<k)-1),k),
	B=fi(a,pii(b.se-(1<<k)+1,b.se),k);
	A=(b.se+1)-A; B=B+((1<<k)-a.fi);
	return A&B;
}
vector<seq> qry(int l,int r)
{
	int k=0;
	while((1<<(k+1))<=r-l+1) ++k;
	vector<seq> t;
	t.pb(lps(pii(l,r),pii(l,r),k));
	for(int s=k;s;--s)
		t.pb(lps(pii(l,l+(1<<s)-1),pii(r-(1<<s)+1,r),s-1));
	return t;
}
#define S 19
int l2[SZ];
struct SA
{
int n,k,sa[SZ],t[SZ],rnk[SZ],qzh[SZ],
tmpsa[SZ],tmpr[SZ],h[SZ],mi[S][SZ]; char s[SZ];
bool same(int a,int b,int p) {return t[a]==t[b]&&t[a+p]==t[b+p];}
void pre(int m=500)
{
	n=strlen(s); s[++n]=0;
	for(int i=0;i<n;i++) rnk[i]=s[i], ++qzh[rnk[i]];
	for(int i=1;i<m;i++) qzh[i]+=qzh[i-1];
	for(int i=n-1;i>=0;i--) sa[--qzh[rnk[i]]]=i;
	for(int j=1;j<=n;j<<=1)
	{
		int cur=-1;
		for(int i=n-j;i<n;i++) tmpsa[++cur]=i;
		for(int i=0;i<n;i++) if(sa[i]>=j) tmpsa[++cur]=sa[i]-j;
		for(int i=0;i<n;i++) tmpr[i]=rnk[tmpsa[i]];
		for(int i=0;i<m;i++) qzh[i]=0;
		for(int i=0;i<n;i++) ++qzh[tmpr[i]];
		for(int i=1;i<m;i++) qzh[i]+=qzh[i-1];
		for(int i=n-1;i>=0;i--) t[i]=rnk[i], sa[--qzh[tmpr[i]]]=tmpsa[i];
		m=0;
		for(int i=0;i<n;i++)
			rnk[sa[i]]=(i>0&&same(sa[i],sa[i-1],j))?m:++m;
		++m;
	}
	for(int i=0;i<n;i++) rnk[sa[i]]=i;
	int p=0;
	for(int i=0;i<n;i++)
	{
		if(p) --p;
		int ls=sa[rnk[i]-1];
		while(s[ls+p]==s[i+p]) p++;
		h[rnk[i]]=p;
	}
	--n;
	for(int i=1;i<=n;i++) sa[i-1]=sa[i];
	for(int i=0;i<n;i++) rnk[sa[i]]=i;
	for(int i=2;i<=n;i++) h[i-1]=h[i];
	h[n]=sa[n]=0;
	for(int i=0;i<n;i++)
		mi[0][i]=h[i];
	for(int j=1;j<S;j++)
		for(int i=0;i+(1<<j)<=n;i++)
			mi[j][i]=min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]);
}
inline int gmin(int a,int b)
{
	int l=l2[b-a+1];
	return min(mi[l][a],mi[l][b-(1<<l)+1]);
}
int lcp(int a,int b)
{
	if(a==b) return n-a;
	if(rnk[a]>rnk[b]) swap(a,b);
	return gmin(rnk[a]+1,rnk[b]);
}
}A,B;
const int ps[2]={999000011,864888601};
ll po[2][SZ],qz[2][SZ];
void build_hash(char*s,int N)
{
	for(int w=0;w<2;++w)
	{
		po[w][0]=1; qz[w][0]=0;
		for(int j=1;j<=N;++j)
			po[w][j]=po[w][j-1]*233LL%ps[w];
		for(int j=1;j<=N;++j)
			qz[w][j]=(qz[w][j-1]*233LL+s[j-1])%ps[w];
	}
}
ll ghash(int l,int r)
{
	ll a=r-l+1;
	for(int w=0;w<2;++w)
	{
		int u=(qz[w][r+1]-qz[w][l]*(ll)po[w][r-l+1])%ps[w];
		if(u<0) u+=ps[w]; a=a*1000000007LL+u;
	}
	return a;
}
void pre()
{
	for(int i=1;i<=n;++i) od[0][i]=s[i];
	for(int j=1;j<U;++j)
	{
		int l=1<<j,u=n-l+1;
		if(u<=0) break;
		for(int i=1;i<=u;++i)
			t[i]=mp(pii(od[j-1][i],od[j-1][i+(1<<(j-1))]),i);
		sort(t+1,t+1+u);
		int x=1;
		for(int i=1;i<=u;++i)
		{
			if(i!=1&&t[i].fi!=t[i-1].fi) ++x;
			od[j][t[i].se]=x;
		}
	}
	for(int j=0;j<U;++j)
		for(int i=1;i<=n-(1<<j)+1;++i)
			ap[j][od[j][i]].insert(i);
}
int si[SZ],ml[SZ],mr[SZ];
ll med[SZ];
bool cov[6666666];
bool np[SZ]; vector<int> yy[SZ];
vector<int> app[26];
int main()
{
	l2[0]=-1;
	for(int i=1;i<SZ;++i)
		l2[i]=l2[i>>1]+1;
	scanf("%d%s",&n,s+1);
	for(int i=0;i<26;++i) app[i].pb(0);
	for(int i=1;i<=n;++i)
		app[s[i]-'a'].pb(i);
	for(int i=0;i<26;++i) app[i].pb(n+1);
	for(int i=2;i<=n;++i) if(!np[i])
		for(int j=i;j<=n;j+=i)
			yy[j].pb(i),np[j]=1;
	for(int i=1;i<=n;++i) ml[i]=mr[i]=2e9;
	for(int i=1;i<=n;++i)
		A.s[i-1]=B.s[n-i]=s[i];
	A.pre(); B.pre(); build_hash(s,n+1); pre();
	for(int i=1;i<=n;++i)
		si[i]=si[i-1]+n/i-1;
	for(int len=1;len+len<=n;++len)
	{
		int l=-1,r=-1;
		for(int i=len-1;i+len<n;i+=len)
		{
			if(i<=r) continue;
			int L=B.lcp(n-i-1,n-i-len-1),R=A.lcp(i,i+len);
			if(L+R-1<len) continue;
			l=i-L+1; r=i+R-1;
			if(cov[si[len-1]+(i+1)/len])
				continue;
			for(int x=len+len;l+x+x-1<=r+len;x+=len)
				cov[si[x-1]+l/x+1]=1;
			for(int t=l;t+len-1<=r;++t)
				ml[t+1]=min(ml[t+1],len),
				mr[t+len*2]=min(mr[t+len*2],len);
		}
	}
	med[n+1]=n+1;
	for(int i=n;i>=1;--i)
		med[i]=min(med[i+1],i+ml[i]*2LL-1);
	int q,l,r;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		if(r-l+1<=26)
		{
			int sb=0,gg=0;
			for(int j=l;j<=r;++j)
				if(sb&(1<<(s[j]-'a'))) gg=1;
				else sb|=1<<(s[j]-'a');
			if(!gg)
			{
				puts("-1");
				continue;
			}
		}
		for(auto j:yy[r-l+1])
		{
			int p=(r-l+1)/j*(j-1);
			if(ghash(l,l+p-1)==ghash(r-p+1,r))
			{
				puts("1");
				goto good;
			}
		}
		if(min(ml[l],mr[r])*2LL<=r-l+1)
		{
			puts("2");
			goto good;
		}
		{
		vector<seq> ps=qry(l,r);
		int ans=2e9;
		for(auto t:ps)
			if(t.u<=t.v) ans=min(ans,t.u);
		if(ans*2LL<=r-l+1)
		{
			puts("2");
			goto good;
		}
		}
		if(med[l]<=r||
		*lower_bound(app[s[l]-'a'].begin(),
		app[s[l]-'a'].end(),l+1)<=r||
		*lower_bound(app[s[r]-'a'].begin(),
		app[s[r]-'a'].end(),l)<r)
		{
			puts("3");
			goto good;
		}
		puts("4");
		good:;
	}
}