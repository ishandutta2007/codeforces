#include<stdio.h>
char in[200][200];
int map[30][30];
int ind[30];
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%s", in[i]);
    }
    for(i=1; i<n; i++)
    {
        for(j=0; in[i][j] == in[i+1][j]; j++);
        if(in[i][j] == 0) continue;
        if(in[i+1][j] == 0)
        {
            printf("Impossible");
            return 0;
        }
        if(map[in[i][j] - 'a'][in[i+1][j] - 'a'] == 0)
        {
            map[in[i][j] - 'a'][in[i+1][j] - 'a'] = 1;
            ind[in[i+1][j] - 'a'] ++;
        }
    }
    int Q[100], f, r;
    f=r=-1;
    for(i=0; i<='z'-'a'; i++)if(ind[i] == 0) Q[++r] = i;
    while(f<r)
    {
        int x = Q[++f];
        for(i=0; i<='z'-'a'; i++)
        {
            if(map[x][i] == 0) continue;
            ind[i]--;
            if(ind[i] == 0) Q[++r] = i;
        }
    }
    if(r != 'z'-'a') printf("Impossible");
    else
    {
        for(i=0; i<='z'-'a'; i++) printf("%c", Q[i]+'a');
    }
    return 0;
}