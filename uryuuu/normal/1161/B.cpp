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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;
//typedef pair<pii,int> piii;

map<pii,int>mp;
struct node
{
    int u,v;
}a[maxn];

int n,m;

int solve(int x)
{
    int u,v;
    for(int i=1;i<=m;i++)
    {
        u=(a[i].u+x)%n;
        v=(a[i].v+x)%n;
        if(u>v)
            swap(u,v);
        if(mp[mkp(u,v)]==0)
            return 0;
    }
    return 1;
}


int main()
{
    sync;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v;
        a[i].u--;
        a[i].v--;
        if(a[i].u>a[i].v)
            swap(a[i].u,a[i].v);
        mp[mkp(a[i].u,a[i].v)]++;
    }
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {
            if(solve(i))
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    
    
    return 0;
}