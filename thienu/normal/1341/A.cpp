#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using ll = long long;

using namespace std;

void solve(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    if(n * (a-b) > c+d || n * (a+b) < c-d){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}

int main(){
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        solve();
    }
    return 0;
}