#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> sum;
    for(int i = 0; i < 3; ++i)
        sum.push_back(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 3; ++j){
            int x;
            cin >> x;
            sum[j] += x;
        }
    }
    bool ok = true;
    for(int i = 0; i < 3; ++i){
        if(sum[i] != 0){
            ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}