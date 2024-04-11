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
#define SZ 2333333
struct ms
{
char a[33][33];
};
int n;
ms rs(ms x)
{
	//ij -> jn+1-i 
	ms g;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			g.a[j][n+1-i]=x.a[i][j];
	return g;
}
ms f1(ms x)
{
	ms g;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			g.a[i][n+1-j]=x.a[i][j];
	return g;
}
ms f2(ms x)
{
	ms g;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			g.a[n+1-i][j]=x.a[i][j];
	return g;
}
bool operator == (ms a,ms b)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(a.a[i][j]!=b.a[i][j]) return 0;
	return 1;
}
ms A,B,X;
#define OK {puts("Yes");return 0;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>(A.a[i]+1);
	for(int i=1;i<=n;++i)
		cin>>(B.a[i]+1);
	X=A;
	for(int s=0;s<4;++s)
	{
		ms Y=f1(X);
		if(Y==B) OK
		if(f2(Y)==B) OK
		if(f2(X)==B) OK 
		X=rs(X);
	}
	puts("No");
}