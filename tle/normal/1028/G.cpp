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
const int n=10000;
ll qm[6][n+2];
void ask(int i,ll b)
{
	int j=min(b,(ll)n);
	vector<ll> v;
	ll r=qm[i-1][j];
	for(int s=1;s<=j;++s)
	{
		v.pb(r+b); ++r;
		r+=qm[i-1][min(r+j,(ll)n)];
		if(r>(ll)2e18) break;
	}
	printf("%d\n",int(v.size()));
	for(auto t:v) printf("%lld ",t);
	cout<<endl;
	int t; cin>>t;
	if(t==-1) exit(0);
	if(t==0) ask(i-1,b);
	r=qm[i-1][j];
	for(int s=1;s<=j;++s)
	{
		++r; --t;
		if(!t) ask(i-1,r+b);
		r+=qm[i-1][min(r+j,(ll)n)];
	}
}
int main()
{
	for(int i=1;i<=4;++i)
	{
		for(int j=1;j<=n;++j)
		{
			ll r=qm[i-1][j];
			for(int s=1;s<=j;++s)
			{
				++r,r+=qm[i-1][min(r+j,(ll)n)];
				if(r>(ll)2e18) break;
			}
			qm[i][j]=r;
		}
	}
	ask(5,1);
}