#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c=0;
    cin >> n;
    for(int i=0; i<n; ++i) {
        string s;
        cin >> s;
        if(s[1]=='+')
            ++c;
        else
            --c;
    }
    cout << c;
    return 0;
}