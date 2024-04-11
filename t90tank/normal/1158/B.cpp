#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;

int main() {
    cin>>n>>k;
    if (k == 1) {
        for (int i = 1; i < n; ++i) printf( "0" );
        puts( "1" );
        return 0;
    }
    int p = (n-k)/2+1;
    for (int i = 0; i < n; ++i)
        if (i % p == 0) printf( "0");
        else printf("1");
     puts("");
}