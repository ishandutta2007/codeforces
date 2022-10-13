#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,int> low;
map<ll,ll> high;
ll p[105];
ll mod = 969238902368L;
ll getHash(vector<int> &nums){
    ll res = 0;
    ll pow = 1;
    for(int i=0;i<nums.size();i++){
        res = (res+(pow*nums[i])%mod)%mod;
        pow = (pow*137)%mod;
    }
    return res;
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<105;i++)
        p[i] = rand()%100000023;
    int val[n];
    int cnt[n];
    vector<int> nums;
    nums.assign(n-1,0);
    for(int j=0;j<(1<<15);j++){
        for(int i=0;i<n;i++)
            val[i] = a[i]^j;
        for(int i=0;i<n;i++)
            cnt[i] = 0;
        for(int i=0;i<n;i++)
            for(int k=0;k<15;k++)
                if(val[i]&(1<<k)) cnt[i]++;
        for(int x=1;x<n;x++)
            nums[x-1]=(cnt[0]-cnt[x]);
        low[getHash(nums)] = j+1;
    }
    for(int j=0;j<(1<<15);j++){
        for(int i=0;i<n;i++)
            val[i] = a[i]^(j*(1<<15));
        for(int i=0;i<n;i++)
            cnt[i] = 0;
        for(int i=0;i<n;i++)
            for(int k=15;k<30;k++)
                if(val[i]&(1<<k)) cnt[i]++;
        for(int x=1;x<n;x++)
            nums[x-1]=(cnt[0]-cnt[x]);
        high[-getHash(nums)] = j*1LL*(1<<15)+1;
    }
    int ans = 0;
    for(auto &it : low){
              
        if(high[it.first]>0){
            ans =it.second+high[it.first]-2;
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}