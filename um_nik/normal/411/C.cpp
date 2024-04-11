#include <iostream>
using namespace std;

int x[5], y[5];

bool check(int b, int a)
{
    if (x[2] > a && y[3] > b)
        return true;
    if (x[3] > a && y[2] > b)
        return true;
    return false;
}

int main()
{
    for (int i = 0; i < 4; i++)
        scanf("%d%d", &x[i], &y[i]);
    if (x[0] > y[2] && x[0] > y[3] && y[1] > x[2] && y[1] > x[3])
    {
        printf("Team 1\n");
        return 0;
    }
    if (x[1] > y[2] && x[1] > y[3] && y[0] > x[2] && y[0] > x[3])
    {
        printf("Team 1\n");
        return 0;
    }
    if (check(x[0], y[1]) && check(x[1], y[0]))
        printf("Team 2\n");
    else
        printf("Draw\n");
//  cin >> x[0];
    return 0;
}