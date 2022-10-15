#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    char last=s[0];
    int freq=1;
    bool flag=false;
    for(int i=1; i<s.size(); ++i) {
        if(s[i]==last) {
            ++freq;
            if(freq==7) {
                flag=true;
                break;
            }
        } else {
            last=s[i];
            freq=1;
        }
    }
    if(flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}