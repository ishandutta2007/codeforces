#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define endl '\n'

const int N = 2005;
char a[N][N];
int n, m;

bool ck(int i, int j){
    int cnt;
    if (i - 1 >= 0 && j - 1 >= 0){
        cnt = ((a[i][j] == '*') ? 1 : 0);
        if (a[i - 1][j - 1] == '*'){
            cnt++;
        }
        if (a[i - 1][j] == '*'){
            cnt++;
        }
        if (a[i][j - 1] == '*'){
            cnt++;
        }
		if (cnt == 1){
			a[i][j] = '.';
			return 1;
		}
    }
    if (i - 1 >= 0 && j + 1 < m){
        cnt = ((a[i][j] == '*') ? 1 : 0);
        if (a[i - 1][j + 1] == '*'){
            cnt++;
        }
        if (a[i - 1][j] == '*'){
            cnt++;
        }
        if (a[i][j + 1] == '*'){
            cnt++;
        }
		if (cnt == 1){
            a[i][j] = '.';
            return 1;
		}
	}
	if (i + 1 < n && j - 1 >= 0){
	    cnt = ((a[i][j] == '*') ? 1 : 0);
        if (a[i + 1][j - 1] == '*'){
            cnt++;
        }
        if (a[i + 1][j] == '*'){
            cnt++;
        }
        if (a[i][j - 1] == '*'){
            cnt++;
        }
		if (cnt == 1){
			a[i][j] = '.';
			return 1;
		}
	}
	if (i + 1 < n && j + 1 < m){
	    cnt = ((a[i][j] == '*') ? 1 : 0);
        if (a[i + 1][j + 1] == '*'){
            cnt++;
        }
        if (a[i + 1][j] == '*'){
            cnt++;
        }
        if (a[i][j + 1] == '*'){
            cnt++;
        }
		if (cnt == 1){
			a[i][j] = '.';
			return 1;
		}
	}
	return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    queue <pair <int, int>> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (ck(i, j)){
                q.push({i, j});
            }
        }
	}
	while (!q.empty()){
		int i = q.front().fi, j = q.front().se;
		q.pop();
		if (i - 1 >= 0 && a[i - 1][j] == '*'){
            if (ck(i - 1, j)){
                q.push({i - 1, j});
			}
		}
		if (i + 1 < n && a[i + 1][j] == '*'){
			if (ck(i + 1, j)){
				q.push({i + 1, j});
			}
		}
		if (j - 1 >= 0 && a[i][j - 1] == '*'){
            if (ck(i, j - 1)){
                q.push({i, j - 1});
            }
		}
		if (j + 1 < m && a[i][j + 1] == '*'){
			if (ck(i, j + 1)){
                q.push({i, j + 1});
			}
		}
		if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == '*'){
			if (ck(i + 1, j + 1)){
                q.push({i + 1, j + 1});
			}
		}
		if (i - 1 >= 0 && j + 1 < m && a[i - 1][j + 1] == '*'){
			if (ck(i - 1, j + 1)){
                q.push({i - 1, j + 1});
			}
		}
		if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] == '*'){
			if (ck(i - 1, j - 1)){
                q.push({i - 1, j - 1});
			}
		}
		if (i + 1 < n && j - 1 >= 0 && a[i + 1][j - 1] == '*'){
			if (ck(i + 1, j - 1)){
                q.push({i + 1, j - 1});
			}
		}
	}
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
}