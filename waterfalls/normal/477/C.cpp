#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int ls,lp;
char s[2013];
char p[513];
int getRid[2000];
int endsAt[2000];
int mostCanGet[2000];
int minForLen[2000][2001];
int removeFor[2001];

int main() {
    scanf(" %s %s",&s,&p);
    ls = strlen(s); lp = strlen(p);
    for (int i=0;i<ls;i++) {
        getRid[i] = -1;
        endsAt[i] = -1;
        if (s[i]!=p[0]) continue;
        int on = 0;
        int where = i;
        while (where<ls && on<lp) {
            if (s[where]==p[on]) on+=1;
            where+=1;
        }
        if (on==lp) {
            getRid[i] = where-i-lp;
            endsAt[i] = where-1;
        }
    }
    for (int i=ls-1;i>=0;i--) {
        if (getRid[i]==-1) continue;
        mostCanGet[i] = 1;
        for (int j=0;j<=2000;j++) minForLen[i][j] = 10000;
        minForLen[i][1] = getRid[i];
        int where = endsAt[i]+1;
        int last = ls;
        while (where<last) {
            if (getRid[where]!=-1) {
                for (int j=1;j<=mostCanGet[where];j++) {
                    minForLen[i][j+1] = min(minForLen[i][j+1],getRid[i]+minForLen[where][j]);
                    minForLen[i][j] = min(minForLen[i][j],minForLen[where][j]);
                }
                mostCanGet[i] = max(mostCanGet[i],1+mostCanGet[where]);
                if (last==ls) last = endsAt[where];
            }
            where+=1;
        }
    }
    for (int i=0;i<=2000;i++) removeFor[i] = 10000;
    for (int i=0;i<ls;i++) for (int j=1;j<=mostCanGet[i];j++) removeFor[j] = min(removeFor[j],minForLen[i][j]);
    for (int i=0;i<=ls;i++) {
        int j;
        for (j=1;j<=2000;j++) if (removeFor[j]>i) break;
        j-=1;
        if (j*lp>ls-i) j = (ls-i)/lp;
        printf("%d ",j);
    }
    printf("\n");

    return 0;
}