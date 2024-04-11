#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    if(s.find_first_of("HQ9")!=-1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}