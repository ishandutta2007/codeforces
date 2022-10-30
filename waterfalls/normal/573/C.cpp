#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,allok,inbig;
vector<int> adj[100013];
bool onechain[100013];
bool twochain[100013];
bool outbig[100013];

void dfs(int x, int p) {
    if (inbig) return;
    for (int i: adj[x]) if (i!=p) dfs(i,x);
    if (inbig) return;
    int chain = 0;
    int bad = 0;
    for (int i: adj[x]) if (i!=p) {
        if (onechain[i]) chain+=1;
        else bad+=1;
    }
    if (bad || chain>2) inbig = x;
    else if (chain<=1) onechain[x] = 1;
}

void dfs2(int x, int p) {
    if (!allok) return;
    for (int i: adj[x]) if (i!=p) dfs2(i,x);
    if (!allok) return;
    int one = 0;
    int two = 0;
    int big = 0;
    for (int i: adj[x]) if (i!=p) {
        if (onechain[i]) one+=1;
        if (twochain[i]) two+=1;
        if (outbig[i]) big+=1;
    }
    if (big || two || one>2) {
        if (big>1) allok = 0;
        else outbig[x] = 1;
    } else {
        if (one==2) twochain[x] = 1;
        else onechain[x] = 1;
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    inbig = 0;
    dfs(1,0);
    if (inbig==0) return printf("Yes\n"),0;
    for (int i=1;i<=n;i++) onechain[i] = 0;
    allok = 1;
    dfs2(inbig,0);
    printf("%s\n",allok ? "Yes" : "No");

    return 0;
}