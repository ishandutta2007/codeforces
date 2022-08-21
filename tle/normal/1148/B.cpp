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
#define SZ 666666
int n,m,ta,tb,k,a[SZ],b[SZ];
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),a[i]+=ta;
	for(int i=1;i<=m;++i)
		scanf("%d",b+i);
	//a[i]<=b[j] find minimum such j
	//a[i]<=b[j]<=t
	int aa=0;
	const int inf=2.01e9;
	for(int j=0;j<=n&&j<=k;++j)
	{
		if(j==n) aa=inf;
		else
		{
			int u=a[j+1];
			//cancel some shit >=u
			int w=lower_bound(b+1,b+1+m,u)-b;
			//b[w]>=u
			//cancel b[w]...b[w+k-j]
			int r=w+k-j-1;
			if(r>=m) aa=inf;
			else aa=max(aa,b[r+1]);
		}
	}
	if(aa==inf) cout<<-1<<"\n";
	else cout<<aa+tb<<"\n";
}