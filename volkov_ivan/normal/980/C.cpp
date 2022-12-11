#include <iostream>
#include <set>

using namespace std;

const int MAX_K = 256;
int group[MAX_K];
int post[MAX_K];
set <int> beg;
int cnt = 0;

void upd(int l, int r, int c) {
    for (int i = l; i <= r; i++) {
        group[i] = c;
    }
}

void add(int c, int k) {
    if (group[c] != -1) return;
    int l = max(0, c - k + 1);
    //cout << l << ' ';
    while (1) {
        if (group[l] == -1) {
            beg.insert(l);
            post[cnt] = l;
            upd(l, c, cnt);
            cnt++;
            return;
        }
        if (beg.find(l) != beg.end()) {
            upd(l, c, group[l]);
            return;
        }
        l++;
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < MAX_K; i++) group[i] = -1;
    for (int i = 0; i < n; i++) {
        add(arr[i], k);
    }
    for (int i = 0; i < n; i++) {
        cout << post[group[arr[i]]] << ' ';
    }
    cout << endl;
    return 0;
}