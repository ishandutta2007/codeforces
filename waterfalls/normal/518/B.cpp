#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

string s,t;
map<char,int> counts;

char change(char c) {
    if (c=='0') return '0';
    if (c<='Z') return (char) (c-'A'+'a');
    else return (char) (c-'a'+'A');
}

int main() {
    cin >> s >> t;
    for (int i=0;i<t.size();i++) counts[t[i]]+=1;
    int yay = 0, whoops = 0;
    for (int i=0;i<s.size();i++) if (counts[s[i]]) yay+=1, counts[s[i]]-=1, s[i] = '0';
    for (int i=0;i<s.size();i++) if (counts[change(s[i])]) whoops+=1, counts[change(s[i])]-=1;
    cout << yay << " " << whoops << "\n";

    return 0;
}