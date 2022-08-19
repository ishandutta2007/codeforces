#include <iostream>
using namespace std;

int k, n = 1000;
int sz;
int a[1001][1001];
int b[2000];
int ans[40000][2];

int main()
{
//  freopen("output.txt", "w", stdout);

    scanf("%d", &k);
    b[2] = 1;
    b[3] = 1;
    ans[0][0] = 0;
    ans[0][1] = 2;
    ans[1][0] = 0;
    ans[1][1] = 3;
    sz = 2;
    for (int i = 1; i <= 30; i++)
    {
        b[2 * i + 2] = 2 * b[2 * i];
        b[2 * i + 3] = 2 * b[2 * i];
        ans[sz][0] = 2 * i;
        ans[sz][1] = 2 * i + 2;
        sz++;
        ans[sz][0] = 2 * i;
        ans[sz][1] = 2 * i + 3;
        sz++;
        ans[sz][0] = 2 * i + 1;
        ans[sz][1] = 2 * i + 2;
        sz++;
        ans[sz][0] = 2 * i + 1;
        ans[sz][1] = 2 * i + 3;
        sz++;
    }
    int tmp = 100;
    for (int i = 0; i <= 30; i++)
    {
        ans[sz][0] = 2 * i + 2;
        ans[sz][1] = tmp;
        sz++;
        for (int j = i; j < 34; j++)
        {
            ans[sz][0] = tmp;
            tmp++;
            ans[sz][1] = tmp;
            sz++;
        }
        ans[sz][0] = tmp;
        ans[sz][1] = 950 + i;
        sz++;
        tmp++;
    }
    for (int i = 0; i < sz; i++)
    {
        a[ans[i][0]][ans[i][1]] = 1;
        a[ans[i][1]][ans[i][0]] = 1;
    }
    for (int i = 0; i <= 30; i++)
    {
        if ((k & (1 << i)) != 0)
        {
            a[1][950 + i] = 1;
            a[950 + i][1] = 1;
        }
    }
    printf("1000\n");
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (a[i][j] == 1)
                printf("Y");
            else
                printf("N");
        }
        printf("\n");
    }
    return 0;
}