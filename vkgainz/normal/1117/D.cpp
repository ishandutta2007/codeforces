#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 2e5+5;
ll mod = 1e9+7;
struct Matrix {
    int m;
    ll a[100][100];
    Matrix(int _m) { 
        m = _m;
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                a[i][j] = 0LL;
    }
    Matrix operator *(Matrix other) {
        Matrix prod = Matrix(m);
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) {
                for(int k=0;k<m;k++) {
                    prod.a[i][k] += a[i][j]*other.a[j][k];
                    prod.a[i][k]%=mod;
                }
            }
        }
        return prod;
    }
};
ll n;
int m;
ll get(Matrix a) {
    Matrix res = Matrix(m);
    for(int i=0;i<m;i++) {
        if(i==0) {
            res.a[i][0] = 1, res.a[i][m-1] = 1;
        }
        else {
            res.a[i][i-1] = 1;
        }
    }
    while(n) {
        if(n%2) {
            res = res * a;
        }
        n/=2;
        a = a*a;
    }
    return (res.a[0][m-1]+mod)%mod;
}
int main() {
    cin >> n >> m;
    Matrix a = Matrix(m);
    for(int i=0;i<m;i++) {
        if(i==0) {
            a.a[i][0] = 1, a.a[i][m-1] = 1;
        }
        else {
            a.a[i][i-1] = 1;
        }
    }
    cout << get(a);
    
}