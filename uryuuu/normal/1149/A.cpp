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
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod = 998244353;
#define eps 1e-10



int main()
{
    sync;
    int t;
    int n;
    int a=0,b=0;
    cin>>n;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x==1)
            a++;
        else
            b++;
    }
    if(a%2==0)
    {
        if(b>0)
        {
            cout<<2<<' ';
            b--;
        }
        for(int i=1;i<=a-1;i++)
            cout<<1<<' ';
        for(int i=1;i<=b;i++)
            cout<<2<<' ';
        if(a)
            cout<<1<<endl;
    }
    else
    {
        if(b>0)
        {
            cout<<2<<' ';
            b--;
        }
        for(int i=1;i<=a;i++)
            cout<<1<<' ';
        for(int i=1;i<=b;i++)
            cout<<2<<' ';
        cout<<endl;
    }
    
    
    return 0;
}