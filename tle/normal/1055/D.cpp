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
#define next nxt
struct HashKMP
{
char s[SZ+1]; int n,next[SZ];
void gnext()
{
    n=strlen(s);
    next[0]=-1;
    int j=-1;
    for(int i=1;s[i];i++)
    {
        while(j!=-1&&s[i]!=s[j+1]) j=next[j];
        if(s[i]==s[j+1]) ++j;
        next[i]=j;
    }
}
int kmp(const char* a)
{
    int j=-1;
    for(int i=0;a[i];i++)
    {
        while(j!=-1&&s[j+1]!=a[i]) j=next[j];
        if(s[j+1]==a[i]) ++j;
        if(s[j+1]==0) return i;
    }
    return -1;
}
}ha;
int n,L[SZ],R[SZ],p,q;
string a[3005],b[3005];
bool chk()
{
	string ls="";
	for(int i=1;i<=n;++i)
	{
		if(R[i]==-1) continue;
		if(L[i]+p<0||R[i]+q>=(int)a[i].size()) return 0;
		string t;
		t.pb(a[i][L[i]+p]);
		t.pb(a[i][R[i]+q]);
		t.pb(b[i][L[i]+p]);
		t.pb(b[i][R[i]+q]);
		if(ls=="") ls=t;
		else if(ls!=t) return 0;
	}
	return 1;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
		cin>>b[i];
	string ls=""; int G;
	for(int i=1;i<=n;++i)
	{
		int mi=2e9,mx=-1;
		for(int j=0;j<a[i].size();++j)
			if(a[i][j]!=b[i][j])
				mi=min(mi,j),mx=j;
		L[i]=mi; R[i]=mx;
		if(mx==-1) continue;
		G=i;
		string co=a[i].substr(L[i],R[i]-L[i]+1)
		+"|"+b[i].substr(L[i],R[i]-L[i]+1);
		if(ls=="") ls=co;
		else if(ls!=co)
		{
			puts("NO");
			return 0;
		}
	}
	while(chk()) --p; ++p;
	while(chk()) ++q; --q;
	string A=a[G].substr(L[G]+p,R[G]+q-L[G]-p+1);
	strcpy(ha.s,A.c_str()); ha.gnext();
	for(int i=1;i<=n;++i)
	{
		int u=ha.kmp(a[i].c_str());
		if(R[i]==-1)
		{
			if(u==-1) continue;
			puts("NO"); return 0;
		}
		if(u!=R[i]+q)
		{
			puts("NO");
			return 0;
		}
	}
	cout<<"YES\n";
	cout<<a[G].substr(L[G]+p,R[G]+q-L[G]-p+1)<<"\n";
	cout<<b[G].substr(L[G]+p,R[G]+q-L[G]-p+1)<<"\n";
}