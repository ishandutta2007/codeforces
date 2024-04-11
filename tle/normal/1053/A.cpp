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
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int a=n,b=m;
	//(nm)/k
	{
	int t=__gcd(k,a);
	k/=t; a/=t;
	}
	{
	int t=__gcd(k,b);
	k/=t; b/=t;
	}
	if(k>2)
	{
		puts("NO");
		return 0;
	}
	if(k!=2)
	{
	if(a*2<=n) a*=2;
	else if(b*2<=m) b*=2;
	}
	puts("YES");
	cout<<0<<" "<<0<<"\n";
	cout<<0<<" "<<b<<"\n";
	cout<<a<<" "<<0<<"\n";
}