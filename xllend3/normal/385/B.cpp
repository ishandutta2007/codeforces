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
int l,m,n,t,a[5555],ans;
char s[5555];
int main()
{
    scanf("%s",s+1);n=strlen(s+1);
    rep(i,1,n-3)
    {
        a[i]=1;if(s[i]!='b'||s[i+1]!='e'||s[i+2]!='a'||s[i+3]!='r')a[i]=0;
    }
    rep(i,1,n-3)
    {
        bool bo=0;rep(j,i+3,n){if(a[j-3])bo=1;if(bo)++ans;}
    }printf("%d\n",ans);
    return 0;
}