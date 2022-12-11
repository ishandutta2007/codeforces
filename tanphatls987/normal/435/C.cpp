#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <string.h>
using namespace std;

const int maxi=1000;
int p[2*maxi+1][maxi]={0},a[maxi],n,i,j,power,top,bot,curx,cury;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    top=maxi;bot=maxi;cury=maxi;
    curx=0;
    power=1;
    for(i=0;i<n;i++)
    {
        for(j=curx;j<curx+a[i];j++)
        {
            //printf("%d %d\n",cury-power*(j-curx+1),j);
            p[cury-power*(j-curx+1)][j]=power;
        }
        cury-=power*(a[i]+1);
        curx+=a[i];
        if (cury<top) top=cury;
        if (cury>bot) bot=cury;
        //printf("%d %d %d %d\n",top,bot,i,j);
        power*=-1;
    }
    for(i=top+1;i<bot;i++)
    {
        for(j=0;j<curx;j++)
        {
            if (p[i][j]==1) printf("/");
            else if (p[i][j]==0) printf(" ");
            else if (p[i][j]==-1) printf("\\");
        }
        printf("\n");
    }
}