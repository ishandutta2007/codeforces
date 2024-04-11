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
typedef long double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
ll n;
int qry(ll x,ll y)
{
	cout<<x<<" "<<y<<endl;
	int g; cin>>g;
	if(!g) exit(0);
	return g;
}
void ty(ll xl,ll xr,ll yl,ll yr)
{
	for(ll x=xl;x<xr;++x)
		for(ll y=yl;y<yr;++y)
			qry(x,y);
}
ll xl,xm,xr,yl,ym,yr;
int main()
{
	cin>>n;
	xl=yl=0; xm=xr=ym=yr=n+1;
	while(1)
	{
//		cout<<xl<<","<<xm<<","<<xr<<" "<<yl<<","<<ym<<","<<yr<<"\n";
		ld sa=(ld)(xm-xl)*(ym-yl),
		sb=(ld)(xm-xl)*(yr-ym),
		sc=(ld)(xr-xm)*(ym-yl);
		ll X,Y;
		if(sb<=sa+sc&&sc<=sa+sb)
			X=(xl+xm)/2,Y=(yl+ym)/2;
		else if(sb>sa+sc)
			X=(xl+xm)/2,Y=ym;
		else
			X=xm,Y=(yl+ym)/2;
		int g=qry(X,Y);
		if(g==1)
			xl=max(xl,X+1);
		else if(g==2)
			yl=max(yl,Y+1);
		else
			xm=min(xm,X),ym=min(ym,Y);
		if(xm<=xl) xm=xr,yr=ym;
		if(ym<=yl) ym=yr,xr=xm;
	}
}