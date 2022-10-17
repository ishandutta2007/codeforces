#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(N), b(N);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] += 1;
    }
    for(int i = 1; i < N; ++i) {
        for(int j = i; j < N; j += i) {
            if(a[j]) b[i] = gcd(b[i], j);
        }
    }
    int cnt = 0;
    for(int i = 1; i < N; ++i) if(b[i] == i) ++cnt;
    cout << cnt - n << '\n';
}