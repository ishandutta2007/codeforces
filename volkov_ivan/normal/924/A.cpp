#include <iostream>
#include <vector>

using namespace std;

vector < pair <char, int> > now;
vector <int> now_r, now_c;

const int MAX_N = 50;
char field[MAX_N][MAX_N];
bool visited_r[MAX_N], visited_c[MAX_N];

bool process(int row, int n, int m) {
    now.push_back(make_pair('r', row));
    pair <char, int> q;
    while (!now.empty()) {
        q = now.back();
        now.pop_back();
        if (q.first == 'r') {
            now_r.push_back(q.second);
            for (int j = 0; j < m; j++) {
                if (field[q.second][j] == '#' && !visited_c[j]) {
                    now.push_back(make_pair('c', j));
                    visited_c[j] = 1;
                }
            }
        } else {
            now_c.push_back(q.second);
            for (int i = 0; i < n; i++) {
                if (field[i][q.second] == '#' && !visited_r[i]) {
                    now.push_back(make_pair('r', i));
                    visited_r[i] = 1;
                }
            }
        }
    }
    for (int i : now_r) {
        for (int j : now_c) {
            if (field[i][j] == '.') return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }
    for (int i = 0; i < max(n, m); i++) {
        visited_c[i] = visited_r[i] = 0;
    }
    bool found;
    for (int i = 0; i < n; i++) {
        found = 0;
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '#' && !visited_r[i] && !visited_c[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            now.clear();
            now_r.clear();
            now_c.clear();
            if (!process(i, n, m)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}