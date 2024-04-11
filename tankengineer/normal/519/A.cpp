#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s[10];

inline int type(char ch) {
    return ch >= 'a' && ch <= 'z';
}

inline int val(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 'a' + 'A';
    }
    switch (ch) {
        case 'Q' : return 9;
        case 'R' : return 5;
        case 'B' : return 3;
        case 'N' : return 3;
        case 'P' : return 1;
    }
    return 0;
}

int main() {
    int cnt[2] = {0, 0};
    for (int i = 0; i < 8; ++i) {
        scanf("%s", s);
        for (int j = 0; j < 8; ++j) {
            cnt[type(s[j])] += val(s[j]);
        }
    }
    if (cnt[0] > cnt[1]) {
        puts("White");
    } else if (cnt[0] == cnt[1]) {
        puts("Draw");
    } else {
        puts("Black");
    }
    return 0;
}