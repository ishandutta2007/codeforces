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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#ifdef LOCAL
#define TIMER cerr<<clock()<<"ms\n"
#else
#define TIMER
#endif
#define SZ 888888
int n,m,p[233333],x,lg[555];
char bs[555],gs[555][555];
typedef long long ll;
int N=0,M=1,S,T,fst[SZ],nxt[SZ],va[SZ],vb[SZ];
ll cap[SZ],cost[SZ];
void ad_dl(int a,int b,ll ca,ll co)
{
    ++M; nxt[M]=fst[a]; fst[a]=M; va[M]=a; vb[M]=b; cap[M]=ca; cost[M]=co;
}
void addl(int a,int b,ll ca,ll co) {ad_dl(a,b,ca,co); ad_dl(b,a,0,-co);}
ll dis[SZ]; int q[SZ],fe[SZ];
bool inq[SZ];
bool spfa()
{
    ll inf=2000000000000000LL;
    for(int i=1;i<=N;i++) dis[i]=inf;
    inq[S]=1; q[1]=S; dis[S]=0; int h=1,t=2;
    while(h!=t)
    {
        int cur=q[h++]; h&=131071;
        for(int e=fst[cur];e;e=nxt[e])
        {
            if(!cap[e]||dis[vb[e]]<=dis[cur]+cost[e]) continue;
            int b=vb[e],co=cost[e];
            dis[b]=dis[cur]+co; fe[b]=e;
            if(!inq[b]) {inq[b]=1; q[t++]=b; t&=131071;}
        }
        inq[cur]=0;
    }
    return dis[T]!=inf;
}
ll mcf()
{
    ll ans=0;
    while(spfa())
    {
        ll cur=2000000000000000LL;
    	//cout<<"spfa..."<<cur<<"\n";
        for(int i=fe[T];i;i=fe[va[i]]) cur=min(cur,cap[i]);
    	//cout<<"spfa..."<<cur<<"\n";
        for(int i=fe[T];i;i=fe[va[i]])
        {
            ans+=cur*cost[i];
            cap[i]-=cur; cap[i^1]+=cur;
        }
    }
    return ans;
}
int main()
{
	scanf("%d%s%d",&n,bs,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d",gs[i],p+i);
		lg[i]=strlen(gs[i]);
	}
	int x; scanf("%d",&x);
	N=n+1;
	int in=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j+lg[i]<=n;j++)
		{
			bool ok=1;
			for(int k=0;k<lg[i];k++) ok&=gs[i][k]==bs[j+k];
			if(ok) addl(j+1,j+lg[i]+1,1,-p[i]);
		}
	}
	for(int i=1;i<=n;i++) addl(i,i+1,x,0);
	S=++N; T=++N; addl(S,1,x,0); addl(n+1,T,x,0);
	cout<<-mcf()<<"\n";
}