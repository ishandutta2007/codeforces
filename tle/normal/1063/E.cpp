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
#define SZ 6666
int n,a[SZ];
bool t[SZ];
vector<int> vs[SZ]; int vn;
int tn=0;
string w;
string go(int p,int q)
{
	string h=w;
	if(p==q) return h;
	if(p<q)
		h[p-1]='\\',h[q-1]='\\';
	else
		h[p-1]='/',h[q-1]='/';
	return h;
}
int main()
{
	cin>>n; bool s=1;
	for(int i=1;i<=n;++i)
		cin>>a[i],s&=a[i]==i,w.pb('.');
	//a[i] to i
	if(s)
	{
		printf("%d\n",n);
		for(int i=1;i<=n;++i)
			puts(w.c_str());
		return 0;
	}
	printf("%d\n",n-1);
	for(int i=1;i<=n;++i) if(!t[i])
	{
		vector<int> v;
		for(int j=i;!t[j];j=a[j])
			v.pb(j),t[j]=1;
		if(i==1)
		{
			int u=v.size();
			for(int j=1;j<u;++j)
			{
				int b=(j+1==u)?v[0]:v[j+1],
				a=v[j]; //b to a
				puts(go(b,a).c_str()); ++vn;
			}
			continue;
		}
		if(v.size()==1)
			continue;
		vector<int> w=v;
		pii mx(-1,-1);
		for(int i=0;i<v.size();++i)
			mx=max(mx,pii(v[i],i));
		int u=v.size();
		for(int i=0;i<v.size();++i)
			w[i]=v[(i+1)%u];
		puts(go(w[0],1).c_str()); ++vn;
		for(int j=0;j<u-1;++j)
		{
			int b=(j+1==u)?w[0]:w[j+1],
			a=w[j]; //b to a
			string s=go(b,a);
			if(j==u-2) s[0]='\\';
			puts(s.c_str()); ++vn;
		}
	}
	while(vn<n) puts(w.c_str()),++vn;
}