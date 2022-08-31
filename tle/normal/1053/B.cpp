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
#define SZ 333333
int n,b[SZ],q[SZ],c[SZ],q1[SZ],n2[SZ],qq[2][SZ];
ll a[SZ];
ll work(int u)
{
	n2[n+1]=n+1;
	for(int i=n;i>=1;--i)
	{
		if(c[i]==2) n2[i]=i;
		else n2[i]=n2[i+1];
	}
	for(int i=1;i<=n;++i)
		q1[i]=q1[i-1]+(c[i]==1);
	int r=0; ll ans=0;
	for(int i=1;i<=n;++i)
	{
		while((q1[r]-q1[i-1]==0
		||q[r]-q[i-1]<u)&&r<=n) ++r;
		if(r>n) break;
		if(r<n2[i])
			ans+=qq[q[i-1]&1][n2[i]-1]
			-qq[q[i-1]&1][r-1];
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i),
		b[i]=__builtin_popcountll(a[i]),
		q[i]=q[i-1]+b[i];
		qq[0][i]=qq[0][i-1]+(q[i]%2==0);
		qq[1][i]=qq[1][i-1]+(q[i]%2==1);
	}
	ll ans=0;
	for(int i=0;i<=64;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(b[j]<i) c[j]=0;
			else if(b[j]==i) c[j]=1;
			else c[j]=2;
		}
		ans+=work(i+i);
	}
	cout<<ans<<"\n";
}