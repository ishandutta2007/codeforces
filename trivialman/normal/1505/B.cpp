#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9;
const int N = 2e5 + 5;
mt19937 rng(time(0));
 
int T, n, a[N];
 
int main() {
    cin >> n;
    int x;
    while(n>9){
        for(x=0;n;n/=10) x+=n%10;
        n = x;
    }
    cout<<n<<endl;
    return 0;
}