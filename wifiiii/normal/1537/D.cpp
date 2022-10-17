#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int x) {
    int y=x,c=0;
    while(y%2==0) y/=2,c++;
    if(y==1 && c>=5 && c%2==1) return 0;
    if(x<=9) {
        if(x==4 || x==6) return 1;
        return 0;
    }
    return x%2==0;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (solve(n) ? "Alice" : "Bob") << '\n';
    }
}