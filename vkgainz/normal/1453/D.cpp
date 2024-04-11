#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 2e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        long long k; cin >> k;
        if(k%2==1) { //check
            cout << -1 << "\n";
            continue;
        }
        k/=2;
        vector<int> in;
        in.push_back(1);
        int lst = 0;
        int curr = 1;
        while(k>0) {
            if((1LL<<(curr-lst))-1==k) {
                break;
            }
            if((1LL<<(curr-lst+1))-1>k) {
                in.push_back(1);
                k-=(1LL<<(curr-lst))-1;
                lst = curr;
            }
            else {
                in.push_back(0);
            }
            ++curr;
        }
        cout << in.size() << "\n";
        for(auto &it : in) {
            cout << it << " ";
        }
        cout << "\n";
        
    }
}