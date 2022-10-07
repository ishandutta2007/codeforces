#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N = 200005;
int m, h[N];
int n, a[N], b[N];
int main() {
    cin>>m;
    for (int i = 0; i <= m; i++)
        cin>>h[i];
    int ok = 0;
    for (int i = 1; i < m; i++)
        if (h[i] > 1 && h[i + 1] > 1)
            ok++;
    if (ok < 1){
        cout<<"perfect\n";
        return 0;
    }
    cout<<"ambiguous\n";
    int I = 1, P = 1;
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < h[i]; j++)
            a[++I] = P;
        P = I;
    }
    n = I;
    I = 1, P = 1;
    int O = 0, PP = 0, P1 = 0, P2 = 0;
    for (int i = 1; i <= m; i++){
        P1 = 0;
        P2 = 0;
        for (int j = 0; j < h[i]; j++){
            if (j == 0 || PP == 0)
                b[++I] = P;
            else
                b[++I] = PP;
            if (j == 0)
                P1 = I;
            else
                P2 = I;
        }
        P = P1;
        PP = P2;
    }
    for (int i = 1; i <= n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for (int i = 1; i <= n; i++)
        cout<<b[i]<<" ";
    cout<<endl;
    return 0;
}