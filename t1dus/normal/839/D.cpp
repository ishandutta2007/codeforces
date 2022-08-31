#include<bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1000000007;
int n;
int cnt[1000005];
int a[200005];
int ans[1000005];
int power[200005];

signed main(){
  
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++) cnt[i] = 0;
  power[0] = 1;
  for(int i = 0; i < n; i ++){
    cin >> a[i];
    power[i+1] = (power[i]*2)%MOD;
    for(int j = 1; j*j <= a[i]; j++){
      if(a[i]%j == 0){
        cnt[j] ++;
        if(j*j != a[i]) cnt[a[i]/j]++;
      }
    }
  }
  int res = 0;
  for(int i = 1000000; i >= 2; i --){
    ans[i] = (cnt[i]*power[cnt[i]-1])%MOD;
    for(int j = 2; i*j <= 1000000; j ++){
      ans[i] -= ans[i*j];
      ans[i] += MOD;
      ans[i] %= MOD;
    }
    res += ans[i]*i;
    res %= MOD;
  }
  cout << res << endl;
}