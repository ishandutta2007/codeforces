#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int M = 1000000007;
typedef long long ll;
struct matrix {
    ll v[2][2];
} a,c,ans;
ll x,y,n;
matrix operator*(const matrix& a,const matrix& b) {
    memset(c.v,0,sizeof(c.v));
    for (int k = 0; k < 2; ++k)
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                c.v[i][j] = ((a.v[i][k] * b.v[k][j]) % M + c.v[i][j]) % M;
	return c;
}
matrix pow(matrix a,ll b) {
    ans.v[0][0] = ans.v[1][1] = 1;
    while (b) {
        if (b & 1) ans = ans * a;
        b = b / 2;
        a = a * a;
    }
}
int main() {
    cin >> x >> y >> n;
    if (n == 1) cout << (x % M + M) % M;
    else if (n == 2) cout << (y % M + M) % M;
    else {
        a.v[0][0] = 1; a.v[0][1] = -1;
        a.v[1][0] = 1; a.v[1][1] = 0;
        pow(a,n - 2);
        //cout << ans.v[0][0] << ' ' << ans.v[0][1] << endl;
        cout << ((ans.v[0][0] * y % M + ans.v[0][1] * x % M) % M + M) % M;
    }
}