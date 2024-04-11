#include<stdio.h>
#include<algorithm>
#include<vector>
void dfs(int x);
struct node
{
    int n, h;
} h[100001];
bool operator<(const node &A, const node &B){return A.h<B.h;}
std::vector<int> map[100001];
int range[100001][2];

void init(int n);
int getmax(int f, int r);
void set(int x, int v);

int imax[100001][3];
int dmax[100001][3];

int main()
{
    int n;
    int i, j;
    int t, a, b;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &h[i].h);
        h[i].n = i;
    }
    std::sort(h+1, h+n+1);
    for(i=1; i<n; i++)
    {
        scanf("%d%d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    dfs(1);

//  for(i=1; i<=n; i++)printf("# %d %d %d\n", i, range[i][0], range[i][1]);

    init(n);
    for(i=1; i<=n; i=j)
    {
        for(j=i; j<=n && h[j].h == h[i].h; j++)
        {
            int x = h[j].n;
            for(int k=0; k<map[x].size(); k++)
            {
                int xx = map[x][k];
                if(range[xx][0] < range[x][0]) continue;
                int t = getmax(range[xx][0], range[xx][1]);
                if(t > imax[x][0])
                {
                    imax[x][2] = imax[x][0];
                    imax[x][1] = xx;
                    imax[x][0] = t;
                }
                else if(t > imax[x][2])
                {
                    imax[x][2] = t;
                }
            }
        }
        for(j=i; j<=n && h[j].h == h[i].h; j++)
        {
            int x = h[j].n;
            set(range[x][0], imax[x][0]+1);
        }
    }

    init(n);
    for(i=n; i>=1; i=j)
    {
        for(j=i; j>=1 && h[j].h == h[i].h; j--)
        {
            int x = h[j].n;
            for(int k=0; k<map[x].size(); k++)
            {
                int xx = map[x][k];
                if(range[xx][0] < range[x][0]) continue;
                int t = getmax(range[xx][0], range[xx][1]);
            //  printf("*%d %d\n", xx, t);
                if(t > dmax[x][0])
                {
                    dmax[x][2] = dmax[x][0];
                    dmax[x][1] = xx;
                    dmax[x][0] = t;
                }
                else if(t > dmax[x][2])
                {
                    dmax[x][2] = t;
                }
            }
        }
        for(j=i; j>=1 && h[j].h == h[i].h; j--)
        {
            int x = h[j].n;
            set(range[x][0], dmax[x][0] + 1);
        }
    }

    int ans = 0;
    for(i=1; i<=n; i++)
    {
//      printf("&%d %d %d %d %d %d %d\n", i, imax[i][0], imax[i][1], imax[i][2], dmax[i][0], dmax[i][1], dmax[i][2]);
        if(imax[i][1] == dmax[i][1])
        {
            if(ans < imax[i][0] + dmax[i][2] + 1) ans = imax[i][0] + dmax[i][2] + 1;
            if(ans < imax[i][2] + dmax[i][0] + 1) ans = imax[i][2] + dmax[i][0] + 1;
        }
        else
        {
            if(ans < imax[i][0] + dmax[i][0] + 1) ans = imax[i][0] + dmax[i][0] + 1;
        }
    }

    init(n);
    for(i=1; i<=n; i=j)
    {
        for(j=i; j<=n && h[j].h == h[i].h; j++)
        {
            int x = h[j].n;
            int t = getmax(range[x][1]+1, n);
            if(ans < t+dmax[x][0]+1) ans = t+dmax[x][0]+1;
        }
        for(j=i; j<=n && h[j].h == h[i].h; j++)
        {
            int x = h[j].n;
            set(range[x][0], imax[x][0]+1);
        }
    }
    init(n);
    for(i=n; i>=1; i=j)
    {
        for(j=i; j>=1 && h[j].h == h[i].h; j--)
        {
            int x = h[j].n;
            int t = getmax(range[x][1]+1, n);
            if(ans < t+imax[x][0]+1) ans = t+imax[x][0]+1;
        }
        for(j=i; j>=1 && h[j].h == h[i].h; j--)
        {
            int x = h[j].n;
            set(range[x][0], dmax[x][0]+1);
        }
    }

    printf("%d", ans);

    return 0;
}

int dT = 0;

void dfs(int x)
{
    range[x][0] = ++dT;
    for(int i=0; i<map[x].size(); i++)
    {
        int xx = map[x][i];
        if(range[xx][0] != 0) continue;
        dfs(xx);
    }
    range[x][1] = dT;
}


int IT[400001];
int b;
void init(int n)
{
    for(b=1; b<=n; b*=2);
    for(int i=b*2; i>=1; i--)IT[i] = 0;
}

int max(int a, int b){return a>b?a:b;}

int getmax(int f, int r)
{
                /*printf("^^");
                for(int i=0; i<=20; i++)printf("%d ", IT[i]);
                printf("\n");*/
    f+=b; r+=b;
    int m = 0;
    while(f<r)
    {
        if(f%2 == 1) m = max(m, IT[f++]);
        if(r%2 == 0) m = max(m, IT[r--]);
        f/=2; r/=2;
    }
    if(f==r) m = max(m, IT[f]);
    return m;
}

void set(int x, int v)
{
    IT[x+=b] = v;
    while(x/=2) IT[x] = max(IT[x*2], IT[x*2+1]);
}