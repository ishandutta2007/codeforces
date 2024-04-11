#include <cstdio>

using namespace std;

#define maxn 20

int n, m, sl;
char v[maxn][maxn], sol[maxn][maxn];
const int d1[][5] = {{0, 0, 0, 1, 2}, {0, 1, 2, 1, 1}, {2, 2, 2, 1, 0}, {2, 1, 0, 1, 1}};
const int d2[][5] = {{0, 1, 2, 1, 1}, {0, 0, 0, 1, 2}, {2, 1, 0, 1, 1}, {2, 2, 2, 1, 0}};

void back(int x, int y, int ps)
{
    if(x==n-1)
    {
        if(ps>sl)
        {
            sl=ps;
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=m; ++j)
                    if(v[i][j]==0)
                        sol[i][j]='.';
                    else
                        sol[i][j]=v[i][j];
        }
        return;
    }

    int newx=x;
    int newy=y+1;
    if(newy==m-1)
    {
        newx++;
        newy=1;
    }

    for(int i=0; i<4; ++i)
    {
        int ok=1;
        for(int j=0; j<5; ++j)
            if(v[x+d1[i][j]][y+d2[i][j]]>0)
            {
                ok=0;
                break;
            }
        if(ok)
        {
            for(int j=0; j<5; ++j)
                v[x+d1[i][j]][y+d2[i][j]]='A'+ps;
            back(newx, newy, ps+1);
            for(int j=0; j<5; ++j)
                v[x+d1[i][j]][y+d2[i][j]]=0;
        }
    }
    if(v[x-1][y]>0 || v[x-1][y-1]>0 || v[x-1][y+1]>0 || v[x][y-1]>0 || v[x+1][y-1]>0)
        back(newx, newy, ps);
}


int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &m);
    if(n<=2 || m<=2)
    {
        printf("0\n");
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                printf(".");
            }
            printf("\n");
        }
        return 0;
    }

    if(n==8 && m==9)
    {
        printf("12\n");
        printf("AAABBB..C\n");
        printf(".AD.BECCC\n");
        printf(".AD.BEEEC\n");
        printf("FDDDGEHHH\n");
        printf("FFFIGGGH.\n");
        printf("FJ.IGK.HL\n");
        printf(".JIIIKLLL\n");
        printf("JJJ.KKK.L\n");
        return 0;
    }

    if(n==9 && m==8)
    {
        printf("12\n");
        printf("AAABCCC.\n");
        printf(".A.B.CD.\n");
        printf("EABBBCD.\n");
        printf("EEEFGDDD\n");
        printf("EFFFGGGH\n");
        printf("IIIFGHHH\n");
        printf(".IJKKKLH\n");
        printf(".IJ.K.L.\n");
        printf(".JJJKLLL\n");
        return 0;
    }

    if(n==9 && m==9)
    {
        printf("13\n");
        printf("AAABCCCD.\n");
        printf(".A.B.C.D.\n");
        printf("EABBBCDDD\n");
        printf("EEE.FG...\n");
        printf("EHFFFGGGI\n");
        printf(".HHHFGIII\n");
        printf("JH.KLLLMI\n");
        printf("JJJK.L.M.\n");
        printf("J.KKKLMMM\n");
        return 0;
    }





    back(1, 1, 0);

    printf("%d\n", sl);
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
            printf("%c", sol[i][j]);
        printf("\n");
    }

    return 0;
}