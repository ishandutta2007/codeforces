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
#define SZ 20099
const int S=805;
char l[SZ],r[SZ];
void go(char*s)
{
	int t=strlen(s);
	reverse(s,s+t);
	for(int i=t;i<S;++i) s[i]='0';
}
int rot=1,ch[SZ][10],fail[SZ],cn[SZ][S],e=1;
void insert(const char* s,int w)
{
    int cur=rot;
    for(int i=0;s[i];i++)
    {
        int c=s[i]-'0';
        if(!ch[cur][c]) ch[cur][c]=++e;
        cur=ch[cur][c];
    }
    ++cn[cur][w];
}
int qs[SZ],h=0,t=0;
void bfail()
{
    h=t=0; fail[rot]=rot;
    for(int i=0;i<10;i++)
    {
        if(!ch[rot][i]) 
        {
            ch[rot][i]=rot; continue;
        }
        fail[ch[rot][i]]=rot;
        qs[t++]=ch[rot][i];
    }
    while(h!=t)
    {
        int cur=qs[h++];
        for(int j=0;j<S;++j)
        	cn[cur][j]+=cn[fail[cur]][j];
        for(int c=0;c<10;c++)
        {
            if(!ch[cur][c]) ch[cur][c]=ch[fail[cur]][c];
            else
            {
                fail[ch[cur][c]]=ch[fail[cur]][c];
                qs[t++]=ch[cur][c];
            }
        }
    }
    for(int i=1;i<=e;++i)
        for(int j=1;j<S;++j)
        	cn[i][j]+=cn[i][j-1];
}
void ins(string s,int d)
{
	reverse(s.begin(),s.end());
	while(s.back()=='0') s.pop_back();
	reverse(s.begin(),s.end());
	insert(s.c_str(),d);
}
void dfs(int d,bool o1,bool o2,string s)
{
	if((o1&&o2)||d==-1)
	{
		ins(s,d+1);
		return;
	}
	for(int c='0';c<='9';++c)
	{
		bool p1=o1,p2=o2;
		if(o1==0&&c<l[d]) continue;
		if(c>l[d]) p1=1;
		if(o2==0&&c>r[d]) continue;
		if(c<r[d]) p2=1;
		s.pb(c);
		dfs(d-1,p1,p2,s);
		s.pop_back();
	}
}
int f[2005][SZ],ii[2005][SZ],tr[2005][SZ];
pii js[2005][SZ];
int ts[SZ];
inline void cmax(int&a,int b) {if(a<b) a=b;}
int main()
{
	int n;
	scanf("%s%s%d",l,r,&n);
	go(l); go(r);
	dfs(S-1,0,0,"");
	bfail();
	memset(f,-127/3,sizeof f);
	f[0][rot]=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=e;++j) if(f[i-1][j]>=0)
			for(int k=0;k<=9;++k)
			{
				int v=f[i-1][j]+cn[ch[j][k]][min(n-i,S-1)];
				if(v<f[i][ch[j][k]]) continue;
				if(v>f[i][ch[j][k]]||
				pii(ii[i-1][j],k)<js[i][ch[j][k]])
					f[i][ch[j][k]]=v,
					js[i][ch[j][k]]=pii(ii[i-1][j],k),
					tr[i][ch[j][k]]=j;
			}
		vector<int> w[10];
		int mx=0,tn=0;
		for(int j=1;j<=e;++j) if(f[i][j]>=0)
			w[js[i][j].se].pb(j),mx=max(mx,js[i][j].fi),++tn;
		static int su[SZ];
		for(int i=0;i<=mx;++i) su[i]=0;
		for(int j=9;j>=0;--j)
			for(auto x:w[j]) ++su[js[i][x].fi];
		for(int i=1;i<=mx;++i) su[i]+=su[i-1];
		for(int j=9;j>=0;--j)
			for(auto x:w[j]) ts[su[js[i][x].fi]--]=x;
		int o=0;
		for(int j=1;j<=tn;++j)
		{
			if(j>1&&js[i][ts[j]]!=js[i][ts[j-1]]) ++o;
			ii[i][ts[j]]=o;
		}
	}
	pair<int,pii> aa;
	aa.fi=-1;
	for(int j=1;j<=e;++j)
		aa=max(aa,mp(f[n][j],mp(-ii[n][j],j)));
	printf("%d\n",aa.fi);
	int x=n,y=aa.se.se;
	string s;
	while(x)
	{
		s.pb(js[x][y].se+'0');
		y=tr[x--][y];
	}
	reverse(s.begin(),s.end());
	puts(s.c_str());
}