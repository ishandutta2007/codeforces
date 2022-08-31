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
bitset<707> f[707],ok[707],oll[707],orr[707];
int n,a[777];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(__gcd(a[i],a[j])>1) ok[i][j]=1;
	for(int i=1;i<=n;++i)
		oll[i][i]=orr[i][i]=i;
	for(int len=1;len<=n;++len)
	{
		for(int l=1;l+len-1<=n;++l)
		{
			int r=l+len-1;
			f[l]=oll[l]&orr[r];
			if((f[l]&ok[r+1]).count())
				oll[l][r+1]=1;
			if((f[l]&ok[l-1]).count())
				orr[r][l-1]=1;
		}
	}
	if(f[1].count()) puts("Yes");
	else puts("No");
}