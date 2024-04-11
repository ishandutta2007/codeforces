#include <bits/stdc++.h>

#define lsort(a) sort(a.begin(), a.end())
#define gsort(a) sort(a.rbegin(), a.rend())

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    int m = 1000000000;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        m = min(m, a[i] / max(i, n - 1 - i));
    }
    cout << m << "\n";
    
    return 0;
}