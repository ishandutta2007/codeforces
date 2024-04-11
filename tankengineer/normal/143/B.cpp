#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

char num[105];

int main() {
    scanf("%s", num);
    int l = strlen(num);
    string ans;
    if (num[0] == '-') {
        ans += '(';
    }
    ans += '$';
    int pos = l;
    for (int i = num[0] == '-'; i < l; ++i) {
        if (num[i] == '.') {
            pos = i;
            break;
        }
    }
    int cnt = 0;
    string tmp;
    for (int i = pos - 1; i >= 0; --i) {
        if (num[i] == '-') {
            continue;
        }
        if (cnt != 0 && cnt % 3 == 0) {
            tmp += ',';
        }
        tmp += num[i];
        ++cnt;
    }
    reverse(tmp.begin(), tmp.end());
    ans += tmp;
    ans += '.';
    for (int i = 1; i <= 2; ++i) {
        if (num[pos + i] > '9' || num[pos + i] < '0') {
            ans += '0';
        } else {
            ans += num[pos + i];
        }
    }
    if (num [0] == '-') {
        ans += ')';
    }
    cout << ans;
    return 0;
}