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
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=10010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>n;
    rep(i,1,n)
    cin>>a[i];
    int zd=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(zd<a[i])
        {
            zd=a[i];
        }
        if(i==zd)
        {
//            cout<<i<<' '<<zd<<endl;
            cnt++;
            zd=0;
        }
    }
    cout<<cnt<<endl;
    return 0;
}