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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn];
string s;
int ans[maxn];
map<int,int>mp;

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
        {
            cin>>a[i];
        }
        if(n%2==0)
        {
            for(int i=1;i<=n;i+=2)
            {
                cout<<-1*a[i+1]<<' '<<a[i]<<' ';
            }
            cout<<endl;
        }
        else
        {
            if(n<=60000)
            {
                for(int i=1;i<=n-3;i+=2)
                {
                    cout<<-1*a[i+1]<<' '<<a[i]<<' ';
                }
                cout<<a[n-1]*a[n]<<' '<<-2*a[n]*a[n-2]<<' '<<a[n-1]*a[n-2]<<endl;
            }
            else
            {
                for(int i=1;i<=n;i++)
                    ans[i]=0;
                mp.clear();
                int id=1;
                for(int i=1;i<=n;i++)
                {
                    mp[a[i]]++;
                    if(mp[a[i]]>mp[id])
                        id=a[i];
                }
                
                int s=0;
                for(int i=1;i<=n;i++)
                {
                    if(s>=3)
                        break;
                    if(a[i]==id)
                    {
                        s++;
                        if(s<=2)
                            ans[i]=1;
                        else
                            ans[i]=-2;
                    }
                }
                int L=1,R;
                while(L<=n)
                {
                    while(ans[L])
                        L++;
                    R=L+1;
                    while(ans[R])
                        R++;
                    ans[R]=a[L];
                    ans[L]=-a[R];
                    L=R+1;
                    while(ans[L]&&L<=n)
                        L++;
                }
                for(int i=1;i<=n;i++)
                    cout<<ans[i]<<' ';
                cout<<endl;
            }
        }
    }
    return 0;
}