#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n;
int before[26][26];
char names[100][101];
int len[100];
int done[26];
vector<char> order;

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%s",&names[i]);
    for (int i=0;i<n;i++) len[i] = strlen(names[i]);
    int ok = 1;
    for (int i=1;i<n;i++) {
        int which = 0;
        while (names[i][which]==names[i-1][which] && which<min(len[i],len[i-1])) which+=1;
        if (which==len[i]) ok = 0;
        if (which!=len[i-1]) before[names[i-1][which]-'a'][names[i][which]-'a'] = 1;
    }
    for (int i=0;i<26;i++) for (int j=0;j<26;j++) if (before[i][j] && before[j][i]) ok = 0;
    if (ok) {
        for (int i=0;i<26;i++) {
            int found = 0;
            for (int j=0;j<26 && !found;j++) {
                int okay = 1;
                for (int k=0;k<26;k++) if (before[k][j]) okay = 0;
                if (okay && !done[j]) {
                    done[j] = 1;
                    found = 1;
                    order.push_back((char) (j+'a'));
                    for (int k=0;k<26;k++) before[j][k] = 0;
                }
            }
        }
        if (order.size()==26) {
            for (int i=0;i<26;i++) printf("%c",order[i]);
            printf("\n");
        } else printf("Impossible\n");
    } else printf("Impossible\n");

    return 0;
}