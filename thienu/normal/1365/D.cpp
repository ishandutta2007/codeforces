#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;


vector<pair<int, int>> offs;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n+2, vector<char>(m+2, '#'));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == 'B'){
                // cout << i << " " << j << endl;
                for(pair<int, int> off : offs){
                    if(board[i+off.first][j+off.second] == 'G'){
                        cout << "No" << endl;
                        return;
                    }
                    if(board[i+off.first][j+off.second] == '.'){
                        board[i+off.first][j+off.second] = '#';
                    }
                }
            }
        }
    }

    // for(int i = 0; i < n+2; i++){
    //     for(int j = 0; j < m+2; j++){
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }


    vector<vector<bool>> reachable(n+2, vector<bool>(m+2, false));
    queue<pair<int, int>> q;
    q.push(make_pair(n, m));
    while(q.size()){
        pair<int, int> cur = q.front();
        q.pop();
        if(reachable[cur.first][cur.second]){
            continue;
        }
        if(board[cur.first][cur.second] == '#'){
            continue;
        }
        reachable[cur.first][cur.second] = true;
        for(pair<int, int> off : offs){
            q.push(make_pair(cur.first + off.first, cur.second + off.second));
        }
    }

    // for(int i = 0; i < n+2; i++){
    //     for(int j = 0; j < m+2; j++){
    //         cout << (reachable[i][j] ? 1 : 0);
    //     }
    //     cout << endl;
    // }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == 'G' && !reachable[i][j]){
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main(){

    offs.push_back(make_pair(1, 0));
    offs.push_back(make_pair(-1, 0));
    offs.push_back(make_pair(0, 1));
    offs.push_back(make_pair(0, -1));

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}