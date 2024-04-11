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
#define SZ
int f[12][12]=
{
0,0,0,1,2,3,3,3,3,4,5,6,
0,0,2,4,5,6,6,8,9,10,11,12,
0,2,4,6,7,9,10,12,13,15,16,18,
1,4,6,8,10,12,14,16,18,20,22,24,
2,5,7,10,12,15,17,20,22,25,27,30,
3,6,9,12,15,18,21,24,27,30,33,36,
3,6,10,14,17,21,24,28,31,35,38,42,
3,8,12,16,20,24,28,32,36,40,44,48,
3,9,13,18,22,27,31,36,40,45,49,54,
4,10,15,20,25,30,35,40,45,50,55,60,
5,11,16,22,27,33,38,44,49,55,60,66,
6,12,18,24,30,36,42,48,54,60,66,72,
};
int main()
{
	int n,m;
	cin>>n>>m;
	if(n>m) swap(n,m);
	ll ans=0;
	if(n==1)
	{
		int u=m%6;
		ans=m/6LL*3+(u>=4)+(u>=5);
	}
	else if(n<=12&&m<=12) ans=f[n-1][m-1];
	else ans=(ll)n*m/2;
	cout<<ans*2<<"\n";
}