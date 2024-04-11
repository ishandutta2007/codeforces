#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int deg[100013];
int s[100013];
queue<int> process;

int main() {
    scanf("%d",&n);
    int total = 0;
    for (int i=0;i<n;i++) {
        scanf("%d%d",&deg[i],&s[i]);
        total+=deg[i];
        if (deg[i]==1) process.push(i);
    }
    printf("%d\n",total/2);
    while (!process.empty()) {
        int next = process.front();
        process.pop();
        if (deg[next]==0) continue;
        printf("%d %d\n",next,s[next]);
        deg[s[next]]-=1;
        s[s[next]]^=next;
        if (deg[s[next]]==1) process.push(s[next]);
    }

    return 0;
}