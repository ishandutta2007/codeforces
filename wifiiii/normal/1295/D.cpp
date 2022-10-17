#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//random_device rng;
//mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'


ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
const int maxn = 1000005;
int prime[maxn],np[maxn],mu[maxn],tot=0;
void init()
{
    np[1]=1;mu[1]=1;
    for(int i=2;i<maxn;++i)
    {
        if(!np[i]) prime[++tot] = i, mu[i] = -1;
        for(int j=1;j<=tot;++j)
        {
            if(i*prime[j]>=maxn) break;
            np[i*prime[j]] = 1;
            mu[i*prime[j]] = -mu[i];
            if(i%prime[j]==0)
            {
                mu[i*prime[j]] = 0;
                break;
            }
        }
    }
}

int getmu(ll x) {
    if(x < maxn) return mu[x];
    int ret = 1;
    for(ll i=2;i*i<=x;++i) {
        if(x%i==0) {
            int c=0;
            while(x%i==0) {
                x/=i;
                c++;
            }
            if(c>1) return 0;
            ret = -ret;
        }
    }
    if(x>1) ret = -ret;
    return ret;
}
ll a,b;
ll get(ll x)
{
    ll g=gcd(a,b);
    ll tmp = b/g;
    ll ans = 0;
    ll tmp2 = x/g;
    for(ll i=1;i*i<=tmp;++i) {
        if(tmp % i == 0) {
            ans += getmu(i) * (tmp2/i);
            if(i != tmp / i) {
                ll j = tmp / i;
                ans += getmu(j) * (tmp2/j);
            }
        }
    }
    return ans;
}
int main()
{
    init();
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<get(a+b-1)-get(a-1)<<endl;
    }
}