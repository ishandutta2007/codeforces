#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using ll = long long;

using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n < 4){
        cout << -1;
    }
    else if(n == 4){
        cout << "3 1 4 2";
    }
    else{
        map<int, vector<int>> templ;
        templ[5] = {1, 3, 5, 2, 4};
        templ[6] = {1, 4, 2, 6, 3, 5};
        templ[7] = {1, 4, 7, 3, 5, 2, 6};
        templ[8] = {1, 4, 2, 6, 8, 5, 3, 7};
        templ[9] = {1, 3, 7, 9, 5, 2, 6, 4, 8};
        int i = 0;
        while(n > 9){
            for(int j = 0; j < 5; j++){
                cout << i + templ[5][j] << " ";
            }
            i += 5;
            n -= 5;
        }
        for(int j = 0; j < n; j++){
            cout << i + templ[n][j] << " ";
        }
    }
}

int main(){
    int t;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        solve();
        cout << endl;
    }
    return 0;
}