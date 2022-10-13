#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
int n;
ll mod = 1000000007;
ll fact[1000001];
ll inv(ll b, ll p=mod-2) {
    if(p==0) return 1;
    ll x = inv(b,p/2);
    if(p%2) {return ((((x*x)%mod)*b)%mod+mod)%mod;}
    else {return (((x*x)%mod+mod)%mod);}
}
ll choose(int i,int j) {
    if(j==0) return 1;
    ll x = fact[i];
    ll y = fact[i-j];
    ll z = fact[j];
    ll a = inv(y), b = inv(z);
    return ((x*1LL*a)%mod*1LL*b%mod);
}
ll get(vector<int> &nums) {
    bool mark[n+1];
    memset(mark,false,sizeof(mark));
    int f[nums.size()];
    memset(f,0,sizeof(f));
    for(int i=0;i<nums.size();i++) {
        for(int j=1;j<=n;j++) {
            if(!mark[j] && j%nums[i]==0) {
                mark[j] = 1;
                ++f[i];
            }
        }
    }
    ll ans = 1;
    ll left = n;
    for(int i=0;i<nums.size();i++) {
        ans*=(choose(left-1,f[i]-1)%mod*1LL*fact[f[i]]%mod);
        ans%=mod;
        left-=f[i];
    }
    return ans;
}
int main() {
    cin >> n;
    vector<int> nums;
    nums.push_back(1);
    while(nums[nums.size()-1]*2<=n) {
        nums.push_back(nums[nums.size()-1]*2);
    }
    reverse(nums.begin(),nums.end());
    fact[0] = 1;
    for(int i=1;i<=1000000;i++) fact[i] = fact[i-1]*1LL*i%mod;
    ll ans = get(nums);
    if(nums[0]*3/2<=n) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i]%2==0) {
                nums[i]/=2;
                nums[i]*=3;
                ans+=get(nums);
                ans%=mod;
            }
        }
    }
    if(ans<0) ans+=mod;
    cout << ans << endl;
}