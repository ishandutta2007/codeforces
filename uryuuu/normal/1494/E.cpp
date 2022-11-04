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
#include <chrono>
#include <random>
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
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;
//const ll Mod=998244353;

map<pii,int>mp;
char op,c;

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int u,v,w;
    int s1=0,f=0;
    int a,b,k;
    while(m--)
    {
        cin>>op;
        if(op=='+')
        {
            cin>>u>>v>>c;
            w=ch(c);
            mp[mkp(u,v)]=w;
            a=mp[mkp(u,v)];
            b=mp[mkp(v,u)];
            if(b)
            {
                if(a==b)
                {
                    s1++;
                }
                f++;
            }
        }
        else if(op=='-')
        {
            cin>>u>>v;
            a=mp[mkp(u,v)];
            b=mp[mkp(v,u)];
            if(b)
            {
                if(a==b)
                {
                    s1--;
                }
                f--;
            }
            mp[mkp(u,v)]=0;
        }
        else
        {
            cin>>k;
            if(s1)
            {
                cout<<"YES"<<endl;
                continue;
            }
            if(f&&k%2)
            {
                cout<<"YES"<<endl;
                continue;
            }
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}