#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t=0;
    string s;
    cin >> n >> s;
    char lastC=0;
    for(int i=0; i<n; ++i) {
        if(lastC==s[i])
            ++t;
        else
            lastC=s[i];
    }
    cout << t;
    return 0;
}