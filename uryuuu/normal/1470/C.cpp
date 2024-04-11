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
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;


int b[maxn];
int a[maxn];
int s;
int query(int x)
{
    cout<<'?'<<' '<<x+1<<endl;
    cin>>s;
    return s;
}

int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    int sq=(int)sqrt(n)-1;
    for(int i=0;i<sq;i++)
    {
        query(i);
    }
    int x=0;
    int v=query(x);
    while(v==k)
    {
        x=(x+sq)%n;
        v=query(x);
    }
    if(v<k)
    {
        while(query((x+sq)%n)<k)
            x=(x+sq)%n;
        while(query((x+1)%n)<k)
            x=(x+1)%n;
        x=(x+1)%n;
    }
    else
    {
        while(query((x-sq+n)%n)>k)
            x=(x-sq+n)%n;
        while(query((x-1+n)%n)>k)
            x=(x-1+n)%n;
        x=(x-1+n)%n;
    }
    cout<<"! "<<x+1<<endl;
    
    return 0;
}