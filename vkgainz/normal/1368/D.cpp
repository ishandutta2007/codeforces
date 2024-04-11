#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> nums;
    nums.assign(n,0);
    int cnt[21];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
        for(int j=0;j<21;j++)
            if(a[i]&(1<<j)) ++cnt[j];
    }
    for(int i=0;i<21;i++){
        for(int j=0;j<cnt[i];j++){
            nums[j]+=(1<<i);
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans+=nums[i]*1LL*nums[i];
    }
    cout << ans << endl;
}