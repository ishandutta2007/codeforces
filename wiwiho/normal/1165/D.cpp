#include <bits/stdc++.h>

using namespace std;

//#define TEST

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for(int query = 0; query < t; query++){

        int n;
        cin >> n;

        vector<long long> d(n);
        for(int i = 0; i < n; i++){
            cin >> d[i];
        }

        sort(d.begin(), d.end());

        long long ans = d[0] * d[n - 1];

        if(ans == -1){
            cout << ans << "\n";
            continue;
        }

        vector<long long> divisor;
        for(int i = 2; (long long)i * i <= ans; i++){
            if(ans % i == 0){
                divisor.push_back(i);
                if(ans / i != i){
                    divisor.push_back(ans / i);
                }
            }
        }
        sort(divisor.begin(), divisor.end());

        if(divisor != d){
            ans = -1;
        }

        cout << ans << "\n";

    }
    
    return 0;
}