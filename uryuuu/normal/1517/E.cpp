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

ll a[maxn];
ll pre[2][maxn];
ll pr[maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll ans=0ll;
        ll sum=0ll;
        
        for(int i=0;i<=n;i++)
        {
            pre[0][i]=0ll;
            pre[1][i]=0ll;
        }
        
        
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pre[i%2][i]=a[i];
            sum+=a[i];
            pr[i]=a[i];
        }
        
        if(sum%2ll)
            sum=sum/2ll;
        else
            sum=sum/2ll-1ll;
        for(int i=1;i<=n;i++)
        {
            pre[0][i]+=pre[0][i-1];
            pre[1][i]+=pre[1][i-1];
            pr[i]+=pr[i-1];
        }
        
        ll s;
        int lmt;
        int pos;
        int k;
        
        lmt=n-3;
        for(int i=3;i<=lmt;i++)
        {
            s=0ll;
            s+=a[n];
            s+=pr[i]-a[1];
            if(s>sum)
                break;
            k=i%2;
            pos=upper_bound(pre[k]+i+1,pre[k]+lmt+1,sum-s+pre[k][i])-pre[k]-1;
            if(pos%2!=k)
                pos--;
            ans=(1ll*ans+(1ll*(pos-i)/2ll+1ll))%Mod;
//            cout<<"PCCPCPPC"<<' '<<i<<' '<<(1ll*(pos-i)/2ll+1ll)<<endl;
        }
        
        lmt=n;
        for(int i=3;i<=lmt;i++)
        {
            s=0ll;
            s+=pr[i]-a[1];
            if(s>sum)
                break;
            k=i%2;
            pos=upper_bound(pre[k]+i+1,pre[k]+lmt+1,sum-s+pre[k][i])-pre[k]-1;
            if(pos%2!=k)
                pos--;
            ans=(1ll*ans+(1ll*(pos-i)/2ll+1ll))%Mod;
//            cout<<"PCCPCPP"<<' '<<i<<' '<<(1ll*(pos-i)/2ll+1ll)<<endl;
        }
        
        lmt=n-3;
        for(int i=0;i<=lmt;i++)
        {
            s=0ll;
            s+=a[n];
            s+=pr[i];
            if(s>sum)
                break;
            k=i%2;
            pos=upper_bound(pre[k]+i+1,pre[k]+lmt+1,sum-s+pre[k][i])-pre[k]-1;
            if(pos%2!=k)
                pos--;
            ans=(1ll*ans+(1ll*(pos-i)/2ll+1ll))%Mod;
//            cout<<"CCPCPPC"<<' '<<i<<' '<<(1ll*(pos-i)/2ll+1ll)<<endl;
        }
        
        lmt=n;
        for(int i=0;i<=lmt;i++)
        {
            s=0ll;
            s+=pr[i];
            if(s>sum)
                break;
            k=i%2;
            pos=upper_bound(pre[k]+i+1,pre[k]+lmt+1,sum-s+pre[k][i])-pre[k]-1;
            if(pos%2!=k)
                pos--;
            ans=(1ll*ans+(1ll*(pos-i)/2ll+1ll))%Mod;
//            cout<<"CCPCPP"<<' '<<i<<' '<<(1ll*(pos-i)/2ll+1ll)<<endl;
        }
        
        for(int i=n-2;i>=2;i--)
        {
            s=pr[n]-pr[i];
            if(s>sum)
                break;
            ans++;
        }
        
        cout<<(ans%Mod+Mod)%Mod<<endl;
    }
    
    return 0;
}