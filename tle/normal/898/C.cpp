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
map<string,set<string> > num;
bool pf(string a,string b)
{
	return b.size()>=a.size()&&
	b.substr(b.size()-a.size(),a.size())==a;
}
int main()
{
	cin>>n;
	while(n--)
	{
		string s; int a; string b;
		cin>>s; auto&p=num[s];
		cin>>a;
		while(a--) cin>>b,p.insert(b);
	}
	printf("%d\n",int(num.size()));
	for(auto r:num)
	{
		cout<<r.fi<<" ";
		set<string> cur;
		for(auto s:r.se)
		{
			set<string> nx;
			bool ban=0;
			for(auto aa:cur)
				if(pf(aa,s));else
				{
					nx.insert(aa);
					if(pf(s,aa)) ban=1;
				}
			if(!ban) nx.insert(s); cur=nx;
		}
		printf("%d ",(int)cur.size());
		for(auto c:cur) cout<<c<<" ";
		cout<<"\n";
	}
}