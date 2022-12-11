#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=4000;

int a[maxi]={0};
int n,v,i,pre,now,tmp,ans,col,idx,val;

int readfile()
{
    scanf("%d%d",&n,&v);
    for(i=0;i<n;i++) {scanf("%d%d",&idx,&val);a[idx]+=val;}
}
int main()
{
    readfile();
    for(i=1;i<=3001;i++)
    {
        col=min(v,a[i-1]);
        ans+=col;tmp=v-col;
        col=min(tmp,a[i]);
        ans+=col;a[i]-=col;
    }
    printf("%d",ans);
}