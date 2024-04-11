#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int gcd(int p, int q) {
    return q ? gcd(q, p % q) : p;
}

int dvd(int x) {
    int ret = 0, i = 1;
    for (; i * i < x; i++) {
        if (x % i == 0) {
            ret += 2;
        }
    }
    if (i * i == x) ret++;
    return ret;
}

ll x[100];
// ll p[100] = {1, -1, 0, -0.5, 0, 1, 0, -0.5, 0.1666666, 0.5, 0, 0, -0.5, 0.5, 0.3333333};

// 0.5 -> 3 7 9 12 13 

void solve(int casi){
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    ll a = dvd(A), b = dvd(B), c = dvd(C);
    ll ab = dvd(gcd(A, B)), bc = dvd(gcd(B, C)), ac = dvd(gcd(C, A));
    ll abc = dvd(gcd(gcd(A, B), C));
    x[0] = a * b * c;
    x[1] = ab * ac * bc;
    x[2] = a * ab * ac + b * ab * bc + c * ac * bc;
    x[3] = a * bc * bc + b * ac * ac + c * ab * ab;
    x[4] = abc * (a * b + a * c + b * c);
    x[5] = abc * (ab * ac + ab * bc + ac * bc);
    x[6] = abc * abc * (a + b + c);
    x[7] = abc * abc * (ab + ac + bc);
    x[8] = abc * abc * abc;
    x[9] = a * bc + b * ac + c * ab;
    x[10] = ab * ac + ab * bc + ac * bc;
    x[11] = abc * (a + b + c);
    x[12] = abc * (ab + ac + bc);
    x[13] = abc * abc;
    x[14] = abc;
    ll ans1 = x[0] - x[1] + x[5];
    ll ans3 = (x[8] + x[14] * 2) / 3;
    ll ans2 = (-x[3] - x[7] + x[9] - x[12] + x[13] + ans3) / 2;
    ll ans = ans1 + ans2;
    printf("%lld\n", ans);
    // for (int i = 0; i < 15; i++) 
    //     cout << x[i] << ' ';
    // cout << endl;
}

int main(){
    int T = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}