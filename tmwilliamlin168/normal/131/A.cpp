#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    bool isCap=true;
    for(int i=1; i<s.size(); ++i) {
        if(s[i]>='a'&&s[i]<='z') {
            isCap=false;
            break;
        }
    }
    if(isCap) {
        for(int i=0; i<s.size(); ++i) {
            if(s[i]>='a'&&s[i]<='z')
                s[i]=toupper(s[i]);
            else
                s[i]=tolower(s[i]);
        }
    }
    cout << s;
    return 0;
}