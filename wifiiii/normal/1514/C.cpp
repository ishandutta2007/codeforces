#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int chk(int x) {
    if(x == 4) return 1;
    if(x % 2 == 0) x /= 2;
    if(x % 2 == 0) return 0;
    for(int i = 3; i * i <= x; ++i) {
        if(x % i == 0) {
            while(x % i == 0) x /= i;
            if(x == 1) return 1;
            return 0;
        }
    }
    return 1;
}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main() {
    int n;
    cin >> n;
    vector<int> ans;
    for(int i = 1; i < n; ++i) {
        if(gcd(i, n) == 1) ans.push_back(i);
    }
    if(n > 2 && chk(n)) ans.pop_back();
    cout << ans.size() << '\n';
    for(int i : ans) cout << i << " "; cout << endl;
}