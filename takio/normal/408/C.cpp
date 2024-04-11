#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int l1[3010][200], l2[3010][200];
int n[3010];
const double eps = 1e-12;

void solve (int a, int b) {
    if (!n[a] || !n[b]) {
        cout << "NO\n";
        return ;
    }
    for (int i = 1; i <= n[a]; i++){
        if(l1[a][i] * b % a == 0 && l2[a][i] * b % a == 0 && l2[a][i] != l1[a][i] * b / a && -l2[a][i] * b / a != l1[a][i]){
            cout << "YES\n0 0\n" << l1[a][i] << ' ' << l2[a][i] << endl << -l2[a][i] * b / a << ' ' << l1[a][i] * b / a << endl;
            return ;
        }
    }
    if (a < b) swap (a, b);
    double k = sqrt(a * a - b * b);
    if (fabs((int)(k + 0.5) - k) < eps){a = (int)(k + 0.5);}
//    cout << k << ' ' << (int)(k + 0.5) - k << endl;
    if (!n[a]){
        cout << "NO\n";
        return ;
    }
    for (int i = 1; i <= n[a]; i++){
        if(l1[a][i] * b % a == 0 && l2[a][i] * b % a == 0 && l2[a][i] != l1[a][i] * b / a && -l2[a][i] * b / a != l1[a][i]){
            cout << "YES\n0 0\n" << l1[a][i] << ' ' << l2[a][i] << endl << -l2[a][i] * b / a << ' ' << l1[a][i] * b / a << endl;
            return ;
        }
    }
    cout << "NO\n";
    //cout << l1[a] << ' ' << l2[a] <<endl;
    //cout << l1[a] * b << ' ' << l2[a] * b <<endl;
    //cout << l1[a] * b % a << ' ' << l2[a] * b % a;
}


int main () {
    for(int i = 3; i <= 1500; i++)
        for (int j = i + 1; j <= 1500; j++)
        {
            double k = sqrt(i * i + j * j);
            if(fabs((int)(k + 0.5) - k) < eps){
                int k2 = (int)(k + eps);
                l1[k2][++n[k2]] = i,
                l2[k2][n[k2]] = j;
            }
        }
    int a, b;
//    freopen ("in.txt", "r", stdin);
//    freopen ("out.txt", "w", stdout);
    while(cin >> a >> b){
        solve (a, b);
    }
}