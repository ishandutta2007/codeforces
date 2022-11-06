#include <stdio.h>

using namespace std;

int n, i, j, k, sol, v[10][10];
char l1, c1, l2, c2;

void pune(int a, int b)
{
    if(a>0 && a<9 && b>0 && b<9)
        v[a][b]++;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%c%c\n%c%c", &l1, &c1, &l2, &c2);
    l1=l1-'a'+1;
    l2=l2-'a'+1;
    c1-='0';
    c2-='0';
    pune(l2+1, c2+2);
    pune(l2+1, c2-2);
    pune(l2-1, c2+2);
    pune(l2-1, c2-2);
    pune(l2+2, c2+1);
    pune(l2+2, c2-1);
    pune(l2-2, c2+1);
    pune(l2-2, c2-1);
    pune(l1+1, c1+2);
    pune(l1+1, c1-2);
    pune(l1-1, c1+2);
    pune(l1-1, c1-2);
    pune(l1+2, c1+1);
    pune(l1+2, c1-1);
    pune(l1-2, c1+1);
    pune(l1-2, c1-1);
    pune(l2, c2);
    for(int i=1; i<=8; ++i)
    {
        pune(l1, i);
        pune(i, c1);
    }
    for(int i=1; i<=8; ++i)
        for(int j=1; j<=8; ++j)
            if(v[i][j]==0)
                sol++;
    printf("%d\n", sol);
    return 0;
}