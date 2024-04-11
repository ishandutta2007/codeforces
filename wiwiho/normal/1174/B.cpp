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
    int odd = 0;
    int even = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 1){
            odd++;
        }
        else{
            even++;
        }
    }

    if(odd != 0 && even != 0){
        lsort(a);
    }

    for(int i = 0; i < n; i++){
        if(i != 0){
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    
    return 0;
}