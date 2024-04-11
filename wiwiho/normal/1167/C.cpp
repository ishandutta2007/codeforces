#include <bits/stdc++.h>

using namespace std;

//#define TEST

int dfs(vector<vector<int>>& friends, vector<int>& start, vector<bool>& book, int s){
    //cerr << "test " << s << "\n";
    if(friends[s].empty()){
        return 1;
    }

    book[s] = true;

    int ans = 1;
    for(int f : friends[s]){
        //cerr << s << " " << f << "\n";
        if(book[f]){
            continue;
        }
        start[f] = s;
        ans += dfs(friends, start, book, f);
    }

    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> friends(n + 1);

    for(int i = 0; i < m; i++){
        int k;
        cin >> k;

        int last = 0;
        for(int i = 1; i <= k; i++){
            int f;
            cin >> f;
            if(last != 0){
                friends[last].push_back(f);
                friends[f].push_back(last);
            }
            last = f;
        }
    }

    vector<bool> temp(n + 1, false);
    vector<int> start(n + 1);
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++){
        if(i != 1){
            cout << " ";
        }
        if(start[i]){
            while(ans[start[i]] == 0){
                start[i] = start[start[i]];
            }
            ans[i] = ans[start[i]];
            cout << ans[i];
            continue;
        }

        ans[i] = dfs(friends, start, temp, i);
        cout << ans[i];

    }

    cout << "\n";
    
    return 0;
}