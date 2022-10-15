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
int n, ans1, ans2, c[111], a[111][111];
vector<int> f;
int main()
{
    scanf("%d", &n);
    ans1 = ans2 = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        for(int j = 1; j <= c[i]; j++) scanf("%d", &a[i][j]);
        if(c[i] & 1) f.push_back(a[i][c[i] / 2 + 1]);
        for(int j = 1; j <= c[i] / 2; j++)
            ans1 += a[i][j], ans2 += a[i][c[i] - j + 1];
    }
    sort(f.begin(), f.end());
    for(int i = 0; i < (int)f.size(); i++) if((((int)f.size() - i) & 1) == 1) ans1 += f[i]; else ans2 += f[i];
    printf("%d %d\n", ans1, ans2);
    fclose(stdin);
    return 0;
}