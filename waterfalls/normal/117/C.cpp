#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,a,b,done,counter;
int adj[5000][5000];
char row[5001];
int visited[5000];
int num[5000];

void dfs(int x) {
    if (done) return;
    num[x] = counter;
    counter+=1;
    visited[x] = 1;
    for (int i=0;i<n && !done;i++) {
        if (!adj[x][i]) continue;
        if (visited[i] && num[i]<num[x]) {
            a = x;
            b = i;
            done = 1;
        } else if (!visited[i]) dfs(i);
    }
    num[x] = 100000000;
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf(" %s",&row);
        for (int j=0;j<n;j++) adj[i][j] = row[j]-'0';
        visited[i] = 0;
    }
    done = 0;
    counter = 1;
    for (int i=0;i<n && !done;i++) if (!visited[i]) dfs(i);
    if (done) {
        for (int c=0;c<n;c++) {
            if (adj[b][c] && adj[c][a]) {
                printf("%d %d %d\n",a+1,b+1,c+1);
                break;
            }
        }
    } else printf("-1\n");

    return 0;
}