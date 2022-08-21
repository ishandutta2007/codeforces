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
int n,k,p[23333];
int main()
{
	cin>>n>>k; ll ans=0;
	for(int j=0;j<=k;++j)
	{
	int aa=0;
	for(int i=1;i<=j;++i) p[i]=i;
	do
	{
		bool d=0;
		for(int i=1;i<=j;++i) if(p[i]==i) d=1;
		if(!d) ++aa;
	}while(next_permutation(p+1,p+1+j));
	ll a=1;
	for(int r=0;r<j;++r) a*=n-r;
	for(int r=1;r<=j;++r) a/=r;
	ans+=a*aa;
	}
	cout<<ans<<"\n";
}