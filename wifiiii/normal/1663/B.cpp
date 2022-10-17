#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> a {1200, 1400, 1600, 1900, 2100, 2300, 2400, 3000};
int main() {
    int x;
    cin >> x;
    for(int i : a) {
        if(i > x) {
            cout << i << '\n';
            break;
        }
    }
}