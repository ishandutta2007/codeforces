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
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;

string s;

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cin>>s;
        n=a+b;
        int sa=0,sb=0;
        if(n%2)
        {
            int mid=n/2;
            if(a%2&&s[mid]=='1')
            {
                cout<<-1<<endl;
                continue;
            }
            if(b%2&&s[mid]=='0')
            {
                cout<<-1<<endl;
                continue;
            }
            
            if(a%2)
                s[mid]='0';
            else
                s[mid]='1';
        }
        else
        {
            if(a%2)
            {
                cout<<-1<<endl;
                continue;
            }
        }
        
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(s[n-1-i]=='1')
                {
                    f=1;
                    break;
                }
                s[n-1-i]='0';
            }
            else if(s[i]=='1')
            {
                if(s[n-1-i]=='0')
                {
                    f=1;
                    break;
                }
                s[n-1-i]='1';
            }
        }
        if(f)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                sa++;
            if(s[i]=='1')
                sb++;
        }
        if(sa>a||sb>b)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                if(sa<a)
                {
                    s[i]='0';
                    s[n-1-i]='0';
                    sa+=2;
                }
                else
                {
                    s[i]='1';
                    s[n-1-i]='1';
                    sb+=2;
                }
            }
        }
        cout<<s<<endl;
        
    }
    
    return 0;
}