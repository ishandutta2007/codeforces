#include <bits/stdc++.h>
using namespace std;

int dat[101][101];

vector<pair<int, int>> two;
vector<pair<int, int>> one;

int main()
{
    int n, k;
    cin >> n >> k;

    if (n * n < k)
    {
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < n && k; i++)
    {
        for (int j = i; j < n && k; j++)
        {
            if (i == j)
            {
                k--;
                dat[i][j] = 1;
            }
            else if (k >= 2)
            {
                k -= 2;
                dat[i][j] = dat[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", dat[i][j]);
        }
        printf("\n");
    }
}