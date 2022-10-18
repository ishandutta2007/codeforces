#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
#define fto(i, l, r) for(int i = l; i <= r; ++i)

double sum, ans;
int m, r;

int main() {
    cin >> m >> r;
    sum = 2*r*m + (m-1)*2*r*(2+sqrt(2));
    fto(i, 2, m-1) {
        sum+=(m-i)*2*2*r*(sqrt(2)+i-1);
    }

    ans = sum/pow(m, 2);
    printf("%.17g", ans);
}