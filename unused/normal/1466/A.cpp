#include <cstdio>
#include <set>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int d[50];
        for (int i = 0; i < n; i++) scanf("%d",&d[i]);
        set<int> ans;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) ans.insert(d[j] - d[i]);
        printf("%zd\n", ans.size());
    }
}