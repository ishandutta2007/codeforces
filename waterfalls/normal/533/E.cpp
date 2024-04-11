#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char S[100013];
char T[100013];

int main() {
    scanf("%d %s %s",&n,&S,&T);
    int where = 0;
    while (S[where]==T[where]) where+=1;
    int wheres = where;
    int wheret = where+1;
    int ans = 0;
    int bad = 0;
    while (S[wheres]!='\0' || T[wheret]!='\0') {
        if (S[wheres]!=T[wheret]) bad+=1;
        else wheret+=1;
        if (bad>1) break;
        wheres+=1;
    }
    if (bad<=1) ans+=1;
    wheres = where+1;
    wheret = where;
    bad = 0;
    while (S[wheres]!='\0' || T[wheret]!='\0') {
        if (S[wheres]!=T[wheret]) bad+=1;
        else wheres+=1;
        if (bad>1) break;
        wheret+=1;
    }
    if (bad<=1) ans+=1;
    printf("%d\n",ans);

    return 0;
}