#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define tick printf("tick\n")
using namespace std;

const int maxd=100000;

int a[25],b[2][25],i,j,n,k,l,key,tmp,rat,imp,ans;
char s[3];
int readfile()
{
    //freopen("443c.txt","r",stdin);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        if (s[0]=='R') tmp=0;
        if (s[0]=='G') tmp=1;
        if (s[0]=='B') tmp=2;
        if (s[0]=='Y') tmp=3;
        if (s[0]=='W') tmp=4;
        a[5*tmp+s[1]-'1']=1;
    }
    //for(i=0;i<5;i++)
            //for(j=0;j<5;j++) printf("%d",h[i][j]);
}
int solve()
{
    int tmp;
    //for(i=0;i<5;i++)
            //for(j=0;j<5;j++) printf("%d",a[i][j]);
    ans=11;
    for(k=0;k<1<<10;k++)
    {

        memset(b,0,sizeof(b));
        int step=0;
        for(j=0;j<5;j++) if(1<<j&k)
        {
            step++;
            for(i=0;i<5;i++) b[0][5*i+j]++;
        }
        for(j=5;j<10;j++) if(1<<j&k)
        {
            step++;
            for(i=0;i<5;i++) b[1][(j-5)*5+i]++;
        }
        //printf("%d %d\n",k,step);
        int fail=0;
        for(i=0;i<25;i++) if (a[i])
            for(j=i+1;j<25;j++) if (a[j])
        {
            if (i/5==j/5)
            {
                if (b[0][j]+b[0][i]==0) fail=1;
            }
            if (i%5==j%5)
            {
                if (b[1][j]+b[1][i]==0) fail=1;
            }
            if (b[1][j]+b[1][i]+b[0][j]+b[0][i]==0) fail=1;
            if (fail) break;
        }
        /*do
        {
            imp=0;
            for(i=0;i<5;i++)
                for(j=0;j<5;j++)
            {
                rat=0;
                for(l=0;l<5;l++) if(l!=j&&b[i][l]>=a[i][l]) rat++;
                if (rat==4) {b[i][j]++;imp=1;}
                rat=0;
                for(l=0;l<5;l++) if(l!=i&&b[l][j]>=a[l][j]) rat++;
                if (rat==4) {b[i][j]++;imp=1;}
            }
        }while (imp);
        key=0;
        for(i=0;i<5;i++)
            for(j=0;j<5;j++) key+=(b[i][j]>=a[i][j]);*/
        if(fail==0&&step<ans) ans=step;
    }
    cout<<ans;
}
int main()
{
    readfile();
    solve();
}