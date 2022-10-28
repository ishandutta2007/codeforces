#include <bits/stdc++.h>
using namespace std;

char get_letter(int i) {
    cout << "? " << 1 << " " << i + 1 << endl;
    char result; cin >> result;
    return result;
}

char get_distinct(int i, int j) {
    cout << "? " << 2 << " " << i + 1 << " " << j + 1 << endl;
    int result; cin >> result;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    string s = "";
    for (int i = 0; i < n; ++i) {
        vector<int> indices;
        for (int j = i - 1; j >= 0; --j) {
            bool diff = true;
            for (auto k : indices) diff &= s[j] != s[k];
            if (diff) indices.push_back(j);
        }

        if (get_distinct(0, i) > (int) indices.size()) {
            s += get_letter(i);
        } else {
            int low = 0, high = (int) indices.size() - 1;
            while (low < high) {
                int mid = (low + high) / 2;
                if (get_distinct(indices[mid], i) == mid + 1) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            s += s[indices[low]];
        }
    }

    cout << "! " << s << endl;
}