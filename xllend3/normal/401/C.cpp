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
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define dep(i,a,n) for (int i = a; i >= n; --i)
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
int l,m,n,t,l1,l2;
int main()
{
    scanf("%d%d",&n,&m);l1=l2=-1;
    if(m>n){
        if(m>2*n+2){puts("-1");return 0;}
        while(m-1>n&&m>2){
            printf("110");m-=2;n--;
        }
        if(m<3){rep(i,1,m)printf("1");rep(i,1,n)printf("0");return 0;}
        rep(i,1,min(m,n))printf("10");if(m!=n)puts("1");
    }else{
        if(n-m>1){puts("-1");return 0;}
        rep(i,1,min(m,n))printf("01");if(m!=n)puts("0");
    }
    return 0;
}