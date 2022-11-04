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
const int maxn=500010;
//const ll Mod=1000000007;
const ll Mod=998244353;

int a[maxn];
int ans[maxn];

int main()
{
    sync;
//    int n;
//    cin>>n;
//    for(int i=1;i<=n;i++)
//    {
//        a[i]=i;
//    }
//    do
//    {
//        for(int i=1;i<=n;i++)
//        {
//            cout<<a[i]<<' ';
//        }
//        cout<<' ';
//        int ss=0;
//        for(int k=0;k<n;k++)
//        {
//            int mx=0,sum=0;
//            for(int i=1;i<=n;i++)
//            {
//                if(a[(i-k-1+n+n)%n+1]>mx)
//                {
//                    mx=a[(i-k-1+n+n)%n+1];
//                    sum++;
//                }
//            }
//            ans[k]=sum;
//            cout<<sum<<' ';
////            ss+=sum;
//        }
//        for(int k=1;k<n;k++)
//            ss+=abs(a[k]-a[k-1]);
//        ss+=abs(a[0]-a[n-1]);
//        cout<<ss<<endl;
////        if(ans[0]==2&&ans[1]==3&&ans[2]==1&&ans[3]==2)
////            cout<<"FUCK";
////        cout<<endl;
//    }while(next_permutation(a+1,a+n+1));
//
//
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int fl=0;
        int mn=n;
        for(int i=1;i<=n;i++)
        {
            mn=min(mn,a[i]);
        }
        if(mn!=1)
            fl=1;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
                sum++;
        }
        if(sum!=1)
            fl=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]-a[i-1]>1)
                fl=1;
        }
        if(a[1]-a[n]>1)
            fl=1;
        if(fl)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}