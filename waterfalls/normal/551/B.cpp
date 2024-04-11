#include <iostream>
#include <algorithm>

using namespace std;

int c1[26];
int c2[26];
int c3[26];

int main() {
    string a,b,c;
    cin >> a >> b >> c;
    for (int i=0;i<a.size();i++) c1[a[i]-'a']+=1;
    for (int i=0;i<b.size();i++) c2[b[i]-'a']+=1;
    for (int i=0;i<c.size();i++) c3[c[i]-'a']+=1;
    pair<int,int> ans;
    int best = 0;
    for (int one=0;one<=a.size()/b.size();one++) {
        int ok = 1;
        for (int i=0;i<26;i++) {
            c1[i]-=one*c2[i];
            if (c1[i]<0) ok = 0;
        }
        if (ok) {
            int cur = 1e9;
            for (int i=0;i<26;i++) if (c3[i]) cur = min(cur,c1[i]/c3[i]);
            if (one+cur>best) {
                ans = make_pair(one,cur);
                best = one+cur;
            }
        }
        for (int i=0;i<26;i++) c1[i]+=one*c2[i];
    }
    for (int i=0;i<ans.first;i++) {
        cout << b;
        for (int j=0;j<26;j++) c1[j]-=c2[j];
    }
    for (int i=0;i<ans.second;i++) {
        cout << c;
        for (int j=0;j<26;j++) c1[j]-=c3[j];
    }
    for (int i=0;i<26;i++) for (int j=0;j<c1[i];j++) cout << ((char) (i+'a'));
    cout << endl;

    return 0;
}