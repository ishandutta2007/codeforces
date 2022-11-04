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
const int maxn=1000005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn],b[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll len;
        cout<<"? "<<1<<' '<<n<<endl;
        cin>>len;
        ll l,r,mid,ansL,x;
        l=1;r=n;ansL=1;
        while(l<r)
        {
            mid=(l+r)/2;
            cout<<"? "<<mid<<' '<<n<<endl;
            cin>>x;
            if(x==len)
            {
                ansL=max(ansL,mid);
                l=mid+1;
            }
            else
                r=mid;
        }
        cout<<"? "<<l<<' '<<n<<endl;
        cin>>x;
        if(x==len)
            ansL=max(ansL,l);
        
        ll ansmid,ansR;
        cout<<"? "<<ansL+1<<' '<<n<<endl;
        cin>>x;
        ansmid=ansL+len-x+1;
        cout<<"? "<<ansmid<<' '<<n<<endl;
        cin>>len;
        cout<<"? "<<ansmid+1<<' '<<n<<endl;
        cin>>x;
        ansR=ansmid+len-x;
        cout<<"! "<<ansL<<' '<<ansmid<<' '<<ansR<<endl;
            
    }
    return 0;
}