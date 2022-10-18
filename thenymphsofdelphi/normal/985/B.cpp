#include<bits/stdc++.h>
using namespace std;

const int N = 2000;
string a[N];
int col[N];
bool mark;

int main(){
    for (int i = 0; i < N; i++){
        col[i] = 0;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        for (int j = 0; j < m; j++){
            if (a[i][j] == '1') col[j]++;
        }
    }
    for (int i = 0; i < n; i++){
        mark = 0;
        for (int j = 0; j < m; j++){
            if (a[i][j] == '1' && col[j] == 1){
                mark = 1;
                break;
            }
        }
        if (mark == 1) continue;
        else{
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}