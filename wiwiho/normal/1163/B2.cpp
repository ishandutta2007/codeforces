#include <bits/stdc++.h>

using namespace std;

//#define TEST

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> count(100001);
    vector<int> colors(100001);
    int mx = 0;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int u;
        cin >> u;
        count[colors[u]]--;
        colors[u]++;
        count[colors[u]]++;
        mx = max(colors[u], mx);

        bool isAns = false;
        if(mx == 1){
            isAns = true;
        }
        else if(count[i]){
            isAns = true;
        }
        else if(count[1] == 1 && mx * count[mx] == i - 1){
            isAns = true;
        }
        else if(count[mx] == 1 && (mx - 1) * count[mx - 1] == i - mx){
            isAns = true;
        }
        if(isAns){
            ans = i;
        }
    }

    cout << ans << "\n";
    
    return 0;
}