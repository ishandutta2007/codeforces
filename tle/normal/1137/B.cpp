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
char s[SZ+1]; int n;
void pre()
{
    n=strlen(s);
}
int next[SZ+3];
void gnext()
{
    next[0]=-1;
    int j=-1;
    for(int i=1;s[i];i++)
    {
        while(j!=-1&&s[i]!=s[j+1]) j=next[j];
        if(s[i]==s[j+1]) ++j;
        next[i]=j;
    }
}
}A;
char a[SZ],b[SZ];
int cnt[2];
int main()
{
	scanf("%s%s",a,b);
	for(int i=0;a[i];++i) ++cnt[a[i]-48];
	strcpy(A.s,b); A.pre();
	A.gnext();
	int l=A.n-A.next[A.n-1]-1;
	string s1=b,s2=s1.substr(s1.size()-l);
	int x[2],y[2];
	memset(x,0,sizeof x);
	memset(y,0,sizeof y);
	for(auto c:s1) ++x[c-48];
	for(auto c:s2) ++y[c-48];
	if(x[0]>cnt[0]||x[1]>cnt[1])
	{
		puts(a);
		return 0;
	}
	cnt[0]-=x[0]; cnt[1]-=x[1];
	printf("%s",s1.c_str());
	#define D(a,b) (b)?(a/b):int(2e9)
	int w=min(D(cnt[0],y[0]),D(cnt[1],y[1]));
	for(int j=1;j<=w;++j) printf("%s",s2.c_str());
	cnt[0]-=y[0]*w;
	cnt[1]-=y[1]*w;
	while(cnt[0]--) putchar('0');
	while(cnt[1]--) putchar('1');
	puts("");
}