#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;

int main() {
//  freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int cnt = 0;
    int ce = 0;
    int last = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') cnt++; else
        if (s[i] == ')') cnt--; else {
            ce++;
            last = i;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '#') continue;
        if (last == i) {
            if (cnt <= 0) {
                puts("-1");
                return 0;
            }
            ans.push_back(cnt);
        } else {
            ans.push_back(1);
            cnt--;
        }
    }
    if (cnt < 0) {
        puts("-1");
        return 0;
    }
    cnt = 0;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') cnt++; else
        if (s[i] == ')') cnt--; else
        if (s[i] == '#') cnt -= ans[cur++]; 
        if (cnt < 0) {
            puts("-1");
            return 0;
        }
    }
    for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
}