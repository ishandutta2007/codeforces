#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string s,t;

int main() {
    cin >> s >> t;
    int which = s.size()-1;
    while (s[which]=='z') which-=1;
    s[which] = (char) (s[which]+1);
    for (int i=which+1;i<s.size();i++) s[i] = 'a';
    if (s==t) cout << "No such string\n";
    else cout << s;

    return 0;
}