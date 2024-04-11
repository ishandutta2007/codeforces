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
const int MOD=998244353;
int n,k,l,a[SZ];
ll f[SZ];
struct Shifter
{
ll s[SZ];
int R=-1;
void go(int r)
{
	while(R<r)
		++R,(s[R%l]+=f[R])%=MOD;
}
}A,B,C;
int main()
{
	scanf("%d%d%d",&n,&k,&l);
	if(k==1)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	f[0]=1;
	//[L,R]equ [R+1,i]any
	int L=1,R=0,p=-1;
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=-1)
		{
			if(a[i]!=p) L=R+1;
			R=i; p=a[i];
		}
		A.go(R-1); B.go(L-2); C.go(i-1);
		if(L<=R)
		{
			//(R-L) mod l=1: 1
			//(R-L) mod l=0: -1
			(f[i]+=A.s[(i+l-1)%l])%=MOD;
			(f[i]-=B.s[(i+l-1)%l])%=MOD;
			(f[i]-=A.s[(i)%l])%=MOD;
			(f[i]+=B.s[(i)%l])%=MOD;
		}
		if(R+1<=i)
		{
			(f[i]+=C.s[(i+l-1)%l]*(ll)k)%=MOD;
			(f[i]-=A.s[(i+l-1)%l]*(ll)k)%=MOD;
			(f[i]-=C.s[(i)%l]*(ll)k)%=MOD;
			(f[i]+=A.s[(i)%l]*(ll)k)%=MOD;
		}
	}
	ll ans=f[n];
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}