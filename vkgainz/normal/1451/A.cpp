#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n<=3) cout << n-1 << endl;
        else {
            if(n%2==0) cout << 2 << endl;
            else cout << 3 << endl;
        }
    }
}