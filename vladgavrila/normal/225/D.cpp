#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 17
#define conf 30020

int n, m, lg, q0, pc, xt, yt, ds, cc, occ, oc, x[maxn], y[maxn], dt[maxn];
int f[maxn][maxn];
int d[maxn][maxn][conf];
char fol[maxn][maxn][conf];
pair<pair<int, int>, int> q[maxn*maxn*conf];
const int d1[]={0, 0, -1, 1};
const int d2[]={1, -1, 0, 0};
char s[maxn];

int det(int a, int b, int c)
{
    int aria = x[a]*y[b] + x[b]*y[c] + x[c]*y[a] - x[b]*y[a] - x[c]*y[b] - x[a]*y[c];

    if(aria==0)
        return 0;
    if(aria>0)
        return 1;
    if(aria<0)
        return 2;
}

int orientare(int a, int b)
{
    for(int j=0; j<4; ++j)
        if(x[a]+d1[j]==x[b] && y[a]+d2[j]==y[b])
            return j;
}

void build_snake(int a, int b)
{
    int xx, yy;
    x[1]=a;
    y[1]=b;
    for(int j=0; j<4; ++j)
    {
        x[2]=x[1]+d1[j];
        y[2]=y[1]+d2[j];

        if(orientare(1, 2)==oc)
            break;
    }

    for(int i=3; i<=lg; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            x[i]=x[i-1]+d1[j];
            y[i]=y[i-1]+d2[j];

            if(det(i-2, i-1, i)==dt[i-2] && (x[i]!=x[i-2] || y[i]!=y[i-2]))
                break;
        }
    }
}

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d\n", &n, &m);
    for(int i=1; i<=n; ++i)
    {
        scanf("%s", s+1);
        for(int j=1; j<=m; ++j)
        {
            if(s[j]=='#')
                f[i][j]=1;
            if(s[j]=='@')
            {
                xt=i;
                yt=j;
            }
            if(s[j]>='1' && s[j]<='9')
            {
                x[s[j]-'0']=i;
                y[s[j]-'0']=j;
                lg=max(lg, s[j]-'0');
            }
        }
    }

    cc=orientare(1, 2);

    for(int i=1; i<=lg-2; ++i)
        cc=cc*3+det(i, i+1, i+2);

    int ok;
    q0=1;
    q[q0]=make_pair(make_pair(x[1], y[1]), cc);

    fol[x[1]][y[1]][cc]=1;

    for(int i=1; i<=q0; ++i)
    {
        occ=cc=q[i].second;
        for(int j=lg-2; j; --j)
        {
            dt[j]=cc%3;
            cc=cc/3;
        }
        oc=cc;

//        printf("%d\n", oc);

        build_snake(q[i].first.first, q[i].first.second);

     //   for(int j=1; j<=lg; ++j)
       //     printf("%d %d\n", x[j], y[j]);
      //  printf("\n");

        pc=d[x[1]][y[1]][occ];

        for(int j=0; j<4; ++j)
        {
            x[0]=x[1]+d1[j];
            y[0]=y[1]+d2[j];

            if(x[0]<=0 || x[0]>=n+1 || y[0]<=0 || y[0]>=m+1)
                continue;

            cc=orientare(0, 1);
            for(int l=0; l<lg-2; ++l)
                cc=cc*3+det(l, l+1, l+2);

            ok=1;
            for(int i=1; i<lg; ++i)
                if(x[0]==x[i] && y[0]==y[i])
                {
                    ok=0;
                    break;
                }

            if(f[x[0]][y[0]]==1)
                ok=0;

            if(fol[x[0]][y[0]][cc]==1)
                ok=0;

            if(ok)
            {
                q[++q0]=make_pair(make_pair(x[0], y[0]), cc);
                fol[x[0]][y[0]][cc]=1;
                d[x[0]][y[0]][cc]=pc+1;
                if(x[0]==xt && y[0]==yt)
                {
                    printf("%d\n", pc+1);
                    return 0;
                }
            }
        }
    }

    printf("-1\n");

    return 0;
}