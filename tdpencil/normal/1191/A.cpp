#include <bits/stdc++.h>
using namespace std;
int rnk(int num) {
    if(num % 4 == 0) return 4;
    if(num % 4 == 1) return 1;
    if(num % 4 == 3) return 2;
    return 3;
}
int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> mx;
    mx.emplace_back(0, rnk(n));
    mx.emplace_back(1, rnk(n+1));
    mx.emplace_back(2, rnk(n+2));
    for(int i = 0; i < 3; i++)
        swap(mx[i].first, mx[i].second);


    sort(mx.begin(), mx.end());

    cout << mx[0].second << " " << char(mx[0].first - 1 + 'A') << "\n";
}