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
char s[SZ]; int n;
int main()
{
	scanf("%s",s+1); n=strlen(s+1);
	int ca=0,cp=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		if(cp==s[i]) ca=0;
		cp=s[i]; ans=max(ans,++ca);
	}
	if(s[1]!=s[n])
	{
		int i,ca=0;
		for(i=1;i<=n;++i)
		{
			if(i!=1&&s[i]==s[i-1]) break;
			++ca;
		}
		for(int j=n;j>=i;--j)
		{
			if(i!=n&&s[j]==s[j+1]) break;
			++ca;
		}
		ans=max(ans,ca);
	}
	printf("%d\n",ans);
}