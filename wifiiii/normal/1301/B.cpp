#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        int lo=0,hi=1e9;
        auto calc = [&](int mid) {
            int ret=0;
            for(int i=1;i<n;++i) {
                int x=a[i-1]==-1?mid:a[i-1],y=a[i]==-1?mid:a[i];
                ret=max(ret,abs(x-y));
            }
            return ret;
        };
        while(lo<hi) {
            int m1=lo+(hi-lo)/3,m2=hi-(hi-lo)/3;
            if(calc(m1)<calc(m2)) hi=m2-1;
            else lo=m1+1;
        }
        cout<<calc(lo)<<" "<<lo<<endl;
    }
}