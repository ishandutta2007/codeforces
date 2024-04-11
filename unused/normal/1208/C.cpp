#include <stdio.h>
int z[1000][1000];
int main()
{
    int n; scanf("%d",&n);
    int x = 0;
    for (int i = 0; i < n; i += 4)
        for (int j = 0; j < n; j += 4)
            for (int k = 0; k < 4; k++)
                for (int l = 0; l < 4; l++)
                    z[i+k][j+l] = x++;
    for (int i = 0; i < n; i++, printf("\n"))
    for (int j = 0; j < n; j++)
    printf("%d ", z[i][j]);
}