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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T>
struct rbt: tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>{};
rbt<pair<ll,int> > s1,s2;
int n,l,v;
pii p[SZ];
int main()
{
	scanf("%d%d%d",&n,&l,&v);
	for(int i=1;i<=n;++i)	
		scanf("%d%d",&p[i].fi,&p[i].se);
	sort(p+1,p+1+n);
	ll c1=0,ans=0;
	for(int i=n;i>=1;--i)
		if(p[i].se==-1)
		{
			++c1;
			s1.insert(mp(v*(ll)(p[i].fi+l)-p[i].fi,i));
			s2.insert(mp(v*(ll)(p[i].fi+l)+p[i].fi,i));
		}
		else
		{
			ans+=c1
			-s1.order_of_key(mp(v*(ll)p[i].fi+p[i].fi+l,int(1e9)))
			-s2.order_of_key(mp(v*(ll)p[i].fi-p[i].fi-l,int(1e9)));
		}
	cout<<ans<<"\n";
}