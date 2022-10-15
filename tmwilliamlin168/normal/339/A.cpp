#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int c1=0, c2=0, c3=0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i]=='1')
            ++c1;
        else if(s[i]=='2')
            ++c2;
        else if(s[i]=='3')
            ++c3;
    }
    if(c1!=0) {
        cout << 1;
        --c1;
    } else if(c2!=0) {
        cout << 2;
        --c2;
    } else {
        cout << 3;
        --c3;
    }
    while(c1--)
        cout << "+" << 1;
    while(c2--)
        cout << "+" << 2;
    while(c3--)
        cout << "+" << 3;
    return 0;
}