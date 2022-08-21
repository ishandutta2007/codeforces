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
#define SZ
vector<pii> sol[1<<9];
vector<pii> gs(int t,int x)
{
	static int fm[1<<19];
	static pii fs[1<<19];
	queue<int> q;
	vector<pair<pii,int> > sb;
	for(int i=0;i<(1<<t);++i) fm[i]=-1;
	for(int i=0;i<t;++i)
		for(int k=1;i+k+k<t;++k)
			sb.pb(mp(pii(i,k),(1<<i)^(
			1<<(i+k))^(1<<(i+k+k))));
	q.push(x); fm[x]=-2;
	while(!q.empty())
	{
		int w=q.front(); q.pop();
		for(auto p:sb)
		{
			if(fm[w^p.se]!=-1) continue;
			fm[w^p.se]=w;
			fs[w^p.se]=p.fi;
			q.push(w^p.se);
		}
	}
	if(fm[0]==-1) throw "GG";
	int tt=0;
	vector<pii> vp;
	while(tt!=x)
		vp.pb(fs[tt]),tt=fm[tt];
	return vp;
}
int n;
int a[233333];
int main()
{
	int mx=0;
	for(int i=0;i<(1<<9);++i)
	{
		vector<pii> sb;
		for(int j=0;j<12;++j)
			for(int k=1;j+k+k<12;++k)
				sb.pb(pii(j,k));
		random_shuffle(sb.begin(),sb.end());
		int u=sb.size();
		for(int x=-1;x<u;++x)
			for(int y=x;y<u;++y)
				for(int z=y;z<u;++z)
				{
					vector<pii> p;
					if(x>=0) p.pb(sb[x]);
					if(y>=0) p.pb(sb[y]);
					if(z>=0) p.pb(sb[z]);
					int w=i;
					for(auto h:p)
					{
						int a=h.fi,b=h.se;
						if(a>=0&&a<9) w^=1<<a;
						if(a+b>=0&&a+b<9)
							w^=1<<(a+b);
						if(a+b+b>=0&&a+b+b<9)
							w^=1<<(a+b+b);
					}
					if(!w)
					{
						sol[i]=p;
						goto GG; 
					}
				}
		cout<<"NMSL.\n"; //ru ya sui he
		GG:;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	vector<pair<pii,int> > vp;
	int l=1;
	while(n-l+1>=18)
	{
		int h=0;
		for(int p=0;p<9;++p)
			if(a[l+p]) h^=1<<p;
		vector<pii> w=sol[h];
		for(auto& t:w)
		{
			t.fi+=l;
			vp.pb(mp(mp(t.fi,t.fi+t.se),t.fi+t.se+t.se));
			a[t.fi]^=1;
			a[t.fi+t.se]^=1;
			a[t.fi+t.se+t.se]^=1;
		}
		l+=9;
	}
	try
	{
		int g=0;
		for(int i=l;i<=n;++i)
			if(a[i]) g^=1<<(i-l);
		vector<pii> w=gs(n-l+1,g);
		for(auto& t:w)
		{
			t.fi+=l;
			vp.pb(mp(mp(t.fi,t.fi+t.se),t.fi+t.se+t.se));
			a[t.fi]^=1;
			a[t.fi+t.se]^=1;
			a[t.fi+t.se+t.se]^=1;
		}
	}
	catch(...)
	{
		puts("NO");
		return 0;
	}
	for(int i=0;i<=n+1;++i)
		if(a[i]) throw "GG";
	puts("YES");
	printf("%d\n",int(vp.size()));
	for(auto t:vp)
		printf("%d %d %d\n",t.fi.fi,t.fi.se,t.se);
}