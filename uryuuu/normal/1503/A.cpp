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

int a[maxn],b[maxn];
string s;
int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>s;
        int sa=0,sb=0;
        int f=0;
        for(int i=0;i<n;i++)
            a[i]=0;
        int m=n/2;
        int d=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                a[i]=d;
                d=-d;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
                sum++;
        }
        if(sum>m)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(a[i])
                continue;
            if(sum<m)
            {
                a[i]=1;
                sum++;
            }
            else
                a[i]=-1;
        }
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                b[i]=a[i];
            else
                b[i]=-a[i];
        }
        for(int i=0;i<n;i++)
        {
            sa+=a[i];
            if(sa<0)
                f=1;
        }
        for(int i=0;i<n;i++)
        {
            sb+=b[i];
            if(sb<0)
                f=1;
        }
        if(sa||sb||f)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
                cout<<'(';
            else
                cout<<')';
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(b[i]==1)
                cout<<'(';
            else
                cout<<')';
        }
        cout<<endl;
    }
    
    return 0;
}