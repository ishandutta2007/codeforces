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
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=5000005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn];
int mp[maxn];
int b[maxn];
int c[maxn];

int main()
{
//    sync;
    int t;
//    cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
//        cin>>n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]=a[i]+4000000;
        }
        sort(a+1,a+n+1);
        int mid=n/2;
        int f=0;
        for(int i=mid;i<=n;i++)
        {
            if(a[i]==a[i-mid+1])
            {
                f=1;
            }
        }
        if(f)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
            c[i]=a[i];
        int m=unique(c+1,c+n+1)-c-1;
        
        int j,x,cnt=0;
        int k;
        for(int i=1;i<=m;i++)
        {
            for(j=i+1;j<=m;j++)
            {
                x=c[j]-c[i];
                for(k=1;k*k<=x;k++)
                {
                    if(x%k==0)
                    {
                        b[++cnt]=k;
                        b[++cnt]=x/k;
                    }
                }
            }
        }
        sort(b+1,b+cnt+1);
        cnt=unique(b+1,b+cnt+1)-b-1;
        
        
        int v;
        int mx=0;
        int ans=1;
        for(int i=cnt;i>=2;i--)
        {
            v=b[i];
            mx=0;
            for(j=1;j<=n;j++)
            {
                x=a[j]%v;
                mp[x]++;
                if(mp[x]>mx)
                {
                    mx=mp[x];
                }
            }
            for(j=1;j<=n;j++)
            {
                x=a[j]%v;
                mp[x]--;
            }
            
            if(mx>=mid)
            {
                ans=v;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}