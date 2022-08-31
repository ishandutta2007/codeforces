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
char s[SZ],t[SZ];
int n,m;
vector<int> A,B;
vector<pii> aa;
void go(int l,int r)
{
	string a,b;
	for(int i=0;i<r;++i) a.pb(t[i]);
	for(int i=l;i<n;++i) a.pb(s[i]);
	for(int i=0;i<l;++i) b.pb(s[i]);
	for(int i=r;i<m;++i) b.pb(t[i]);
	vector<pii> qs;
	if(l||r) qs.pb(pii(l,r));
	int t=a.back(),u=b.back(),
	ca=a.size()-1,cb=b.size()-1,g=0;
	while(1)
	{
		while(ca>=0&&a[ca]==t) --ca;
		while(cb>=0&&b[cb]==u) --cb;
		if(ca<0&&cb<0) break;
		if(!g)
		qs.pb(pii(ca+1,cb+1));
		else
		qs.pb(pii(cb+1,ca+1));
		ca=max(ca-1,-1);
		cb=max(cb-1,-1);
		g^=1; swap(t,u);
	}
	if(qs.size()<aa.size()) aa=qs;
}
void work()
{
	A.clear(); B.clear();
	for(int i=0;i+1<n;++i)
		if(s[i]!=s[i+1]) A.pb(i);
	for(int i=0;i+1<m;++i)
		if(t[i]!=t[i+1]) B.pb(i);
	//cerr<<A.size()+B.size()<<"??\n";
	go(0,0);
	if(A.size()) go(A[0]+1,0);
	if(B.size()) go(0,B[0]+1);
	go(n-1,0);
	go(0,m-1);
	if(A.size()>B.size())
	{
		int t=(A.size()-B.size())/2;
		for(int j=t-2;j<=t+2;++j)
			if(j>=0&&j<int(A.size()))
			{
				go(A[j]+1,0);
				if(B.size()) go(A[j]+1,B[0]+1);
			}
	}
	if(A.size()<B.size())
	{
		int t=(B.size()-A.size())/2;
		for(int j=t-2;j<=t+2;++j)
			if(j>=0&&j<int(B.size()))
			{
				go(0,B[j]+1);
				if(A.size()) go(A[0]+1,B[j]+1);
			}
	}
}
int main()
{
	scanf("%s%s",s,t);
	n=strlen(s); m=strlen(t);
	for(int i=1;i<=500001;++i) aa.pb(pii(0,0));
	s[n++]='a'; t[m++]='b'; work();
	s[n-1]='b'; t[m-1]='a'; work();
	printf("%d\n",int(aa.size()));
	for(auto x:aa) printf("%d %d\n",x.fi,x.se);
}