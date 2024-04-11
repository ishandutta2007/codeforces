#include<bits/stdc++.h>
using namespace std;

int main(){
    long s;
    int n, x, y, i;
    cin >> s >> n;
    vector<pair<int,int>> a;
    for (i = 0; i < n; i++){
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }
    sort(a.begin(), a.end());
    for (i = 0; i < n; i++){
        if (s <= a[i].first){
            cout << "NO";
            return 0;
        }
        else{
            s += a[i].second;
        }
    }
    cout << "YES";
}