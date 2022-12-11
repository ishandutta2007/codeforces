#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, z, t1 ,t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int anse = (abs(y - x) + abs(z - x)) * t2 + 3 * t3;
    int anss = abs(y - x) * t1;
    //cout << anse << " " << anss<<'\n';
    if (anse <= anss) cout <<"YES";
    else cout << "NO";
}