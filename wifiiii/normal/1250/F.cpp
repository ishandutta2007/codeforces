#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> x, y;
        for(int i=0;i<2*n;++i) {
            int a,b;
            cin>>a>>b;
            if(!a) x.push_back(abs(b));
            else y.push_back(abs(a));
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        double ans=0;
        for(int i=0;i<n;++i) {
            ans+=sqrtl(1ll*x[i]*x[i]+1ll*y[i]*y[i]);
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
}