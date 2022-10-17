#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int g=0;
    for(int i=0;i<n;++i) cin>>a[i],g=gcd(g,a[i]);
    for(int i=0;i<n;++i) a[i]/=g;
    auto chk=[&](vector<int> a) {
        int mx=*max_element(a.begin(),a.end());
        int sum=accumulate(a.begin(),a.end(),0);
        int n=a.size();
        vector<int> dp(sum+1);
        dp[0]=1;
        for(int i:a) {
            for(int j=dp.size()-1;j>=i;--j) dp[j]|=dp[j-i];
        }
        if(sum%2==0 && dp[sum/2]) return 0;
        return 1;
    };
    if(chk(a)) cout<<"0"<<endl;
    else {
        for(int i=0;i<n;++i) {
            vector<int> b=a;
            b.erase(b.begin()+i);
            if(chk(b)) {
                cout<<"1"<<endl;
                cout<<i+1<<endl;
                return 0;
            }
        }
        assert(0);
    }
}