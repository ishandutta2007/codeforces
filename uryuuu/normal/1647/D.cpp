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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1010;
const ll Mod=1000000007;
//const ll Mod=998244353;



int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int x,d;
        int sum=0;
        cin>>x>>d;
//        cout<<x<<' '<<d<<' ';
        while(x%d==0)
        {
            sum++;
            x/=d;
        }
//        cout<<sum<<' '<<x<<endl;
        if(sum==1)
        {
            cout<<"NO\n";
        }
        else if(sum==2)
        {
            int fl=0;
            for(int i=2;i<x;i++)
            {
                if(x%i==0)
                {
                    fl=1;
                    break;
                }
                if(i*i>x)
                    break;
            }
            if(fl)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else if(sum==3)
        {
            int fl=0;
            for(int i=2;i<x;i++)
            {
                if(x%i==0)
                {
                    fl=1;
                    break;
                }
                if(i*i>x)
                    break;
            }
            
            if(fl==0)
            {
                for(int i=2;i<d;i++)
                {
                    if(d%i==0&&((i*x)%d||(d/i*x)%d))
                    {
                        fl=1;
                        break;
                    }
                    if(i*i>d)
                        break;
                }
            }
            if(fl)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            int fl=0;
            for(int i=2;i<x;i++)
            {
                if(x%i==0)
                {
                    fl=1;
                    break;
                }
                if(i*i>x)
                    break;
            }
            
            if(fl==0)
            {
                for(int i=2;i<d;i++)
                {
                    if(d%i==0)
                    {
                        fl=1;
                        break;
                    }
                    if(i*i>d)
                        break;
                }
            }
            if(fl)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    
    return 0;
}