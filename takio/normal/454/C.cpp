#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;


int n, m;
long double f[100010], sum[100010];

int main (){
    cin >> m >> n;
//    f[0] = 0;
    long double mn = pow(m, n);
//    cout << mn << endl;
    long double res = 0;
    for (int i = 1; i <= m - 1; i++){
//        f[i] = pow(i, n) - sum[i - 1],
//        sum[i] = sum[i - 1] + f[i];
        res += pow((long double)i / m, n);
//        cout << f[i] << endl;
    }
    res = m - res;
    printf ("%.20lf", (double)res);
}