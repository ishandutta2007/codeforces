#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)

using namespace std;

int main () {
    int m, n;
    scanf("%d%d", &m, &n);
    string s1, s2, s3;
    fto(i, 0, n-1) s1 += "#";
    fto(i, 0, n-2) s2 += "."; s2 += "#";
    s3 += "#"; fto(i, 0, n-2) s3 += ".";

    fto(i, 1, m){
        if (i%2 == 1) cout << s1;
        else if (i%4 == 0) cout << s3;
        else cout << s2;
        cout << "\n";
    }

    return 0;
}