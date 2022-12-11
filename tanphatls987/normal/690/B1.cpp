#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;

int a[maxn][maxn], n, cnt;

void nhap()
{
    scanf("%d\n", &n);
    cnt = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char c = getchar();
            a[i][j] = c - '0';
            if (a[i][j] == 3)
            {
                printf("no\n");
                exit(0);
                
            }
            cnt += (a[i][j] != 0);
        }
        scanf("\n");
    }
}

bool ktr(int lx, int ly)
{
    int rx = 0, ry = 0;
    for(int i=lx+1; i<=n; i++)
    if (a[i][ly] == 1)
    {
        rx = i;
        break;
    }
    
    for(int i=ly+1; i<=n; i++)
    if (a[lx][i] == 1)
    {
        ry = i;
        break;
    }
    
    //cout<<lx<<' '<<rx<<' '<<ly<<' '<<ry<<endl;
    
    if (rx == 0 || ry == 0)
        return 0;
        
    for(int i=lx+1; i<rx; i++)
    {
        if (a[i][ly] != 2 || a[i][ry] != 2)
            return 0;
    }
    
    for(int i=ly+1; i<ry; i++)
    {
        if (a[lx][i] !=2 || a[rx][i] != 2)
            return 0;
    }
    
    int dem = 0;
    
    for(int i=lx+1; i<rx; i++)
    {
        for(int j=ly+1; j<ry; j++)
        {
            if (a[i][j] != 4)
                return 0;
            dem ++;
        }
    }
    
    if ((rx - lx + 1) * (ry - ly +1) != cnt) 
        return 0;
        
    //cout<<'a'<<endl;
        
    if (dem == 0)
        return 0;
    return 1;
}

bool tinh()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        if (a[i][j] == 1)
        {
            return ktr(i, j);
        }
    }
    return 0;
}

int main()
{
    nhap();
    if (tinh())
        printf("yes\n");
    else printf("no\n");
    return 0;
}