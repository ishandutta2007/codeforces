#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include <queue>
#include<vector>

using namespace std;

int num[15];

int main () {
    int a, cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= 6; i++) {
        cin >> a;
        num[a]++;
    }
    for (int i = 1; i <= 9; i++) {
        if (num[i] >= 4) cnt1++;
        if (num[i] == 2 || num[i] == 6) cnt2++;
    }
    if (cnt1 && cnt2) {
        cout << "Elephant\n";
    } else if (cnt1) {
        cout << "Bear\n";
    } else {
        cout << "Alien\n";
    }
}