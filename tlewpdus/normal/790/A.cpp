#include <bits/stdc++.h>

using namespace std;

int n, k, a;
char inp[50][5];
int res[50];

void prt(int a) {
    if (a<26) printf("%c ",'A'+a);
    else printf("A%c ",'a'+(a-26));
}

int main() {
    int i;
    scanf("%d%d",&n,&k);
    for (i=0;i<n-k+1;i++) scanf("%s",inp[i]);
    for (i=0;i<k-1;i++) res[i] = i;
    a = k;
    for (i=k-1;i<n;i++) {
        if (inp[i-k+1][0]=='Y') res[i] = a++;
        else res[i] = res[i-k+1];
    }
    for (i=0;i<n;i++) prt(res[i]);
    printf("\n");

    return 0;
}