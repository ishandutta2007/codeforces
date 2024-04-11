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
#define SZ 1234567
int ch[SZ][26],len[SZ],fail[SZ],s[SZ],cl,an,lst,sf[SZ],df[SZ];
int addn(int l) {len[an]=l; return an++;}
void init()
{
	cl=an=lst=0;
	//memset(ch,0,sizeof(ch));
	addn(0); addn(-1);
	fail[0]=1; s[0]=-233;
}
int gfail(int x,int l)
{
	while(s[l-len[x]-1]!=s[l]) x=fail[x];
	return x;
}
void add(int c)
{
	c-='a'; s[++cl]=c;
	int cp=gfail(lst,cl);
	if(!ch[cp][c])
	{
		int nn=addn(len[cp]+2);
		fail[nn]=ch[gfail(fail[cp],cl)][c];
		ch[cp][c]=nn;
	}
	lst=ch[cp][c]; df[lst]=len[lst]-len[fail[lst]];
	sf[lst]=(df[lst]==df[fail[lst]])?sf[fail[lst]]:fail[lst];
}
int ans[SZ],la[SZ];
const int MOD=1e9+7;
char str[SZ],sc[SZ];
int main()
{
	scanf("%s",str+1); init();
	int n=strlen(str+1),g=0;
	for(int i=1;i<=n+1-i;i++)
		sc[++g]=str[i],sc[++g]=str[n+1-i];
	ans[0]=1;
	for(int i=1;i<=n;++i)
	{
		add(sc[i]);
		for(int j=lst;len[j]>0;j=sf[j])
		{
			la[j]=ans[i-(len[sf[j]]+df[j])];
			if(sf[j]!=fail[j]) (la[j]+=la[fail[j]])%=MOD;
			if(i%2==0) (ans[i]+=la[j])%=MOD;
		}
	}
	printf("%d\n",ans[n]);
}