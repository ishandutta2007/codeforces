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
#include <assert.h>
#include <unordered_map>
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
int T;
ll gans(vector<char> u)
{
	//delete any element <=size each time
	map<char,int> pc;
	for(auto t:u) pc[t]++;
	ll ans=1;
	for(int j=1;j<=u.size();++j)
	{
		int w=0;
		for(auto c:u) w+=c<=j;
		ans*=w-j+1;
	}
	for(auto g:pc)
		for(int j=g.se;j;--j) ans/=j;
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ll w;
		scanf("%lld",&w);
		vector<char> vs;
		for(int i=2;w;++i)
			vs.pb(w%i),w/=i;
		sort(vs.begin(),vs.end());
		ll ans=gans(vs);
		if(vs.size()&&*vs.begin()==0)
			vs.erase(vs.begin()),ans-=gans(vs);
		printf("%lld\n",ans-1);
	}
}