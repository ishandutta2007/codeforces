#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bool isPrime[50001];

int main() {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i = 2; i <= 50000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = 2 * i; j <= 50000; j += i)
                isPrime[j] = false;
        }
    }
    int t; cin >> t;
    while(t--) {
        int a, b, k; cin >> a >> b >> k;
        if(k == 1) {
            if((a % b == 0 || b % a == 0) && a != b) 
                cout << "Yes" << "\n";
            else cout << "No" << "\n";
            continue;
        }
        int sum = 0;
        for(auto &it : primes) {
            while(a % it == 0) {
                a /= it;
                ++sum;
            }
        }
        for(auto &it : primes) {
            while(b % it == 0) {
                b /= it;
                ++sum;
            }
        }
        if(a > 1) ++sum;
        if(b > 1) ++sum;
        if(k <= sum) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}