#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
int a[100001];
    int freq[11];
    int dig[100001];

ll get(int i,int b){
    //a[i] left
    vector<int> digits;
    int temp = a[i];
    while(temp>0){
        digits.push_back(temp%10);
        temp/=10;
    }
    ll x = 0;
    if(b>=dig[i]){
        for(int i=0;i<digits.size();i++){
            x+=pow(10,2*i)*1LL*digits[i];
            x%=mod;
        }
        x*=11;
        return x%mod;
    }
    else{
        for(int i=0;i<b;i++){
            x+=pow(10,2*i)*1LL*digits[i];
            x%=mod;
        }
        x*=11;
        ll y = 0;
        for(int i=b;i<digits.size();i++){
            y+=pow(10,b+i)*1LL*digits[i];
        }
        y*=2;
        return (x+y)%mod;

    }
}
int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        int temp = a[i];
        while(temp>0){
            temp/=10;
            ++dig[i];
        }
        ++freq[dig[i]];
    }
    ll ans=  0;
    for(int i=0;i<n;i++){
        for(int j=1;j<11;j++){
            ll add = get(i,j);
            add*=freq[j];
            ans+=add;
            ans%=mod;
        }
    }
    if(ans<0) ans+=mod;
    cout << ans << endl;
}