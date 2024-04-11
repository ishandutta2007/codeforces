#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(b == 1) {
            cout << "NO" << endl;
            continue;
        }
        assert(b > 1);
        cout << "YES" << '\n';
        cout << 1ll * a * (2 * b - 1) << " " << a << " " << 2ll * a * b << endl;
        // (ab,2ab-a) = (ab,-a) = a
    }
}