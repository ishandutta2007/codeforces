#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
map<ll,int> dpL[26], dpR[26];
int n, k;
ll s;
int a[25];
ll factorial(int x) {
    ll prod = 1;
    for(int i=1;i<=x;i++) prod = prod*1LL*i;
    return prod;
}
void find(string &curr, bool b) {
    ll sum = 0;
    int use = 0;
    for(int i=0;i<curr.length();i++) {
        if(b) {
            if(curr[i]=='1') {
                sum+=a[i+(n/2)];
            }
            else if(curr[i]=='2') {
                if(a[i+(n/2)]>18) return;
                sum+=factorial(a[i+(n/2)]);
                ++use;
            }
        }
        else {
            if(curr[i]=='1') {
                sum+=a[i];
            }
            else if(curr[i]=='2') {
                if(a[i]>18) return;
                sum+=factorial(a[i]);
                ++use;
            }
        }
    }
    if(b) {
        if(use<=k) ++dpR[use][sum];
    }
    else {
        if(use<=k) ++dpL[use][sum];
    }
}
void generate(int mx, string curr, bool b) {
    if(curr.length()==mx) {
        find(curr,b);
        return;
    }
    generate(mx,curr+"0",b);
    generate(mx,curr+"1",b);
    generate(mx,curr+"2",b);
}
int main() {
    cin >> n >> k >> s;
    for(int i=0;i<n;i++) cin >> a[i];
    generate(n/2,"",false);
    generate((n+1)/2,"",true);
    ll ans = 0;
    for(int i=0;i<=k;i++) {
        for(int j=0;i+j<=k;j++) {
            for(auto &it : dpL[i]) {
                ans+=it.second*1LL*dpR[j][s-it.first];
            }
        }
    }
    cout << ans << endl;
}