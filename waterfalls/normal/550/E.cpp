#include <cstdio>

using namespace std;

int n;
char s[100013];

int go() {
    int found = 0;
    for (int i=0;i<n-3;i++) if (s[i]=='0') found = 1;
    if (!found) printf("NO\n");
    else {
        printf("YES\n");
        int i;
        for (i=0;s[i]!='0';i++) printf("%c->",s[i]);
        printf("0->(");
        for (i=i+1;i<n-2;i++) printf("%c->",s[i]);
        printf("0)->0\n");
    }
    return 0;
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf(" %c",&s[i]);
    if (n>2 && s[n-3]=='1' && s[n-2]=='0' && s[n-1]=='0') return go();
    if (s[n-1]!='0' || (n>1 && s[n-2]=='0' && n==2)) printf("NO\n");
    else {
        printf("YES\n");
        if (n==1) printf("0\n");
        else if (n==2) printf("1->0\n");
        else if (s[n-2]=='1') {
            for (int i=0;i<n-1;i++) printf("%c->",s[i]);
            printf("0\n");
        } else {
            for (int i=0;i<n-3;i++) printf("%c->",s[i]);
            printf("(0->0)->0\n");
        }
    }

    return 0;
}