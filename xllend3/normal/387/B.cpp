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
int l,m,n,t,a[1111111],b[1111111],ans;
int main()
{
    scanf("%d%d",&m,&n);rep(i,1,m)scanf("%d",&a[i]);
    rep(i,1,n)scanf("%d",&b[i]);sort(a+1,a+1+m);sort(b+1,b+1+n);
    int j=1;
    rep(i,1,m){
        while(j<=n&&b[j]<a[i])++j;if(j>n){printf("%d\n",m+1-i);return 0;}++j;
    }printf("%d\n",0);
    return 0;
}