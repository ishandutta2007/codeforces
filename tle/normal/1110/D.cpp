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
#define SZ 1234567
int n,m,cn[SZ],a[SZ];
int u[SZ][3][3]; // 
inline void cmax(int&a,int b)
{if(a<b)a=b;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),++cn[a[i]];
	memset(u,-127/3,sizeof u);
	u[0][0][0]=0;
	for(int i=0;i<m+5;++i)
		for(int j=0;j<=2;++j)
			for(int k=0;k<=2;++k) if(u[i][j][k]>=0)
			{
				int w=cn[i+1]-j-k;
				for(int s=0;s<=2&&s<=w;++s)
					cmax(u[i+1][k][s],u[i][j][k]+(w-s)/3+s);
			}
	cout<<u[m+5][0][0]<<"\n";
}