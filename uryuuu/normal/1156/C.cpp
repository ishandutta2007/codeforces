#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;



ll n,z;
ll a[maxn];
int v[maxn];

int main()
{
    sync;
    cin>>n>>z;
    rep(i,1,n)
    cin>>a[i];
    sort(a+1,a+1+n);
    int sum=0;
    mm(v);
    int L=1;
    int R=1+n/2;
    while(L<=n)
    {
        while(v[L]&&L<=n+1)
            L++;
        while((a[R]<a[L]+z||v[R])&&R<=n+1)
            R++;
        if(L>n||R>n)
            break;
        sum++;
        v[L]=v[R]=1;
        L++;
        R++;
    }
    cout<<sum<<endl;
    return 0;
}