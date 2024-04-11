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
const int maxn=4005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int mn,mx;
        cin>>n;
        cin>>mn>>mx;
        int R=n;
        int Mn=999,Mx=0;
        for(int i=1;i<n/2;i++)
        {
            while(R==mn||R==mx)
            {
                R--;
            }
            a[i]=R;
            Mn=min(Mn,R);
            R--;
        }
        a[n/2]=mn;
        a[n/2+1]=mx;
        int L=1;
        for(int i=n/2+2;i<=n;i++)
        {
            while(L==mn||L==mx)
            {
                L++;
            }
            a[i]=L;
            Mx=max(Mx,L);
            L++;
        }
        if(mn>Mn||mx<Mx)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}