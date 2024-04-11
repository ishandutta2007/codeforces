#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4;
char s[maxn];
bool v[26];

int main() {
    int n; scanf("%d", &n);
    set<int> st;
    while (n--) {
        scanf("%s", s);
        int m = strlen(s);
        int z = 0;
        memset(v, false, sizeof(v));
        for (int i = 0; i < m; ++i) {
            if (!v[s[i] - 'a']) v[s[i] - 'a'] = true, z ^= (1 << (s[i] - 'a'));
        }
        st.insert(z);
    }
    printf("%d\n", (int)st.size());
    return 0;
}