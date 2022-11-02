#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> st;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        st.insert(s);
    }

    cout << st.size() << endl;
    return 0;
}