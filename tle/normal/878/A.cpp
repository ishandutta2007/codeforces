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
int b[16][2];
char buf[233];
int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<10;++i)
		b[i][0]=0,b[i][1]=1;
	while(n--)
	{
		scanf("%s%d",buf,&x);
		if(buf[0]=='|')
		{
			for(int i=0;i<10;++i)
				if(x&(1<<i)) b[i][0]=b[i][1]=1;
		}
		else if(buf[0]=='&')
		{
			for(int i=0;i<10;++i)
				if(!(x&(1<<i))) b[i][0]=b[i][1]=0;
		}
		else
		{
			for(int i=0;i<10;++i)
				if(x&(1<<i))
					b[i][0]=!b[i][0],b[i][1]=!b[i][1];
		}
	}
	cout<<"3\n";
	int an=1023,oo=0,xo=0;
	for(int i=0;i<10;++i)
	{
		if(b[i][0]==b[i][1])
		{
			if(b[i][0]) oo|=1<<i;
			else an^=1<<i;
		}
		else if(b[i][0]) xo^=1<<i;
	}
	printf("& %d\n| %d\n^ %d\n",an,oo,xo);
}