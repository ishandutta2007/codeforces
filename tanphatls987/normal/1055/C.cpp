#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N = 1e5 + 10;

int n, test, l;
long long a[N];
int main() {
    long long la, ra, ta;
    long long lb, rb, tb;
    cin >> la >> ra >> ta;
    cin >> lb >> rb >> tb;
    if (la > lb) {
        swap(la, lb);
        swap(ra, rb);
        swap(ta, tb);
    }
    long long com = __gcd(ta, tb);
    long long ans = 0;
    long long p1 = la + (lb - la) / com * com;  
    ans = max(ans, min(p1 + ra - la, rb) - lb + 1);
    long long p2 = p1 + com;
    ans = max(ans, min(ra - la, rb - p2) + 1);
    cout << ans;
}