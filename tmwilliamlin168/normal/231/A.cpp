#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c2=0;
    cin >> n;
    for(int i=0; i<n; ++i) {
        int c=0;
        for(int j=0; j<3; ++j) {
            int t;
            cin >> t;
            if(t==1) ++c;
        }
        if(c>=2) ++c2;
    }
    cout << c2;
    return 0;
}