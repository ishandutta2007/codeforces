#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string st;
    cin >> st;
    int k;
    cin >> k;
    if (st.size()%k!=0) cout << "NO";
    else {
        int l = st.size()/k;
        int ok = 1;
        for (int i=0;i<k;i++) {
            int s = i*l;
            int e = i*l+l-1;
            while (s<e) {
                if (st[s]!=st[e]) ok = 0;
                s+=1; e-=1;
            }
        }
        cout << (ok ? "YES" : "NO");
    }

    return 0;
}