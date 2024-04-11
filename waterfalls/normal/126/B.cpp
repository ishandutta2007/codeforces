#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int len;
char s[1000013];
int Z[1000013];

int main() {
    scanf(" %s",&s);
    len = strlen(s);
    s[len] = '#';
    int L = 0;
    int R = 0;
    for (int i=1;i<len;i++) {
        if (i>R) {
            L = i;
            R = i;
            while (s[R]==s[R-i]) R+=1;
            R-=1;
            Z[i] = R-L+1;
        } else {
            int k = i-L;
            if (Z[k]>=R-i+1) {
                L = i;
                while (s[R]==s[R-i]) R+=1;
                R-=1;
                Z[i] = R-L+1;
            } else Z[i] = Z[k];
        }
    }
    int ans = 0;
    int ind;
    int maxLetters = 0;
    for (int i=1;i<len;i++) {
        if (Z[i]>ans) {
            if (i+Z[i]==len && maxLetters>=Z[i]) {
                ans = Z[i];
                ind = i;
            }
        }
        maxLetters = max(maxLetters,Z[i]);
    }
    if (ans==0) printf("Just a legend\n");
    else {
        for (int i=0;i<ans;i++) printf("%c",s[ind+i]);
        printf("\n");
    }

    return 0;
}