#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void check() {
    for (int i=1;i<a.size();i++) {
        if (abs(a[i]-a[i-1]) >= 2) {
            printf("NO\n");
            exit(0);
        }
    }
}

int main() {
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    while (a.size()) {
        check();
        int best = -1;
        int which = -1;
        for (int i=0;i<a.size();i++) {
            if (a[i] > best) {
                best = a[i];
                which = i;
            }
        }
        a.erase(a.begin()+which);
    }
    printf("YES\n");
}