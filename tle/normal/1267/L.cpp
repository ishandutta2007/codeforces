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
#include <assert.h>
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
int n,l,k;
char buf[3333333];
int pool[26];
char op[2333][2333];
bool good[2333];
int main()
{
	scanf("%d%d%d",&n,&l,&k);
	scanf("%s",buf);
	for(int i=0;i<k;++i) good[i]=1;
	for(int i=0;buf[i];++i)
		++pool[buf[i]-'a'];
	for(int i=0;i<l;++i)
	{
		int tg=0;
		for(int j=0;j<n;++j) tg+=good[j];
		int p=0,su=0;
		while(su+pool[p]<tg)
			su+=pool[p++];
		int ex=su+pool[p]-tg;
		pool[p]-=ex;
		int p_=p;
		for(int j=k-1;j>=0;--j) if(good[j])
		{
			while(!pool[p]) --p;
			op[j][i]=p+'a'; --pool[p];
		}
		pool[p_]+=ex;
		for(int j=0;j<n;++j)
			good[j]&=op[j][i]==op[k-1][i];
		p=25;
		for(int j=n-1;j>=0;--j) if(!op[j][i])
		{
			while(!pool[p]) --p;
			op[j][i]=p+'a'; --pool[p];
		}
	}
	for(int j=0;j+1<n;++j)
	{
		if(strcmp(op[j],op[j+1])>0)
		{
			assert(0);
		}
	}
	for(int j=0;j<n;++j)
		puts(op[j]);
}