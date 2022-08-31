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
string cu;
void nx()
{
	getline(cin,cu);
}
int cn[10],pos[10];
int R=10,C=10;
int cnt=0;
//#define SIM
void go(vector<int> v)
{
	cout<<"next";
	for(auto r:v) cout<<" "<<r,++cn[r];
	cout<<endl;
	#ifdef SIM
	map<int,vector<int> > uu;
	for(auto i:v)
	{
		++pos[i];
		if(pos[i]>=R+C) pos[i]-=C;
	}
	for(int i=0;i<10;++i)
		uu[pos[i]].pb(i);
	string s="SIM:";
	++cnt;
	for(auto r:uu)
	{
		s+=" ";
		for(auto u:r.se)
			s+=char(u+'0');
	}
	cu=s;
	cerr<<s<<"\n";
	#else
	nx();
	#endif
}
void done()
{
	#ifdef SIM
	for(int i=0;i<10;++i)
		if(pos[i]!=R) throw "GG";
	#endif
}
int main()
{
	for(int i=0;i<10;++i) pos[i]=0;
	vector<int> v;
	while(cu.find("01")==string::npos)
		go({0,1}),go({0});
	while(cu.find("0123")==string::npos)
		go({0,1,2,3,4,5,6,7,8,9});
//	for(int i=0;i<10;++i)
//		if(cn[i]<t||(cn[i]-t)%c) throw "GG";
	cout<<"done"<<endl;
	done();
	#ifdef SIM
	cerr<<cnt-3*(R+C)<<" OK\n";
	#endif
}