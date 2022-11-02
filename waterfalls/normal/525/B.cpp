#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char s[200013];
int m;
int sums[100013];

int main() {
    scanf(" %s %d",&s,&m);
    int len = strlen(s);
    for (int i=0;i<m;i++) {
        int a;
        scanf("%d",&a);
        a-=1;
        sums[a]+=1;
    }
    for (int i=1;i<=len/2+2;i++) sums[i]+=sums[i-1];
    for (int i=0;i<len;i++) {
        if (i<len/2) printf("%c",sums[i]%2 ? s[len-i-1] : s[i]);
        else if (len%2==1 && i==len/2) printf("%c",s[i]);
        else printf("%c",sums[len-i-1]%2 ? s[len-i-1] : s[i]);
    }
    printf("\n");

    return 0;
}