#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int dx[] ={0,0,1,-1};
    int dy[] ={1,-1,0,0};
    vector<string> V(N);
    for(int i =0; i < N; i++) cin >> V[i];
    for(int i =0; i < N; i++) for(int j =0; j < N; j++) {
        int a =0;
        for(int k =0; k < 4; k++) if(min(dx[k]+i,dy[k]+j) >= 0 && max(dx[k]+i,dy[k]+j) < N)
            a +=int(V[i+dx[k]][j+dy[k]] == 'o');
        if(a%2 != 0) {cout << "NO\n"; return 0;}
        }
    cout << "YES\n";
    return 0;}