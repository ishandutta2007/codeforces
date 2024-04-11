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

    string s;
    cin >> s;

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '+'){
            ans++;
        }
        else if(ans > 0){
            ans--;
        }
    }

    cout << ans << "\n";
    
    return 0;
}