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
#define SZ 23333
int n,m,a[555][555];
pii ps[SZ];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	}
	vector<int> gg(133);
	for(int i=1;i<n;++i) //i need to win
	{
		for(int j=1;j<=m;++j)
			ps[j]=pii(a[j][n]-a[j][i],j);
		sort(ps+1,ps+1+m);
		int su=0,j;
		for(j=1;j<=m;++j)
		{
			if(su+ps[j].fi>0) break;
			su+=ps[j].fi;
		}
		vector<int> ww;
		while(j<=m) ww.pb(ps[j++].se);
		if(ww.size()<gg.size()) gg=ww;
	}
	printf("%d\n",int(gg.size()));
	for(auto x:gg) printf("%d ",x);
}