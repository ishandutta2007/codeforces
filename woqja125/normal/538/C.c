#include<stdio.h>
int in[100001][2];
int abs(int x){ return x>0?x:-x; }
int Max(int a, int b){ return a>b?a:b; }
int main()
{
    int n, m, max = 0;
    int i, j;
    scanf("%d%d", &n, &m);
    for(i=1; i<=m; i++)scanf("%d%d", &in[i][0], &in[i][1]);
    max = in[1][1] + in[1][0] - 1;
    for(i=1; i<m; i++)
    {
        if(max < in[i][1]) max = in[i][1];
        if(abs(in[i][1] - in[i+1][1]) > abs(in[i][0] - in[i+1][0]))
        {
            printf("IMPOSSIBLE");
            return 0;
        }
        max = Max(max, 
            Max(in[i][1], in[i+1][1]) + (abs(in[i][0] - in[i+1][0]) - abs(in[i][1] - in[i+1][1]))/2 );
    }
    if(max < in[m][1] + n - in[m][0]) max = in[m][1] + n - in[m][0];
    printf("%d", max);
    return 0;
}