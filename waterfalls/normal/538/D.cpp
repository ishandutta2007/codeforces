#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char board[53][53];
int hit[53][53];
char ans[110][110];
vector<pair<int,int> > pieces;

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf(" %s",&board[i]);
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (board[i][j]=='o') pieces.push_back(make_pair(i,j));
    for (int i=0;i<2*n-1;i++) for (int j=0;j<2*n-1;j++) ans[i][j] = '.';
    ans[n-1][n-1] = 'o';
    for (int dx=-n+1;dx<n;dx++) for (int dy=-n+1;dy<n;dy++) {
        if (dx==0 && dy==0) continue;
        int ok = 1;
        for (int i=0;i<pieces.size();i++) {
            int px = pieces[i].first;
            int py = pieces[i].second;
            if (px+dx>=0 && px+dx<n && py+dy>=0 && py+dy<n) {
                if (board[px+dx][py+dy]=='.') ok = 0;
            }
        }
        if (!ok) continue;
        ans[n-1+dx][n-1+dy] = 'x';
        for (int i=0;i<pieces.size();i++) {
            int px = pieces[i].first;
            int py = pieces[i].second;
            if (px+dx>=0 && px+dx<n && py+dy>=0 && py+dy<n) hit[px+dx][py+dy] = 1;
        }
    }
    int ok = 1;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (board[i][j]=='x' && !hit[i][j]) ok = 0;
    if (ok) {
        printf("YES\n");
        for (int i=0;i<2*n-1;i++) {
            for (int j=0;j<2*n-1;j++) printf("%c",ans[i][j]);
            printf("\n");
        }
    } else printf("NO\n");

    return 0;
}