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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int dx[8]={1,1,0,-1,-1,-1,0,1},
dy[8]={0,1,1,1,0,-1,-1,-1};
bool cv[2][310][310][8];
bool vis[310][310];
int main()
{
	int n;
	scanf("%d",&n);
	cv[0][153][153][0]=1;
	vis[153][153]=1;
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		if(i==1) --t;
		memset(cv[1],0,sizeof(cv[1]));
		for(int j=1;j<=309;j++)
		{
			for(int k=1;k<=309;k++)
			{
				for(int s=0;s<8;s++)
				{
					if(!cv[0][j][k][s]) continue;
					for(int g=1;g<=t;g++)
						vis[j+dx[s]*g][k+dy[s]*g]=1;
					cv[1][j+dx[s]*t][k+dy[s]*t][(s+7)&7]=1;
					cv[1][j+dx[s]*t][k+dy[s]*t][(s+1)&7]=1;
				}
			}
		}
		memcpy(cv[0],cv[1],sizeof(cv[1]));
	}
	int qwq=0;
	for(int j=1;j<=309;j++)
		for(int k=1;k<=309;k++)
			qwq+=vis[j][k];
	printf("%d\n",qwq);
}