#include <stdio.h>
#include <setjmp.h>

int dist[15][15];

jmp_buf jb1;

int main()
{
    int nn;
    scanf("%d", &nn);
    volatile int n = nn;
    volatile int i = 0, j = 0, k = 0;

    setjmp(jb1);

    scanf("%d", &dist[i][j]);

    ++j < n ? longjmp(jb1, 0) : (j = 0, ++i < n) ? longjmp(jb1, 0) : (void)0;

    i = j = k = 0;

    setjmp(jb1);

    dist[i][j] = dist[i][j] > dist[i][k] + dist[k][j] ? dist[i][k] + dist[k][j] : dist[i][j];

    ++j < n ? longjmp(jb1, 0) :
        (j = 0, ++i < n) ? longjmp(jb1, 0) : 
            (i = 0, ++k < n) ? longjmp(jb1, 0) : (void)0;

    volatile int ans = 0;

    i = j = 0;
    setjmp(jb1);

    ans = ans > dist[i][j] ? ans : dist[i][j];

    ++j < n ? longjmp(jb1, 0) :
        (j = 0, ++i < n) ? longjmp(jb1, 0) : (void)0;

    printf("%d", ans);
}