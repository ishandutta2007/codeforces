#include <bits/stdc++.h>
using namespace std;

int q, ai, b[200000], c1=0, c2=1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> q;
    while(q--) {
        char qt;
        cin >> qt >> ai, --ai;
        if(qt=='L')
            b[ai]=++c1;
        else if(qt=='R')
            b[ai]=--c2;
        else
            cout << min(c1-b[ai], b[ai]-c2) << "\n";
    }
}