#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char s[11];
char newS[13];

int main() {
    scanf("%s",&s);
    int len = strlen(s);
    int found = 0;
    for (int add=0;add<26 && !found;add++) {
        for (int i=0;i<=len && !found;i++) {
            int where = 0;
            for (int j=0;j<=len;j++) {
                if (j==i) newS[j] = (char) (add+'a');
                else {
                    newS[j] = s[where];
                    where+=1;
                }
            }
            int ok = 1;
            for (int j=0;j<=len;j++) if (newS[j]!=newS[len-j]) ok = 0;
            if (ok) {
                found = 1;
                newS[len+1] = '\0';
                printf("%s\n",newS);
            }
        }
    }
    if (!found) printf("NA\n");

    return 0;
}