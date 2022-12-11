#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100;
string field[MAX_N];
vector <pair <int, int> > available[3];

void find_all(int n) {
    int now;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < field[i].length(); j++) {
            if (field[i][j] == '.') {
                now = 0;
                if (j > 0 && field[i][j - 1] == 'S') now++;
                if (j < field[i].length() - 1 && field[i][j + 1] == 'S') now++;
                available[now].push_back(make_pair(i, j));
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        field[i] = s;
    }
    find_all(n);
    int now = 0, pos = 0, ans = 0;
    while (k != 0) {
        if (pos == available[now].size()) {
            now++;
            pos = 0;
            continue;
        }
        field[available[now][pos].first][available[now][pos].second] = 'x';
        pos++;
        k--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < field[i].length(); j++) {
            if (field[i][j] == 'S') {
                if (j > 0 && (field[i][j - 1] == 'P' || field[i][j - 1] == 'x' || field[i][j - 1] == 'S')) ans++;
                if (j < field[i].length() - 1 && (field[i][j + 1] == 'P' || field[i][j + 1] == 'x' || field[i][j + 1] == 'S')) ans++;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << field[i] << endl;
    }
    return 0;
}