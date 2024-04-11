#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int inv2=(p+1)/2;
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
const int maxn=3e5+5;
int fact[maxn];int invf[maxn];
int c(int n,int k) {if(k<0 || k>n || n<0) return 0; int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;return ans;}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;for(int i=1;i<maxn;++i) {fact[i]=(fact[i-1]*i)%p;} for(int i=0;i<maxn;++i) invf[i]=inv(fact[i]);
    int t;cin>>t;
    int dp[maxn];dp[0]=1;dp[1]=1;for(int i=2;i<maxn;++i) {dp[i]=dp[i-1]+(i-1)*dp[i-2];dp[i]%=p;}
    while(t--)
    {
        int n;cin>>n;int ans=0;
        #ifdef LOCAL
        vector<int> v(n);iota(v.begin(),v.end(),0);
        int ans1=0;
        while(true)
        {
            vector<int> v2(n);for(int i=0;i<n;++i) v2[v[i]]=i;
            bool ok=true;
            for(int i=0;i<n;++i)
            {
                ok=(ok && abs(v[i]-v2[i])<=1);
            }
            ans1+=ok;
            if(!next_permutation(v.begin(),v.end())) break;
        }
        cout<<ans1<<" ans1 "<<endl;
        #endif
        for(int k=0;k<=n;k+=4)
        {
            int o=c(n-k/2,k/2);
            o*=fact[k/2];o%=p;o*=invf[k/4];o%=p;
            o*=dp[n-k];o%=p;ans+=o;ans%=p;
        }
        cout<<(ans%p+p)%p<<'\n';
    }
    return 0;
}