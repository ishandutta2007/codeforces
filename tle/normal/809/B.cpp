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
int k,n;
set<int> g;
int nr(int x)
{
	auto p=g.lower_bound(x);
	int ans=1e9;
	if(p!=g.end()) ans=min(ans,abs(*p-x));
	if(p!=g.begin()) ans=min(ans,abs(*(--p)-x));
	cout<<"qry:"<<x<<" "<<ans<<"\n";
	return ans;
}
int qry(int p,int q)
{
	cout<<"1 "<<p<<" "<<q<<endl;
	string s; cin>>s;
	if(s=="TAK") return -1;
	return 1;
}
vector<int> ans;
void fz(int l,int r)
{
	if(l>r) return;
	if(l==r) throw l;
	int m=(l+r)>>1;
	if(qry(m,m+1)<=0)
		fz(l,m);
	else fz(m+1,r);
}
int main()
{
	cin>>n>>k;
	/*
	for(int i=1,r;i<=k;++i)
		cin>>r,g.insert(r);*/
	vector<int> v;
	try {fz(1,n);}
	catch(int p) {v.pb(p);}
	try {fz(1,v[0]-1);}
	catch(int p) {
	if(qry(p,v[0])<=0) v.pb(p);}
	if(v.size()<2)
	{
	try {fz(v[0]+1,n);}
	catch(int p) {
	if(qry(p,v[0])<=0) v.pb(p);}
	}
	cout<<"2 "<<v[0]<<" "<<v[1]<<endl;
}