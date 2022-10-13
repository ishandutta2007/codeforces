#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll myPow(int p){
    ll ret = 1;
    for(int i=1;i<=p;i++) ret*=3;
    return ret;
}
int main(){
    int a; cin >> a;
    while(a--){
        ll n; cin >> n;
        vector<int> dig;
        while(n>0){
            dig.push_back(n%3);
            n/=3;
        }
        for(int i=0;i<3;i++) dig.push_back(0);
        int last0= dig.size()-1;
        for(int i=dig.size()-1;i>=0;i--){
            if(dig[i]==0){
                last0 = i;
            }
            if(dig[i]==2){
                dig[last0]++;
                for(int i=last0-1;i>=0;i--){
                    dig[i] = 0;
                }
                break;
            }
        }
        ll ans= 0 ;
        for(int i=0;i<dig.size();i++){
            ans+=dig[i]*1LL*myPow(i);
        }
        cout << ans << endl;
    }
}