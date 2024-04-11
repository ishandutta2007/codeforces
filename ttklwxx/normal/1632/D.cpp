#include<bits/stdc++.h>
using namespace std;
 
 
const int maxN = 200000;
const int maxLog = 20;
int table[maxN][maxLog], a[maxN];
int n;
 
 
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
 
 
void precalc() {
    for(int st = 0; (1 << st) <= n; st++) {
        for(int i = 0; i <= n - (1 << st); i++) {
            if(st == 0) {
                table[i][st] = a[i];
                continue;
            }
            table[i][st] = gcd(table[i][st - 1], table[i + (1 << (st - 1))][st - 1]);
        }
    }
}
 
 
int getGcd(int l, int r) {
    int st = __lg(r - l + 1);
    return gcd(table[l][st], table[r + 1 - (1 << st)][st]);
}
 
 
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    precalc();
    int ans = 0;
    int maxr = -1;
    int pt = 0;
    for(int i = 0; i < n; i++) {
        while(pt < i && getGcd(pt, i) < i - pt + 1) ++pt;
        if(getGcd(pt, i) == i - pt + 1) {
            if(pt > maxr) {
                ++ans;
                maxr = i;
            }
        }
        cout << ans << ' ';
    }
}