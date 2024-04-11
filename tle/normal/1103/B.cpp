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
char qry(ll a,ll b)
{
	cout<<"? "<<a<<" "<<b<<endl;
	string g; cin>>g;
	if(g=="e") exit(0);
	return g[0];
}
int main()
{
	string u;
	while(1)
	{
	cin>>u;
	if(u=="end") break;
	if(u=="mistake") exit(0);
	ll u=1;
	//ta>t
	while(u<1e9)
	{
		if(qry(u+u,u)=='y') break;
		u<<=1;
	}
	if(u>1e9)
	{
		cout<<"! "<<1<<endl;
		continue;
	}
	//a in [u+1,u+u]
	//cout<<u+1<<"~"<<u+u<<"\n";
	//a=u+g
	//  u-t<u+u
	//=>u-t<u-g
	ll L=1,R=u;
	while(L<R)
	{
		ll t=(L+R+1)>>1;
		//g<t
		if(qry(u-t,u+u)=='y') R=t-1; else L=t;
	}
	cout<<"! "<<u+L<<endl;
	}
}