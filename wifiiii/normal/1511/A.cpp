#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] == 2) a[i] = 3;
            else if(a[i] == 3) a[i] = 2;
        }
        sort(a.begin(), a.end());
        int up = 0, down = 0;
        for(int i : a) {
            if(i == 1) up++;
            else if(i == 2 && up >= down) up++;
            else down++;
        }
        cout << up << endl;
    }
}