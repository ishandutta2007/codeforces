#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long i = 1;
    vector<long long> v;
    while (i * i <= n){
        if (n%i == 0){
            v.push_back(i);
            if (i != n/i){
                v.push_back(n/i);
            }
        }
        i ++;
    }
    sort(v.begin(),v.end());
    if (v.size() < k) cout << -1 << endl;
    else cout << v[k-1] << endl;
}