#include <bits/stdc++.h>

using namespace std;

char str[1010];

int main() {
    scanf("%s",str);
    printf("%s",str);
    reverse(str,str+strlen(str));
    printf("%s\n",str);

    return 0;
}