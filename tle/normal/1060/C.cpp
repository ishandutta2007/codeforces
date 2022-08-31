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
int n,m,a[SZ],b[SZ],m1[SZ],m2[SZ];
int main()
{
	memset(m1,127/3,sizeof m1);
	memset(m2,127/3,sizeof m2);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		int s=0;
		for(int j=i;j<=n;++j)
			m1[j-i+1]=min(m1[j-i+1],s+=a[j]);
	}
	for(int i=1;i<=m;++i) cin>>b[i];
	for(int i=1;i<=m;++i)
	{
		int s=0;
		for(int j=i;j<=m;++j)
			m2[j-i+1]=min(m2[j-i+1],s+=b[j]);
	}
	int x,ans=0; cin>>x;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(m1[i]*(ll)m2[j]<=x)
				ans=max(ans,i*j);
	cout<<ans<<"\n";
}