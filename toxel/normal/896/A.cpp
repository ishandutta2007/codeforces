#include<bits/stdc++.h>

typedef long long ll;

const ll INF = 4e18;
const int N = 100010;

char s[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char t1[] = "What are you doing while sending \"";
char t2[] = "\"? Are you busy? Will you send \"";
char t3[] = "\"?";

int lens, lent1, lent2, lent3;
ll len[N];

char solve(int n, ll k){
    if (k >= len[n]){
        return '.';
    }
    if (n == 0){
        return s[k];
    }
    if (k < lent1){
        return t1[k];
    }
    if (k < lent1 + len[n - 1]){
        return solve(n - 1, k - lent1);
    }
    if (k < lent1 + len[n - 1] + lent2){
        return t2[k - lent1 - len[n - 1]];
    }
    if (k < lent1 + 2 * len[n - 1] + lent2){
        return solve(n - 1, k - lent1 - len[n - 1] - lent2);
    }
    return t3[k - lent1 - 2 * len[n - 1] - lent2];
}

int main(){
    lens = strlen(s);
    lent1 = strlen(t1);
    lent2 = strlen(t2);
    lent3 = strlen(t3);
    len[0] = lens;
    for (int i = 1; i < N; ++ i){
        len[i] = std::min(lent1 + lent2 + lent3 + 2 * len[i - 1], INF);
    }
    int q;
    scanf("%d", &q);
    while (q --){
        int n;
        ll k;
        scanf("%d%lld", &n, &k);
        putchar(solve(n, k - 1));
    }
    puts("");
    return 0;
}