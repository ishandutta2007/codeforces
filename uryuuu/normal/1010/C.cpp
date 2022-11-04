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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

bool dp[maxn];
int a[maxn],b[maxn];
int gcd(int a,int b)
{
    if(a==0)
        return 1;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}


int main()
{
    sync;
    int n;
    int k;
    cin>>n>>k;
    int cnt=k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=a[i]%k;
        if(a[i]==0)
        {
            a[i]=k;
        }
        cnt=gcd(cnt,a[i]);
    }
//    cout<<cnt<<endl;
    cout<<k/cnt<<endl;
    for(int i=0;i<k;i+=cnt)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    return 0;
}