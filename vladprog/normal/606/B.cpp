#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,x0,y0;
    scanf("%d%d%d%d%*c",&x,&y,&x0,&y0);
    int a[x+1][y+1];
    memset(a,255,sizeof(a));
    a[x0][y0]=0;
    int k=0;
    //printf("k=%d x=%d y=%d\n",k,x0,y0);
    while(true)
    {
        char c;
        if(scanf("%c",&c)<1)break;
        bool stop=false;
        switch(c)
        {
            case 'L': y0=max(y0-1,1); break;
            case 'R': y0=min(y0+1,y); break;
            case 'U': x0=max(x0-1,1); break;
            case 'D': x0=min(x0+1,x); break;
            default: stop=true; break;
        }
        if(stop)break;
        k++;
        if(a[x0][y0]==-1)a[x0][y0]=k;
        //printf("k=%d x=%d y=%d\n",k,x0,y0);
    }
    int b[k+1];
    memset(b,0,sizeof(b));
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
            if(a[i][j]==-1)
                b[k]++;
            else
                b[a[i][j]]++;
    for(int i=0;i<=k;i++)
        printf("%d ",b[i]);
}