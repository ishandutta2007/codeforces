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
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=2000010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

int a[maxn],d[maxn];
int mp[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cout<<"XOR "<<i<<' '<<i+1<<endl;
        cin>>d[i];
    }
    a[1]=0;
    int p;
    mp[a[1]/2]=1;
    int pos;
    for(int i=2;i<=n;i++)
    {
        a[i]=a[i-1]^d[i-1];
    }
    for(int i=2;i<=n;i++)
    {
        if(mp[a[i]/2])
        {
            p=mp[a[i]/2];
            pos=i;
            break;
        }
        mp[a[i]/2]=i;
    }
    if(a[p]==a[pos])
    {
        cout<<"AND "<<p<<' '<<pos<<endl;
        cin>>a[p];
        for(int i=p-1;i>=1;i--)
        {
            a[i]=a[i+1]^d[i];
        }
        for(int i=p+1;i<=n;i++)
        {
            a[i]=a[i-1]^d[i-1];
        }
        cout<<"!";
        for(int i=1;i<=n;i++)
        {
            cout<<" "<<a[i];
        }
        cout<<endl;
        return 0;
    }
    
    
    
    int x;
    cout<<"AND "<<p<<' '<<pos<<endl;
    cin>>x;
    int ppos=0;
    for(int i=1;i<=n;i++)
    {
        if(i==p)
            continue;
        if(a[i]%2==a[p]%2)
        {
            ppos=i;
            break;
        }
    }
//    for(int i=1;i<=n;i++)
//        cout<<a[i]<<' ';
//    cout<<endl;
    if(ppos==0)
    {
        p=pos;
        for(int i=1;i<=n;i++)
        {
            if(i==p)
                continue;
            if(a[i]%2==a[p]%2)
            {
                ppos=i;
                break;
            }
        }
    }
    
    
    int y;
    cout<<"AND "<<p<<' '<<ppos<<endl;
    cin>>y;
    a[p]=x/2*2+y%2;
    for(int i=p-1;i>=1;i--)
    {
        a[i]=a[i+1]^d[i];
    }
    for(int i=p+1;i<=n;i++)
    {
        a[i]=a[i-1]^d[i-1];
    }
    cout<<"!";
    for(int i=1;i<=n;i++)
    {
        cout<<" "<<a[i];
    }
    cout<<endl;
    return 0;
}