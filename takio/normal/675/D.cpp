#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100100;
int a[N];
set <int> st;
map <int, int> l, r;
set <int> :: iterator it, it2;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    st.insert (0);
    st.insert (a[1]);
    st.insert (1e9 + 10);
    r[0] = 1;
    l[1e9 + 10] = 1;
    for (int i = 2; i <= n; i++) {
        it = st.upper_bound(a[i]);
        it2 = it;
        it2--;
        if (r[(*it2)]) {
            printf ("%d ", (*it));
            l[(*it)] = 1;
        } else {
            printf ("%d ", (*it2));
            r[(*it2)] = 1;
        }
        st.insert (a[i]);
    }
}