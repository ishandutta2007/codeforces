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
char uu[]="hard";
int n,a[SZ];
ll f[SZ][5];
char u[SZ];
int main()
{
	scanf("%d",&n);
	scanf("%s",u+1);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	memset(f,127/3,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<4;++j)
		{
			f[i][j]=min(f[i][j],f[i-1][j]+a[i]);
			f[i][j+(uu[j]==u[i])]=
			min(f[i][j+(uu[j]==u[i])],f[i-1][j]);
		}
	ll mi=2e18;
	for(int j=0;j<4;++j)
		mi=min(mi,f[n][j]);
	cout<<mi<<"\n";
}