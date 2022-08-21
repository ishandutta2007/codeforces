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
int n;
#define S 18
struct str
{
string q,h; bool co;
bool f[(1<<S)+1];
};
int qz[S+5];
int gans(str& s)
{
	for(int i=S-1;i>=1;--i)
	{
		bool gg=0;
		for(int j=0;j<(1<<i)&&!gg;++j)
			if(!s.f[qz[i]+j]) gg=1;
		if(!gg) return i;
	}
	return 0;
}
void work(str&s,string&a,string&b)
{
	string cm=a+b;
	for(int i=0;i<a.size();++i)
	{
		int cl=0,r=0;
		for(int j=i;j<cm.size();++j)
		{
			++cl; r=r*2+cm[j]-48; if(cl>=S) break;
			if(j>=a.size()) s.f[qz[cl]+r]=1;
		}
	}
}
void work(str&s,string&a)
{
	for(int i=0;i<a.size();++i)
	{
		int cl=0,r=0;
		for(int j=i;j<a.size();++j)
		{
			++cl; r=r*2+a[j]-48;
			if(cl>=S) break; s.f[qz[cl]+r]=1;
		}
	}
}
str operator + (str& a,str& b)
{
	str nx;
	memset(nx.f,0,sizeof nx.f);
	if(!(a.co||b.co))
	{
		nx.co=0;
		string tmp=a.q+b.q;
		if(tmp.size()>=S+S)
		{
			nx.co=1; nx.q=tmp.substr(0,S);
			nx.h=tmp.substr(tmp.size()-S,S);
		}
		else nx.q=nx.h=tmp;
	}
	else
	{
		nx.co=1;
		if(!a.co)
		{
			nx.q=a.q+b.q;
			nx.h=b.h;
		}
		else if(!b.co)
		{
			nx.h=a.h+b.h;
			nx.q=a.q;
		}
		else
		{
			nx.h=b.h; nx.q=a.q;
		}
		if(nx.q.size()>S)
			nx.q=nx.q.substr(0,S);
		if(nx.h.size()>S)
			nx.h=nx.h.substr(nx.h.size()-S,S);
	}
	for(int j=0;j<=(1<<S);++j)
		nx.f[j]=a.f[j]|b.f[j];
	work(nx,a.h,b.q);
	return nx;
}
str ss[205];
int main()
{
	for(int i=2;i<=S;++i)
		qz[i]=qz[i-1]+(1<<(i-1));
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>ss[i].q,ss[i].h=ss[i].q,
		ss[i].co=0,work(ss[i],ss[i].q);
	int m; cin>>m;
	for(int i=1;i<=m;++i)
	{
		int a,b;
		cin>>a>>b;
		ss[n+i]=ss[a]+ss[b];
		cout<<gans(ss[n+i])<<"\n";
	}
}