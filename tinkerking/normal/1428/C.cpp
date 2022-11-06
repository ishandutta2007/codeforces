#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
char s[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s", s + 1);
        N = strlen(s + 1);
        int v1 = 0, v2 = 0, ans = 0;
        for (int i=1;i<=N;i++) {
            if (s[i] == 'A') {
                v1++;
            } else {
                if (v1 > 0) {
                    v1--;
                } else {
                    v2++;
                }
            }
        }
        printf("%d\n",v1 + v2 % 2);
    }
}