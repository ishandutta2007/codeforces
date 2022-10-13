#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    deque<int> x;
    for(int i=0;i<n;i++)
        if(s[i]=='1') x.push_back(i);
    int arr[n];
    memset(arr,-1,sizeof(arr));
    for(int i=0;i<n;i++){
        if(!x.empty() && x.front()<i-k)
            x.pop_front();
        if(!x.empty() &&( (x.front()>=i && x.front()-k<=i)|| (x.front()<i && x.front()+k>=i)))
            arr[i] = x.front();
    }
    ll dp[n+1];
    for(int i=0;i<=n;i++) dp[i] = 1e12;
    dp[0] =0;
    for(int i=1;i<=n;i++){
        dp[i] = i+dp[i-1];
        if(arr[i-1]!=-1)
            dp[i] = min(dp[i],dp[max(1,arr[i-1]+1-k)-1]+arr[i-1]+1);
    }
    cout << dp[n] << endl;
}