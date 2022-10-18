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
    vector<int> a(2 * n);
    int ma = 0;
    int mi = 10000000;
    for(int i = 0; i < 2 * n; i++){
        cin >> a[i];
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    if(ma == mi){
        cout << "-1\n";
        return 0;
    }

    lsort(a);
    for(int i = 0; i < 2 * n; i++){
        if(i != 0){
            cout << " ";
        }
        cout << a[i];
    }

    cout << "\n";
    
    return 0;
}