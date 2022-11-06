#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
int N;
vector<int>e[300010];
char s[300010];
bool ok[300010][2];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        scanf("%s", s);
        for (int i=0;i<N;i++) {
            e[i].clear();
            ok[i][0] = ok[i][1] = false;
        }
        for (int i=0;i<N;i++) {
            if (s[i] == '>') {
                ok[i][0] = true;
            } else if (s[i] == '<') {
                ok[(i + 1)%N][1] = true;
            } else {
                ok[i][0] = true;
                ok[(i + 1)%N][1] = true;
            }
        }

        bool all0 = true, all1 = true;
        for (int i=0;i<N;i++) {
            all0 &= ok[i][0];
            all1 &= ok[i][1];
            //printf("%d %d %d\n",i,ok[i][0],ok[i][1]);
        } 
        if (all0 || all1) {
            printf("%d\n",N);
            continue;
        }
        int ans = 0;
        for (int i=0;i<N;i++) {
            if ((ok[i][0] && ok[(i+1)%N][1]) || (ok[i][1] && ok[(i-1+N)%N][0])) {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}