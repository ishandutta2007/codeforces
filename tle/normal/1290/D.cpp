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
#define SZ 666666
bool ob[SZ],bad[SZ];
int main()
{
	int n,k;
	cin>>n>>k;
	k=max(k/2,1);
	int nb=n/k;
	for(int d=1;d<=nb;++d)
	{
		for(int s=1;s<=d;++s)
		{
			vector<int> w;
			for(int g=s;g<=nb;g+=d)
				for(int j=(g-1)*k+1;j<=g*k;++j)
					w.pb(j);
			if(w.size()<=k) continue;
			for(int g=s;g<=nb;g+=d) ob[g]=1;
			for(auto u:w)
			{
				cout<<"? "<<u<<endl;
				string s; cin>>s;
				bad[u]|=s[0]=='Y';
			}
			cout<<"R"<<endl;
		}
	}
	//just in case
	for(int i=1;i<=nb;++i) if(!ob[i])
	{
		for(int j=(i-1)*k+1;j<=i*k;++j)
		{
			cout<<"? "<<j<<endl;
			string s; cin>>s;
			bad[j]|=s[0]=='Y';
		}
	}
	int cnt=0;
	for(int i=1;i<=n;++i)
		cnt+=!bad[i];
	cout<<"! "<<cnt<<endl;
}