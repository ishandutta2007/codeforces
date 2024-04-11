#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m,k;
char grid[2013][2013];
int x[2013];
int y[2013];
int ans[2013];
int dp[2013][2013];
int ll[2013][2013];
int rr[2013][2013];
bool done[2013][2013];
int l[2013];
int r[2013];
deque<pair<int,int> > left;
deque<pair<int,int> > right;

bool check(int K) {
    left.clear(); right.clear();
    for (int i=0;i<n;i++) {
        while (left.size()>0 && left.front().B<=i-K) left.pop_front();
        while (right.size()>0 && right.front().B<=i-K) right.pop_front();
        while (left.size()>0 && left.back().A<=l[i]) left.pop_back();
        left.push_back(MP(l[i],i));
        while (right.size()>0 && right.back().A>=r[i]) right.pop_back();
        right.push_back(MP(r[i],i));
        if (i>=K-1 && right.front().A-left.front().A-1>=K) return true;
    }
    return false;
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
    for (int i=0;i<k;i++) {
        scanf("%d%d",&x[i],&y[i]);
        x[i]-=1; y[i]-=1;
        grid[x[i]][y[i]] = 'X';
    }
    for (int i=0;i<n;i++) dp[i][0] = (grid[i][0]=='.');
    for (int j=0;j<m;j++) dp[0][j] = (grid[0][j]=='.');
    for (int i=1;i<n;i++) for (int j=1;j<m;j++) {
        if (grid[i][j]=='.') {
            dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
        }
    }
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) ans[k-1] = max(ans[k-1],dp[i][j]);
    for (int i=0;i<n;i++) {
        ll[i][0] = (grid[i][0]=='X') ? 0 : -1;
        for (int j=1;j<m;j++) ll[i][j] = (grid[i][j]=='X') ? j : ll[i][j-1];
        rr[i][m-1] = (grid[i][m-1]=='X') ? m-1 : m;
        for (int j=m-2;j>=0;j--) rr[i][j] = (grid[i][j]=='X') ? j : rr[i][j+1];
    }
    for (int w=k-1;w>0;w--) {
        done[x[w]][y[w]] = 1;
        ll[x[w]][y[w]] = y[w]>0 ? ll[x[w]][y[w]-1] : -1;
        rr[x[w]][y[w]] = y[w]<m-1 ? rr[x[w]][y[w]+1] : m;
        for (int i=0;i<n;i++) {
            l[i] = ll[i][y[w]];
            while (l[i]>-1 && done[i][l[i]]) l[i] = ll[i][l[i]];
            r[i] = rr[i][y[w]];
            while (r[i]<m && done[i][r[i]]) r[i] = rr[i][r[i]];
        }
        ans[w-1] = ans[w];
        while (check(ans[w-1]+1)) ans[w-1]+=1;
    }
    for (int i=0;i<k;i++) printf("%d\n",ans[i]);

    return 0;
}