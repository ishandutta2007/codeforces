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
int n;
bool qry(int r1,int c1,int r2,int c2)
{
	if(r1<1||r1>n||c1<1||c1>n||r2<1||r2>n||c2<1||c2>n)
		return 0;
	cout<<"? "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
	string x; cin>>x; return x=="YES";
}
int good1(int a,int b)
{
	if(n-a+n-b>=n-1) return qry(a,b,n,n);
	return -1;
}
int good2(int a,int b)
{
	if(a-1+b-1>=n-1) return qry(1,1,a,b);
	throw "GG";
}
map<pii,string> ys;
int main()
{
	cin>>n;
	pii c(1,1);
	string s;
	ys[c]="";
	while(c!=pii(n,n))
	{
		int t=good1(c.fi+1,c.se);
		if(t==-1)
			break;
		if(t) s.pb('D'),++c.fi;
		else s.pb('R'),++c.se;
		ys[c]=s;
	}
	s="";
	c=pii(n,n);
	while(1)
	{
		if(ys.count(c))
		{
			reverse(s.begin(),s.end());
			cout<<"! "<<ys[c]<<s<<endl;
			return 0;
		}
		int t=good2(c.fi,c.se-1);
		if(t) s.pb('R'),--c.se;
		else s.pb('D'),--c.fi;
	}
}