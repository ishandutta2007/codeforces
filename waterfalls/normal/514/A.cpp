#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

char s[20];

int main() {
    scanf(" %s",&s);
    for (int i=0;s[i]!='\0';i++) {
        if (i==0 && s[i]=='9') printf("%c",s[i]);
        else printf("%c",min(s[i],(char) ('0'+'9'-s[i])));
    }
    printf("\n");

    return 0;
}