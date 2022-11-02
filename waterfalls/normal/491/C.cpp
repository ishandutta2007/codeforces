#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 52;
const int INF = 100000000;
const int BASE = 1000;

int n;
int graph[MAX_N][MAX_N];
bool usedX[MAX_N];
bool usedY[MAX_N];
int linkTo[MAX_N];
int labelX[MAX_N];
int labelY[MAX_N];

bool findPath(int i) {
    usedX[i] = true;
    for (int j = 0; j < n; j++) {
        if (!usedY[j] && labelX[i] + labelY[j] == graph[i][j] && linkTo[j] == -1) {
            usedY[j] = true;
            linkTo[j] = i;
            return true;
        }
    }
    for (int j = 0; j < n; j++) {
        if (!usedY[j] && labelX[i] + labelY[j] == graph[i][j]) {
            usedY[j] = true;
            if (linkTo[j] == -1 || findPath(linkTo[j])) {
                linkTo[j] = i;
                return true;
            }
        }
    }
    return false;
}

int solve() {
    memset(linkTo, -1, sizeof(linkTo));
    memset(labelX, 0, sizeof(labelX));
    memset(labelY, 0, sizeof(labelY));

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) labelX[i] = max(labelX[i], graph[i][j]);
    for (int k = 0; k < n; k++) {
        while (true) {
            memset(usedX, 0, sizeof(usedX));
            memset(usedY, 0, sizeof(usedY));
            if (findPath(k)) break;

            int delta = INF;
            for (int i = 0; i < n; i++) if (usedX[i]) for (int j = 0; j < n; j++) if (!usedY[j]) delta = min(delta, labelX[i] + labelY[j] - graph[i][j]);
            if (delta == 0 || delta == INF) break;
            for (int i = 0; i < n; i++) if (usedX[i]) labelX[i] -= delta;
            for (int i = 0; i < n; i++) if (usedY[i]) labelY[i] += delta;
        }
    }
    int maxTotal = 0;
    for (int i = 0; i < n; i++) maxTotal += labelX[i] + labelY[i];
    return maxTotal;
}

int N,K;
char cipher[2000013];
char answer[2000013];
int match[52];

int main() {
    scanf("%d%d %s %s",&N,&K,&cipher,&answer);
    n = K;
    for (int i=0;i<N;i++) {
        int a = cipher[i]-'a';
        if (a<0) a = cipher[i]-'A'+26;
        int b = answer[i]-'a';
        if (b<0) b = answer[i]-'A'+26;
        graph[a][b]+=1;
    }
    printf("%d\n",solve());
    for (int i=0;i<K;i++) match[linkTo[i]] = i;
    for (int i=0;i<K;i++) {
        if (match[i]<26) printf("%c",(char) (match[i]+'a'));
        else printf("%c",(char) (match[i]+'A'-26));
    }
    printf("\n");

    return 0;
}