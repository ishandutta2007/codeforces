#include<bits/stdc++.h>
using namespace std;
const int N = 2111111;
char s[N];
int L[N], R[N];
int main() {
    cin >> s + 1;
    int n = strlen(s + 1);
    
    int mx = 0;
    
    for (int i = 1; i <= n; ++i) {
        int now = 0;
        for (int j = i; j >= max(i - 19, 1); --j) {
            int t = s[j] - 'a';
            if (now & (1 << t)) 
                break;
            now |= (1 << t);
            R[now] = i - j + 1;
        }
    }

    for (int i = 0; i < 20; ++i) {
        int ss = ((1 << 20) - 1) ^ (1 << i);
        for (int j = ss; j; j = (j - 1) & ss) {
            R[j | (1 << i)] = max(R[j | (1 << i)], R[j]);
        }

        int j = 0;
        R[j | (1 << i)] = max(R[j | (1 << i)], R[j]);
    }

    for (int s = 0; s <= (1 << 20) - 1; ++s) {

        int ss = ((1 << 20) - 1) ^ s;
        mx = max(mx, R[s] + R[ss]);
    }
    cout << mx << endl;
    
    return 0;
}