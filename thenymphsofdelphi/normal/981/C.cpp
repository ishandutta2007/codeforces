#include<bits/stdc++.h>
#define pb push_back
#define endl "\n"
using namespace std;

const int N = 100005;
vector <int> a[N], n1, n3;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, junc = 0;
    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; i++){
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for (int i = 1; i <= n; i++){
        if (a[i].size() >= 3){
            junc++;
            n3.pb(i);
        }
        if (a[i].size() == 1){
            n1.pb(i);
        }
    }
    if (junc >= 2){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    if (junc == 0){
        cout << 1 << endl;
        cout << n1[0] << " " << n1[1];
        return 0;
    }
    cout << n1.size() << endl;
    for (int i = 0; i < n1.size(); i++){
        cout << n1[i] << " " << n3[0] << endl;
    }
}