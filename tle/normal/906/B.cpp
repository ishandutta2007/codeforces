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
int id[233333],bp[233333],cp[233333];
void gen(int n,int*a)
{
	int p=0;
	for(int j=2;j<=n/2*2;j+=2) a[p++]=j-1;
	for(int j=1;j<=n;j+=2) a[p++]=j-1;
}
map<pii,bool> in;
int main()
{
	int n,m;
	cin>>n>>m;
	if(n==1&&m==1)
	{
		puts("YES\n1");
		return 0;
	}
	if(min(n,m)==1&&max(n,m)<=3)
	{
		puts("NO");
		return 0;
	}
	gen(n,bp); gen(m,cp);
	if(n==1)
	{
		puts("YES");
		for(int j=0;j<m;++j) printf("%d ",cp[j]+1);
		return 0;
	}
	if(m==1)
	{
		puts("YES");
		for(int j=0;j<n;++j) printf("%d\n",bp[j]+1);
		return 0;
	}
	if(n>=4&&m>=4)
	{
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			id[bp[i]*m+cp[j]]=i*m+j+1;
	puts("YES");
	for(int i=0;i<n;++i,puts(""))
		for(int j=0;j<m;++j)
			printf("%d ",id[i*m+j]);
	return 0;
	}
	if((n==2&&m==3)||(n==3&&m==2)||(n==2&&m==2))
	{
		puts("NO");
		return 0;
	}
	if(min(n,m)==2||max(n,m)<=10)
	{
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			id[i*m+j]=i*m+j;
	for(int i=0;i<n;++i)
		for(int j=0;j+1<m;++j)
			in[pii(i*m+j,i*m+j+1)]=
			in[pii(i*m+j+1,i*m+j)]=1;
	for(int i=0;i+1<n;++i)
		for(int j=0;j<m;++j)
			in[pii(i*m+j,(i+1)*m+j)]=
			in[pii((i+1)*m+j,i*m+j)]=1;
	while(1)
	{
		random_shuffle(id,id+n*m);
		bool gg=0;
		for(int i=0;i<n;++i)
			for(int j=0;j+1<m;++j)
				if(in[pii(id[i*m+j],id[i*m+j+1])]) {gg=1; goto GG;}
		for(int i=0;i+1<n;++i)
			for(int j=0;j<m;++j)
				if(in[pii(id[i*m+j],id[(i+1)*m+j])]) {gg=1; goto GG;}
		GG: if(gg) continue;
		break;
	}
	puts("YES");
	for(int i=0;i<n;++i,puts(""))
		for(int j=0;j<m;++j)
			printf("%d ",id[i*m+j]+1);
	return 0;
	}
	bool rv=0;
	if(n>m) swap(n,m),rv=1;
	gen(n,bp); gen(m,cp);
	//123 -> 321
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			if(!rv)
			id[i*m+j]=i*m+cp[(j+i*2)%m];
			else
			id[i*m+j]=cp[(j+i*2)%m]*n+i;
		}
	for(int i=0;i<n;++i)
		for(int j=0;j+1<m;++j)
			in[pii(i*m+j,i*m+j+1)]=
			in[pii(i*m+j+1,i*m+j)]=1;
	for(int i=0;i+1<n;++i)
		for(int j=0;j<m;++j)
			in[pii(i*m+j,(i+1)*m+j)]=
			in[pii((i+1)*m+j,i*m+j)]=1;
	puts("YES");
	if(!rv)
	for(int i=0;i<n;++i,puts(""))
		for(int j=0;j<m;++j)
			printf("%d ",id[i*m+j]+1);
	else
	for(int i=0;i<m;++i,puts(""))
		for(int j=0;j<n;++j)
			printf("%d ",id[j*m+i]+1);
	return 0;
}