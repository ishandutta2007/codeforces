#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
char s[2010], t[2010];
int sc[26], tc[26];

int main() {
    int i, j;

    scanf("%d",&n);
    scanf("%s",s);
    scanf("%s",t);
    for (i=0;i<n;i++) {
        sc[s[i]-'a']++;
        tc[t[i]-'a']++;
    }
    for (i=0;i<26;i++) {
        if (sc[i]!=tc[i]) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",3*n);
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) if (s[j]==t[i]) break;
        int tl = j;
        printf("%d %d %d ",n-tl-1,1,n);
        char c = s[tl];
        for (j=tl+1;j<n;j++) s[j-1]=s[j];
        s[n-1]=c;
        reverse(s,s+tl);
    }

    return 0;
}