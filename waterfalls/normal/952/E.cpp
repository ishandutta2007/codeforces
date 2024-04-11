#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    int soft = 0;
    int hard = 0;
    while (n--) {
        string s, t;
        cin >> s >> t;
        if (t=="soft") soft+=1;
        else hard+=1;
    }
    for (int i=0;;i++) {
        if (i*i/2 >= soft && i*i-i*i/2 >= hard) {
            printf("%d\n", i);
            break;
        }
        if (i*i/2 >= hard && i*i-i*i/2 >= soft) {
            printf("%d\n", i);
            break;
        }
    }
}