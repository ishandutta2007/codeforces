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
int n,m,a[SZ],b[SZ],ra[SZ],c[SZ],rb[SZ];
int oa[SZ],ob[SZ],oc[SZ],od[SZ],oe[SZ],xc[SZ],aa[SZ],nc[SZ];
int up[SZ];
vector<pii> qry[SZ];
int bs[SZ];
void edt(int x,int y)
{
	for(;x<=n;x+=x&-x)bs[x]+=y;
}
int qsu(int x)
{
	int s=0;
	for(;x>=1;x-=x&-x) s+=bs[x];
	return s;
}
int qsu(int l,int r)
{return qsu(r)-qsu(l-1);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),ra[a[i]]=i;
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]),
		rb[b[i]]=i;
	for(int i=1;i<=n;++i)
		xc[ra[i]]=rb[i];
//	for(int i=1;i<=n;++i)
//		cout<<rb[i]<<",";
//	cout<<" ";
//	for(int i=1;i<=n;++i)
//		cout<<xc[i]<<",";
//	cout<<"\n";
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",oa+i,ob+i,oc+i);
		if(oa[i]==2)
		{
			//cerr<<rb[b[ob[i]]]-ob[i]<<" "<<rb[b[oc[i]]]-oc[i]<<"??\n";
			swap(b[ob[i]],b[oc[i]]);
			swap(rb[b[ob[i]]],rb[b[oc[i]]]);
//			cerr<<"WTH"<<xc[ra[b[ob[i]]]]<<" "<<rb[b[ob[i]]]<<"\n";
//			cerr<<"WTH"<<xc[ra[b[oc[i]]]]<<" "<<rb[b[oc[i]]]<<"\n";
//			xc[ra[b[ob[i]]]]=rb[b[ob[i]]];
//			xc[ra[b[oc[i]]]]=rb[b[oc[i]]];
//			cout<<ra[b[ob[i]]]<<" "<<b[ob[i]]<<"??\n";
			//cerr<<rb[b[ob[i]]]-ob[i]<<" "<<rb[b[oc[i]]]-oc[i]<<"??\n";
			ob[i]=ra[b[ob[i]]],oc[i]=ra[b[oc[i]]];
//			swap(xc[ob[i]],xc[oc[i]]);
//	for(int i=1;i<=n;++i)
//		cout<<rb[i]<<",";
//	cout<<" ";
//	for(int i=1;i<=n;++i)
//		cout<<xc[i]<<",";
//	cout<<"\n";
		}
		else
		{
			scanf("%d%d",od+i,oe+i);
//			int cn=0;
//			for(int j=ob[i];j<=oc[i];++j)
//				cn+=xc[j]>=od[i]&&xc[j]<=oe[i];
//			printf("%d\n",cn);
		}
	}
//	return 0;
	int S=sqrt(2e5)*4;
	vector<int> ch;
	int L=1;
	for(int i=1;i<=m;++i)
	{
		if(oa[i]==2)
		{
			if(up[ob[i]]!=L)
				up[ob[i]]=L,ch.pb(ob[i]);
			if(up[oc[i]]!=L)
				up[oc[i]]=L,ch.pb(oc[i]);
		}
		else
		{
			qry[ob[i]-1].pb(mp(i,-1));
			qry[oc[i]].pb(mp(i,1));
		}
		if(i%S==0||i==m)
		{
			for(int j=1;j<=n;++j) nc[j]=xc[j];
			for(int j=0;j<=n;++j) bs[j]=0;
			for(int j=0;j<=n;++j)
			{
				if(j) edt(xc[j],1);
				for(auto t:qry[j])
					aa[t.fi]+=t.se*qsu(od[t.fi],oe[t.fi]);
			}
			for(int j=L;j<=i;++j)
			{
				if(oa[j]==2)
					swap(nc[ob[j]],nc[oc[j]]);
				else
					for(auto t:ch)
						if(t>=ob[j]&&t<=oc[j])
						{
							aa[j]-=xc[t]>=od[j]&&xc[t]<=oe[j];
							aa[j]+=nc[t]>=od[j]&&nc[t]<=oe[j];
						}
			}
			for(int j=1;j<=n;++j) xc[j]=nc[j];
			for(int j=0;j<=n;++j) qry[j].clear();
			ch.clear(); L=i+1;
		}
	}
	for(int i=1;i<=m;++i)
		if(oa[i]==1) printf("%d\n",aa[i]);
}