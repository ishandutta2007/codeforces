#include<stdio.h>
#include<vector>
char map[100][100], map2[100][100];
char ans[210][210];
int n;
struct P
{
    int x, y;
    P(){}
    P(int X, int Y):x(X), y(Y){}
    P operator+(const P &t) const { return P(x+t.x, y+t.y); }
};
std::vector<P> points;
char trash = '_';
const char& getmap(const P &t)
{
    if(t.x < 0 || t.x >= n || t.y < 0 || t.y >= n) return trash;
    else return map[t.x][t.y];
}
char& getmap2(const P &t)
{
    if(t.x < 0 || t.x >= n || t.y < 0 || t.y >= n) return trash;
    else return map2[t.x][t.y];
}
int main()
{
    int i, j, k;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", map[i]);
        for(j=0; j<n; j++)
        {
            if(map[i][j] == 'o') points.push_back(P(i, j));
        }
    }
    for(i=-n+1; i<n; i++)
    {
        for(j=-n+1; j<n; j++)
        {
            if(i==0 && j==0)
            {
                ans[i+n-1][j+n-1] = 'o';
                continue;
            }
            P t(i, j);
            ans[i+n-1][j+n-1] = 'x';
            for(auto &p: points)
            {
                if(getmap(p+t) == '.')
                {
                    ans[i+n-1][j+n-1] = '.';
                    break;
                }
            }
        }
    }
    for(auto &p: points)
    {
        for(i=-n+1; i<n; i++)for(j=-n+1; j<n; j++)
        {
            if(ans[i+n-1][j+n-1] == 'x')
            {
                char &t = getmap2(P(i, j) + p);
                if(t != '_') t = 'x';
            }
        }
    }
    for(i=0; i<n; i++)for(j=0; j<n; j++) if(map[i][j] == 'x' && map2[i][j] != 'x')
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(i=0; i<2*n; i++) printf("%s\n", ans[i]);
    return 0;
}