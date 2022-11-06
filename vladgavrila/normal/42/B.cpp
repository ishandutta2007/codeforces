#include <stdio.h>

using namespace std;

int x1, x2, y1, y2, prx, pry, pkx, pky;
int f[10][10], at[10][10];
char c1, c2;
const int d1[]={-1, -1, -1, 0, 1, 1, 1, 0, 0};
const int d2[]={1, 0, -1, -1, -1, 0, 1, 1, 0};

int verif(int x, int y)
{
    if(x>0 && x<9 && y>0 && y<9 && at[x][y]==0)
        return 1;
    return 0;
}

void pune(int x, int y)
{
    for(int i=x+1; i<=8; ++i)
    {
        at[i][y]=1;
        if(f[i][y])
            break;
    }
    for(int i=y+1; i<=8; ++i)
    {
        at[x][i]=1;
        if(f[x][i])
            break;
    }
    for(int i=x-1; i; --i)
    {
        at[i][y]=1;
        if(f[i][y])
            break;
    }
    for(int i=y-1; i; --i)
    {
        at[x][i]=1;
        if(f[x][i])
            break;
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%c%c ", &c1, &c2);
    x1=c1-'a'+1;
    y1=c2-'0';
    f[x1][y1]=1;
    scanf("%c%c ", &c1, &c2);
    x2=c1-'a'+1;
    y2=c2-'0';
    f[x2][y2]=1;
    scanf("%c%c ", &c1, &c2);
    prx=c1-'a'+1;
    pry=c2-'0';
    f[prx][pry]=1;
    pune(x1, y1);
    pune(x2, y2);
    for(int i=0; i<8; ++i)
        at[prx+d1[i]][pry+d2[i]]=1;
    scanf("%c%c ", &c1, &c2);
    pkx=c1-'a'+1;
    pky=c2-'0';
    for(int i=0; i<9; ++i)
    {
        if(verif(pkx+d1[i], pky+d2[i]))
        {
            printf("OTHER\n");
            return 0;
        }
    }
    printf("CHECKMATE\n");
    return 0;
}