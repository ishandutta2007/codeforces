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
int n;
int qry(int x)
{
	cout<<"? "<<x+1<<endl;
	int g; cin>>g;
	return g;
}
void op(int x)
{
	if(x!=-1) ++x;
	cout<<"! "<<x<<endl;
	exit(0);
}
int main()
{
	cin>>n;
	int u=qry(0),v=qry(n/2);
	if(u==v) op(0);
	if((u-v)&1) op(-1);
	int l=0,r=n/2-1,a=(u>v);
	while(r-l>2)
	{
		int s=(l+r+1)>>1;
		u=qry(s); v=qry(s+n/2);
		if(u==v) op(s);
		if((u>v)==a) l=s;
		else r=s;
	}
	for(int s=l;s<=r;++s)
	{
		u=qry(s); v=qry(s+n/2);
		if(u==v) op(s);
	}
}