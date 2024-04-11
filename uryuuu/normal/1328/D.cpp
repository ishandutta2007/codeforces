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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

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
        for(int i=1;i<=n;i++)
            cin>>a[i];
        b[1]=1;
        int f=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]!=a[i-1])
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<1<<endl;
            rep(i,1,n)
            cout<<1<<' ';
            cout<<endl;
            continue;
        }
        f=0;
        if(n%2==0)
        {
            cout<<2<<endl;
            for(int i=1;i<=n/2;i++)
                cout<<1<<' '<<2<<' ';
            cout<<endl;
            continue;
        }
        b[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1]&&f==0)
            {
                b[i]=b[i-1];
                f=1;
                continue;
            }
            b[i]=3-b[i-1];
        }
        if(f==1||a[1]==a[n]||n<=2)
        {
            cout<<2<<endl;
            rep(i,1,n)
            cout<<b[i]<<' ';
            cout<<endl;
            continue;
        }
        cout<<3<<endl;
        rep(i,1,n-1)
        cout<<b[i]<<' ';
        cout<<3<<endl;
        
        
    }
    return 0;
}