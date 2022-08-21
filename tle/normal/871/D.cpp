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
#define SZ 12345678
int n,ps[SZ/10],pn=0,phi[SZ],pp[SZ],fl[SZ],qzh[SZ],tt[SZ];
bool np[SZ];
int main()
{
	scanf("%d",&n); np[1]=0; phi[1]=1; pp[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!np[i])
		{
			ps[++pn]=i,phi[i]=i-1,pp[i]=i;
			for(int j=i;j<=n;j+=i) ++fl[j];
		}
		for(int j=1;j<=pn&&i*ps[j]<=n;++j)
		{
			np[i*ps[j]]=1; pp[i*ps[j]]=ps[j];
			if(i%ps[j]==0)
			{
				phi[i*ps[j]]=phi[i]*ps[j];
				break;
			}
			else phi[i*ps[j]]=phi[i]*(ps[j]-1);
		}
	}
	//for(int i=1;i<=n;++i) cout<<i<<":"<<pp[i]<<"\n";
	for(int i=1;i<=n;++i) qzh[i]=qzh[i-1]+(!np[i]);
	int good=0;
	for(int i=2;i<=n;++i)
	{
		if(i+i<=n||np[i]) ++good;
		if(np[i]) ++tt[pp[i]];
	}
	for(int i=1;i<=n;++i)
		tt[i]+=tt[i-1]; 
	ll aa=(good-1)*ll(good)/2,p1=0,p2=0;
	for(int i=2;i<=n;++i)
		if(i+i<=n||np[i]) p1+=i-1-phi[i];
	for(int i=2;i<=n;++i) if(np[i])
	{
		ll c=phi[i]-qzh[i-1]+fl[i];
		p2+=c;
	}
	for(int i=1;i<=pn;++i)
	{
		int j=ps[i]; if(j+j>n) continue;
		int cm=tt[n/j];
		for(int g=j+j;g<=n;g+=j)
			if(g+g<=n||np[g]) --cm;
		p2+=cm;
	}
	int r=pn;
	for(int i=1;i<=pn;++i)
	{
		while(ps[i]*(ll)ps[r]>n) --r;
		if(i>r) break;
		p2+=r-i;
	}
	ll p3=aa-p1-p2;
	//cout<<p1<<","<<p2<<","<<p3<<"\n";
	cout<<p1+p2*2+p3*3<<"\n";
}