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
int l,m,n,t,a[4444],b[4444],tot,k,Min,Max;
int main()
{
    scanf("%d%d",&m,&n);tot=m-1;rep(i,1,n){
        scanf("%d",&t);
        if(t==1)scanf("%d%d",&l,&k),a[l]=a[k]=1;
        else scanf("%d",&l),a[l]=1;
    }
    Min=Max=0;a[m]=1;
    rep(i,1,m-1)if(a[i])continue;else{if(!a[i+1])Min++,Max+=2,i++;else Min++,Max++;}
    printf("%d %d\n",Min,Max);
    return 0;
}