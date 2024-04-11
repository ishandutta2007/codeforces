#include<string>
#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
void sort(string & a, int le, int ri) {
    if(le == ri || (ri - le) & 1) {
        return;
    }else {
        sort(a, le, le + ri >> 1);
        sort(a, le + ri >> 1, ri);
        if(a.substr(le, (le + ri >> 1) - le) > a.substr(le + ri >> 1, ri - (le + ri >> 1))) {
            swap_ranges(a.begin() + le, a.begin() + (le + ri >> 1), a.begin() + (le + ri >> 1));
        }
    }
}
void sort(string & a) {
    int len(a.size());
    sort(a, 0, len);
}
int main() {
    string a, b;
    cin >> a >> b;
    sort(a);
    sort(b);
    printf("%s\n", a == b ? "YES" : "NO");
}