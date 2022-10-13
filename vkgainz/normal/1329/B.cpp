#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int d,m; cin >> d >> m;
        if(d==1){
            cout << 1%m<< endl;
            continue;
        }
        ll diff = 1;
        ll curr = 1;
        ll ans = 0;
        for(int i=1;i<=30;i++){
            curr+=diff*1LL*((1<<(i-1))-1);
            diff = curr+1;
            curr = curr*2+1;
            diff%=m;
            curr%=m;
            if(diff<0) diff+=m;
            if(curr<0) curr+=m;
            if((1<<(i+1))>d){
                ans = curr;
                ans+=(d-(1<<i))*1LL*diff;
                ans%=m;
                if(ans<0) ans+=m;
                break;
            }
        }
        cout << ans << endl;
    }
}