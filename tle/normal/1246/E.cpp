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
#define SZ 66666
int n,k,a[233],dep[233];
#define D 12
bitset<2005> s[D+1][1<<16];
int main()
{
	scanf("%d%d",&n,&k);
//	for(int j=1;j<=(1024-n)/2;++j)
//		a[rand()%n]+=2;
	for(int i=0;i<n;++i)// a[i]+=1;
//		a[i]=(2048-n)/n/2*2+1;
		scanf("%d",a+i);
	s[0][0][0]=1;
	for(int i=1;i<=D;++i)
	{
		for(int g=0;g<(1<<n);++g)
			for(int w=2000/k;w>=0;--w)
				if(s[i-1][g][w*k]) s[i][g][w]=1;
		for(int g=0;g<(1<<n);++g)
			for(int h=0;h<n;++h) if(!(g&(1<<h)))
				s[i][g|(1<<h)]|=s[i][g]<<a[h];
	}
	if(!s[D][(1<<n)-1][1])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int x=D,y=(1<<n)-1,z=1;
	for(int g=x;g>=1;--g)
	{
//		cout<<g<<"WW\n";
		if(g!=x) z*=k;
		//find a subset that is good
		bool ok=0;
		for(int p=0;p<=y;++p) if((y&p)==p)
		{
			int su=0;
			for(int t=0;t<n;++t)
				if(p&(1<<t)) su+=a[t];
			if(su<=z&&(z-su)*k<=2000&&s[g-1][y-p][(z-su)*k])
			{
				ok=1;
//				cerr<<g<<","<<y<<","<<z<<"  "<<su<<"|"<<p<<"  "<<(z-su)*k<<"\n";
				for(int t=0;t<n;++t)
					if(p&(1<<t))
					{
						dep[t]=D-g;
					}
				y-=p; z-=su; break;
			}
		}
		assert(ok);
	}
	priority_queue<pii> pq;
	for(int t=0;t<n;++t)
		pq.push(pii(dep[t],a[t]));
	while(pq.size()>1)
	{
		pii g=pq.top(); pq.pop();
		pii h=pq.top(); pq.pop();
//		cerr<<g.fi<<","<<g.se<<"  "<<h.fi<<","<<h.se<<"\n";
		assert(g.fi==h.fi);
		printf("%d %d\n",g.se,h.se);
		pii z(g.fi,g.se+h.se);
		while(z.se%k==0) z.fi--,z.se/=k;
		pq.push(z);
	}
	assert(pq.top().se==1);
}