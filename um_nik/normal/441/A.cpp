#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> ans;
int p;
int k;
int m;
const int INF = 100000000;

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
        m = INF;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            int x;
            scanf("%d", &x);
            m = min(m, x);
        }
        if (p > m)
            ans.push_back(i);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}