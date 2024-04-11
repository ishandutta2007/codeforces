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
int n,l[SZ],r[SZ],a[SZ];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i) cin>>l[i];
	for(int i=1;i<=n;++i) cin>>r[i];
	for(int i=1;i<=n;++i) a[i]=n-l[i]-r[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)
			if(a[i]<a[j]) --l[i];
		for(int j=n;j>i;--j)
			if(a[i]<a[j]) --r[i];
		if(l[i]||r[i])
		{puts("NO"); return 0;}
	}
	puts("YES");
	for(int i=1;i<=n;++i)
		cout<<a[i]<<' ';
	cout<<"\n";
}