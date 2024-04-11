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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;




int a[205];


int main()
{
    sync;
    int t;
    ll n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(n%2&&(k%2==0))
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(n%2)
        {
            if(n<k)
            {
                cout<<"NO"<<endl;
                continue;
            }
            else
            {
                cout<<"YES"<<endl;
                cout<<n-k+1<<' ';
                for(int i=1;i<k;i++)
                    cout<<1<<' ';
                cout<<endl;
                continue;
            }
        }
        else
        {
            if(k%2==0)
            {
                if(n<k)
                {
                    cout<<"NO"<<endl;
                    continue;
                }
                else
                {
                    cout<<"YES"<<endl;
                    cout<<n-k+1<<' ';
                    for(int i=1;i<k;i++)
                        cout<<1<<' ';
                    cout<<endl;
                    continue;
                }
            }
            else
            {
                if(n<2ll*k)
                {
                    cout<<"NO"<<endl;
                    continue;
                }
                else
                {
                    cout<<"YES"<<endl;
                    cout<<n-2ll*k+2ll<<' ';
                    for(int i=1;i<k;i++)
                        cout<<2<<' ';
                    cout<<endl;
                    continue;
                }
            }
        }
    }
    
    
    
    return 0;
}