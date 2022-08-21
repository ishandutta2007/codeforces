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
#define SZ 200077
bool np[SZ];
int ps[SZ],pn=0,sb[SZ],sn,n,f,aa[SZ];
bitset<200055> sg[555],pp;
int main()
{
	cin>>n>>f;
	for(int i=2;i<=200000;++i) if(!np[i])
	{
		ps[++pn]=i;
		for(int j=i;j<=200000;j+=i) np[j]=1;
	}
	for(int i=1;i<=pn&&ps[i]<=200000;++i)
	{
		sb[++sn]=ps[i];
		for(int j=i;ps[i]*(ll)ps[j]<=200000&&j<=pn;++j)
			sb[++sn]=ps[i]*ps[j];
	}
	for(int i=1;i<=sn;++i)
		if(sb[i]!=f)
			pp[sb[i]]=1;
	sg[0]=pp; aa[0]=0;
	for(int i=1;i<=200000;++i)
	{
		for(int j=0;;++j)
			if(!(sg[j][i])) {aa[i]=j; break;}
		sg[aa[i]]|=pp<<i;
		if(aa[i]>=500) throw "GG";
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int b,w,r;
		cin>>b>>w>>r;
		ans^=aa[w-b-1];
		ans^=aa[r-w-1];
	}
	if(!ans) puts("Bob\nAlice");
	else puts("Alice\nBob");
}
//