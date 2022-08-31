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
int main()
{
	pii t[3];
	int x[3],y[3];
	for(int i=0;i<3;++i)
		cin>>t[i].fi>>t[i].se,
		x[i]=t[i].fi,y[i]=t[i].se;
	sort(x,x+3);
	sort(y,y+3);
	cout<<y[2]-y[0]+x[2]-x[0]+1<<"\n";
	for(int i=y[0];i<=y[2];++i)
		cout<<x[1]<<" "<<i<<"\n";
	for(int i=0;i<3;++i)
	{
		if(t[i].fi<x[1])
		{
			for(int j=t[i].fi;j<x[1];++j)
				cout<<j<<" "<<t[i].se<<"\n";
		}
		else
		{
			for(int j=t[i].fi;j>x[1];--j)
				cout<<j<<" "<<t[i].se<<"\n";
		}
	}
}