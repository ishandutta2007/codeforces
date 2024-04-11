#include <bits/stdc++.h>

using namespace std;

//#define TEST

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> contest(n);
    for(int i = 0; i < n; i++){
        cin >> contest[i];
    }

    sort(contest.begin(), contest.end());

    int ans = 0;
    int now = 1;
    for(int i = 0; i < n; i++){
        if(contest[i] >= now){
            ans++;
            now++;
        }
    }

    cout << ans << "\n";
    
    return 0;
}