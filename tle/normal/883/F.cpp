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
int n; string ss[445];
set<string> sss;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>ss[i];
		reverse(ss[i].begin(),ss[i].end());
		string g=""; bool ls=0;
		for(int p=0;p<ss[i].size();++p)
		{
			if(ss[i][p]=='u')
				g.pb('o'),g.pb('o');
			else if(ss[i][p]=='k'&&ls) continue;
			else g.pb(ss[i][p]);
			if(ss[i][p]!='h') ls=0;
			else ls=1;
		}
		sss.insert(g);
	}
	cout<<sss.size()<<"\n";
}