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
bool oo[26],ha[26];
char s[3],bb[233333];
int main()
{
	scanf("%d",&n);
	int ext=0,did=0;
	while(n--)
	{
		scanf("%s",s);
		memset(ha,0,sizeof ha);
		if(s[0]!='.'&&did) ++ext;
		scanf("%s",bb);
		if(did) continue;
		if(s[0]=='?') oo[bb[0]-'a']=1;
		else
		{
		for(int i=0;bb[i];++i)
			ha[bb[i]-'a']=1;
		for(int i=0;i<26;++i)
			if(ha[i]!=(s[0]=='!')) oo[i]=1;
		}
		int e=0;
		for(int i=0;i<26;++i) e+=!oo[i];
		if(e==1) did=1;
	}
	printf("%d\n",max(ext-1,0));
}