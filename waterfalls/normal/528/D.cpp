#include <cstdio>
#include <algorithm>

using namespace std;

int S,T,k;
char s[200013];
char t[200013];
int l[200013][4];
int r[200013][4];
int ok[200013];
unsigned long long s162[200013];
int let[200013];
unsigned long long t162[200013];
unsigned long long s16[16][12513];
unsigned long long t16[16][12513];

int conv(char c) {
    if (c=='A') return 0;
    if (c=='C') return 1;
    if (c=='G') return 2;
    if (c=='T') return 3;
}

int main() {
    scanf("%d%d%d %s %s",&S,&T,&k,&s,&t);
    for (int i=0;i<S;i++) s[i] = conv(s[i]);
    for (int i=0;i<T;i++) t[i] = conv(t[i]);
    for (int i=0;i<S;i++) for (int j=0;j<4;j++) l[i][j] = k+2, r[i][j] = k+2;
    l[0][s[0]] = 0;
    for (int i=1;i<S;i++) for (int j=0;j<4;j++) l[i][j] = (s[i]==j) ? 0 : l[i-1][j]+1;
    r[S-1][s[S-1]] = 0;
    for (int i=S-2;i>=0;i--) for (int j=0;j<4;j++) r[i][j] = (s[i]==j) ? 0 : r[i+1][j]+1;
    for (int i=0;i<S;i++) for (int j=0;j<4;j++) if (l[i][j]<=k || r[i][j]<=k) ok[i]|=1<<j;
    for (int i=S-1;i>=0;i--) s162[i] = (s162[i+1]<<4)+ok[i], s16[i&15][i>>4] = s162[i];
    for (int i=0;i<T;i++) let[i] = 1<<t[i];
    for (int i=T-1;i>=0;i--) t162[i] = (t162[i+1]<<4)+let[i], t16[i&15][i>>4] = t162[i];
    int ans = 0;
    for (int i=0;i<=S-T;i++) {
        int good = 1;
        int len = T/16;
        for (int j=0;j<len;j++) {
            if ((s16[i&15][(i>>4)+j]&t16[0][j])==t16[0][j]) continue;
            good = 0;
            break;
        }
        for (int j=T-(T&15);j<T;j++) if ((ok[i+j]&let[j])!=let[j]) good = 0;
        ans+=good;
    }
    printf("%d\n",ans);

    return 0;
}