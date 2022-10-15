#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        string s;
        cin >> s;
        int length = s.size();
        if(length > 10) {
            cout << s[0] << length-2 << s[length-1] << "\n";
        } else {
            cout << s << "\n";
        }
    }
    return 0;
}