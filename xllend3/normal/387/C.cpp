#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for (int i = a; i <= (int)n; ++i)
#define dep(i,a,n) for (int i = a; i >= (int)n; --i)
#define re(b,a) for(a::iterator it=b.begin();it!=b.end();++it)
#define clr(a,b) memset(a,sizeof(a),b);
#define inf 0x7fffffff
#define eps 1e-8
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
inline void read(int &n)
{
    char c;
    for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar());
    n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int l,m,n,t,a[111111];
char s[111111];
int mall(int x,int y){rep(i,0,n)
{if(y+i>=x||x+i>n)break;
if(a[i+x]<a[i+y])return 1;
if(a[i+x]>a[i+y])return 0;}return 1;}
int main()
{
    scanf("%s",s+1);n=strlen(s+1);rep(i,1,n)a[i]=s[i]-'0';
    int k=n,ans=0,j;
    while(k>0)
    {
        dep(i,k,0)if(a[i]){j=i;break;}
        if(k-j+1<j-1||k-j+1==j-1&&mall(j,1)){ans++;k=j-1;}
        else {ans++;break;}
    }printf("%d\n",ans);
    return 0;
}