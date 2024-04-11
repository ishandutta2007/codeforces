#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int need[26][26];
int whereBad[26];

int main() {
    int n;
    cin >> n;
    string S,T;
    cin >> S >> T;
    int cur = 0;
    for (int i=0;i<n;i++) if (S[i]!=T[i]) cur+=1;
    for (int i=0;i<n;i++) if (S[i]!=T[i]) need[S[i]-'a'][T[i]-'a'] = i+1;
    for (int i=0;i<26;i++) for (int j=0;j<26;j++) {
        if (need[i][j] && need[j][i]) {
            printf("%d\n%d %d\n",cur-2,need[i][j],need[j][i]);
            return 0;
        }
    }
    for (int i=0;i<n;i++) if (S[i]!=T[i]) whereBad[T[i]-'a'] = i+1;
    for (int i=0;i<n;i++) if (S[i]!=T[i] && whereBad[S[i]-'a']!=0) {
        printf("%d\n%d %d\n",cur-1,i+1,whereBad[S[i]-'a']);
        return 0;
    }
    printf("%d\n-1 -1\n",cur);

    return 0;
}