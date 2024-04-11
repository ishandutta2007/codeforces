#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n;
char s[N*2];

int main() {
    cin >> T;
    while(T--){
        scanf("%d", &n);
        scanf("%s", s + 1);
        if(s[1]<=s[2]){
            printf("%c%c\n", s[1], s[1]);
        }else{
            int j = 2;
            while(j<=n&&s[j]<=s[j-1])
                j++;
            j--;
            rep(i, j + 1, j * 2) s[i] = s[j * 2 + 1 - i];
            s[j * 2 + 1] = 0;
            printf("%s\n", s + 1);
        }
    }
    return 0;
}