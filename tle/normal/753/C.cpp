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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
template<class T1,class T2>
ostream& operator << (ostream& out,pair<T1,T2> p)
{out<<p.fi<<","<<p.se; return out;}
map<string,pii> rs;
pii reply(string s)
{
	if(rs.count(s)) return rs[s];
	cout<<s<<"\n";
	fflush(stdout);
	int a,b;
	cin>>a>>b;
	if(a==4&&b==0) exit(0);
	return rs[s]=pii(a,b);
}
pii gs(string a,string g)
{
	int a1=0,a2=0;
	bool cc[10]={};
	for(int i=0;i<4;i++)
	a1+=a[i]==g[i], cc[g[i]-'0']=1;
	for(int i=0;i<4;i++)
	{
		if(cc[a[i]-'0']&&a[i]!=g[i])
			++a2;
	}
	return pii(a1,a2);
}
vector<string> vec;
map<pii,int> cnt;
int main()
{
	//cout<<gs("0427","0724")<<"\n";
	//cout<<gs("0123","0330")<<"\n";
	srand(666623333);
	#define fora(x) for(char x='0';x<='9';x++)
	fora(a) fora(b) fora(c) fora(d)
	{
		if(a==b||a==c||a==d||b==c||b==d||c==d) continue;
		string s; s.pb(a); s.pb(b);
		s.pb(c); s.pb(d); vec.pb(s);
	}
	random_shuffle(vec.begin(),vec.end());
	while(1)
	{
		string s;
		if(vec.size()<=1000)
		{
		random_shuffle(vec.begin(),vec.end());
		ll mxx=1e18;
		for(int i=0;i<vec.size();i++)
		{
			cnt.clear();
			for(int j=0;j<vec.size();j++)
			++cnt[gs(vec[i],vec[j])];
			ll rp=0;
			for(int j=0;j<vec.size();j++)
			rp+=cnt[gs(vec[i],vec[j])];
			if(rp<mxx) mxx=rp, s=vec[i];
		}
		}
		else s=vec[rand()%vec.size()];
		pii rp=reply(s);
		vector<string> nx;
		for(int j=0;j<vec.size();j++)
		{
			if(gs(vec[j],s)!=rp) continue;
			nx.pb(vec[j]);
		}
		vec=nx;
	}
}