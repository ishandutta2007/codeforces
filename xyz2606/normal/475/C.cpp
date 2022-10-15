#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
char st[1111][1111];
int a[1111][1111], s[1111][1111], s1[1111][1111], s2[1111][1111];
int n, m;
__inline int getSum(int x1, int y1, int x2, int y2) {
    if(x2 > n or y2 > m)
        return -1;
    return s[x2][y2] + s[x1 - 1][y1 - 1] - s[x2][y1 - 1] - s[x1 - 1][y2];
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i(0); i < n; i++) {
        scanf("%s", st[i]);
    }
    memset(a, 0, sizeof(a));
    int x(0), y(0), cnt(0);
    for(int i(1); i <= n; i++) {
        for(int j(1); j <= m; j++) {
            a[i][j] = st[i - 1][j - 1] == 'X';
            if(!x and !y and a[i][j]) {
                x = i; y = j;
            }
            if(a[i][j])
                cnt++;
            //printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
    }
    int px(x), py(y), h1(0), w1(0);
    while(px <= n and a[px][py] == 1) {
        h1++;
        px++;
    }
    px = x;
    while(py <= m and a[px][py] == 1) {
        w1++;
        py++;
    }
    memset(s, 0, sizeof(s));
    for(int i(1); i <= n; i++)
        for(int j(1); j <= m; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    for(int i(1); i <= n; i++) {
        s1[i][0] = 0;
        for(int j(1); j <= m; j++)
            s1[i][j] = s1[i][j - 1] + a[i][j];
    }
    for(int i(1); i <= m; i++) {
        s2[0][i] = 0;
        for(int j(1); j <= n; j++)
            s2[j][i] = s2[j - 1][i] + a[j][i];
    }
    vector<pair<int, pair<int, int> > > vec;
    for(int i(1); i <= n; i++)
        for(int j(1); j <= m; j++)
            if(i == h1 or j == w1)
                vec.push_back(make_pair(i * j, make_pair(i, j)));
    sort(vec.begin(), vec.end());
    int ans(-1);
    for(int i(0); i < (int)vec.size(); i++) {
        int h(vec[i].second.first), w(vec[i].second.second);
        //printf("%d %d %d\n", x, y, getSum(x, y, x + h - 1, y + w - 1));
        if(getSum(x, y, x + h - 1, y + w - 1) != h * w)
            continue;
        int px(x), py(y), cnt1(w * h);
        for(;;) {
            if(px + h <= n and -s1[px + h][py - 1] + s1[px + h][py + w - 1] == w) {
                px++;
                cnt1 += w;
            }else if(py + w <= m and -s2[px - 1][py + w] + s2[px + h - 1][py + w] == h) {
                py++;
                cnt1 += h;
            }else break;
        }
        if(cnt == cnt1) {
            ans = vec[i].first;
            //printf("%d %d\n", vec[i].second.first, vec[i].second.second);
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}