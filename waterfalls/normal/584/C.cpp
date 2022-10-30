#include <bits/stdc++.h>
using namespace std;

int n,t;
string s1,s2;
vector<int> same;
vector<int> diff;

char getother(char a, char b) {
    if (a>b) swap(a,b);
    if (a>'a') return 'a';
    if (b<'z') return 'z';
    return 'b';
}

int main() {
    cin >> n >> t >> s1 >> s2;
    for (int i=0;i<n;i++) {
        if (s1[i]==s2[i]) same.push_back(i);
        else diff.push_back(i);
    }
    int low = (diff.size()+1)/2;
    if (t<low) return printf("-1\n"), 0;
    string res;
    for (int i=0;i<n;i++) res+=getother(s1[i],s2[i]);
    int has = 0;
    while (has<n-t && same.size()>0) {
        int a = same.back();
        same.pop_back();
        res[a] = s1[a];
        has+=1;
    }
    while (has<n-t && diff.size()>=2) {
        for (int r=0;r<2;r++) {
            int a = diff.back();
            diff.pop_back();
            res[a] = s1[a];
            swap(s1,s2);
        }
        has+=1;
    }
    cout << res << '\n';

    return 0;
}