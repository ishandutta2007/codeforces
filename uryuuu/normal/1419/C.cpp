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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,ll> pii;
const double pi=acos(-1);
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod = 998244353;
//#define int long long

string s;
int a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        int sum=0;
        cin>>n>>x;
        int f=0;
        int ff=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            if(a[i]!=x)
                f=1;
            else
                ff=1;
        }
        if(f==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(ff==1)
        {
            cout<<1<<endl;
            continue;
        }
        if(sum==n*x)
        {
            cout<<1<<endl;
            continue;
        }
        cout<<2<<endl;
    }
    return 0;
}