#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;

int n;
int a[100];

int main() {
    scanf( "%d",&n );
    int t = 52;
    int s = 0;
    for (int i = 1; i <= n; ++i){
        scanf( "%d", &a[i] );
        if (a[i] == t) s++;
        else if (a[i] < t) {
            t = a[i];
            s = 1;
        }
    }
    if (s >= n/2+1) puts("Bob");
    else puts("Alice");
}