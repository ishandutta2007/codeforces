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

    vector<int> a(n + 1);
    int count = 0;
    for(int i = 2; i <= n; i++){
        if(a[i] == 0){
            count++;
            a[i] = count;
            for(int j = i; (long long)i * j <= n; j++){
                a[i * j] = count;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(i != 2){
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    
    return 0;
}