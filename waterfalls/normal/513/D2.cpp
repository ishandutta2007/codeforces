#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,c,ok;
pair<int,int> leftC[1000013];
pair<int,int> rightC[1000013];
int left[1000013];
int right[1000013];
char word[10];

void inorder(int x) {
    if (left[x]) inorder(left[x]);
    printf("%d ",x);
    if (right[x]) inorder(right[x]);
}

int solve(int root, int have) {
    if (!ok) return 0;
    if (leftC[root].second==0 && rightC[root].second==0 && root==have) return root;
    if (leftC[root].second==0) {
        right[root] = root+1;
        solve(root+1,max(rightC[root].second,have));
    } else if (rightC[root].second==0) {
        left[root] = root+1;
        solve(root+1,max(leftC[root].second,have));
    } else {
        left[root] = root+1;
        int which = solve(root+1,leftC[root].second);
        if (which>=rightC[root].first) ok = 0;
        right[root] = which+1;
        solve(which+1,max(rightC[root].second,have));
    }
}

int main() {
    scanf("%d%d",&n,&c);
    for (int i=1;i<=n;i++) leftC[i].first = rightC[i].first = 1000000000;
    for (int i=0;i<c;i++) {
        int a,b;
        scanf("%d%d %s",&a,&b,&word);
        if (a>=b) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        if (word[0]=='L') {
            leftC[a].first = min(leftC[a].first,b);
            leftC[a].second = max(leftC[a].second,b);
        } else {
            rightC[a].first = min(rightC[a].first,b);
            rightC[a].second = max(rightC[a].second,b);
        }
    }
    ok = 1;
    solve(1,n);
    if (!ok) printf("IMPOSSIBLE");
    else inorder(1);
    printf("\n");

    return 0;
}