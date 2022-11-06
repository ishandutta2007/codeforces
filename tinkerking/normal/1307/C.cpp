#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char s[100010];
int N;
LL ans[26][26];
LL cnt[26];

int main() {
    scanf("%s",s + 1);
    N = strlen(s + 1);
    LL lastans = 0;
    for (int i=1;i<=N;i++) {
        s[i] -= 'a';
        for (int j=0;j<26;j++) {
            ans[j][s[i]] += cnt[j];
        }
        cnt[s[i]]++;
    }
    for (int i=0;i<26;i++) {
        for (int j=0;j<26;j++) {
            lastans = max(lastans, ans[i][j]);
        }
    }
    for (int i=0;i<26;i++) {
        lastans = max(lastans, cnt[i]);
    }
    printf("%lld\n",lastans);
}