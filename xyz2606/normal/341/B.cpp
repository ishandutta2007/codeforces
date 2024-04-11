#include<cstring>

#include<cstdio>

#include<algorithm>

#include<vector>

#include<cmath>

#include<cstdlib>

#include<ctime>

#include<queue>

using namespace std;

int Q, n, cl, x, st[111111];

int main()

{


    scanf("%d", &n);
    st[0] = -1; cl = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if(x > st[cl]) st[++cl] = x;
        else
            *lower_bound(st + 1, st + 1 + cl, x) = x;
    }
    printf("%d\n", cl);
    fclose(stdin);

    return 0;

}