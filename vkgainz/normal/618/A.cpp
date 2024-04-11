#include<bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> in;
    for(int i = 0; i < n; i++) {
        in.push_back(1);
        while(in.size() > 1 && in.back() == in[in.size() - 2]) {
            in.pop_back();
            in[in.size() - 1]++;
        }
    }
    for(int x : in) cout << x << " ";
}