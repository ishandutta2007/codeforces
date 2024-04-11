#include <iostream>
using namespace std;

int n;
int ans;
int bal;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        bal += x;
        if (bal < 0)
            ans++;
        bal = max(0, bal);
    }
    printf("%d\n", ans);

    return 0;
}