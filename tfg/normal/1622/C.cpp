#include <bits/stdc++.h>

using namespace std;

void solve(){
  long long n,k,sum=0,second=0,ans=INT_MAX;
  cin>>n>>k;
  vector<long long> inp(n,0);
  for (long long i = 0; i < n; i++)
  {
    cin>>inp[i];
    sum+=inp[i];
  }
  if(sum<=k){
    cout<<0<<endl;
    return;
  }
  sort(inp.begin(),inp.end());
  long long first = inp[0];
  inp[0]=0;
  for (long long i = 0; i < n; i++)
  {
    second+=inp[i];
    long long temp=0;
    temp = floor(((double)k-second)/(n-i));
    if(temp<=first){ 
      ans = min(ans,((first-temp)+n-i-1));
    }
    else ans=min(ans,(n-i-1));
  }
  cout<<ans<<endl;
  return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int t=1;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}