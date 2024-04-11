#include <bits/stdc++.h>
using namespace std;

char buff[113];
string s;

int main() {
    for (int i=0;i<10;i++) {
        printf("%d\n", i);
        fflush(stdout);
        gets(buff);
        s = string(buff);
        if (s == "no") continue;
        int grumpy = -1;
        if (s == "great") grumpy = 0;
        else if (s == "don't think so") grumpy = 0;
        else if (s == "don't touch me") grumpy = 0;
        else if (s == "not bad") grumpy = 0;
        else if (s == "cool") grumpy = 0;
        else if (s == "no way") grumpy = 1;
        else if (s == "don't even") grumpy = 1;
        else if (s == "are you serious") grumpy = 1;
        else if (s == "go die in a hole") grumpy = 1;
        else if (s == "worse") grumpy = 1;
        else if (s == "terrible") grumpy = 1;
        if (grumpy == -1) continue;
        if (grumpy==1) printf("grumpy\n");
        else printf("normal\n");
        break;
    }
}