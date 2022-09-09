#include <bits/stdc++.h>
using namespace std;
const int N=200050;
const int inf=1e9+7;
int sum[256][N];
char s[N];
int Get(int j, int l, int r){ return sum[j][r]-sum[j][l-1];}
int main()
{
    int n,i,x,y,sol=inf,tx=0,ty=0;
    scanf("%i",&n);
    scanf("%s",s+1);
    for(i=1;i<=n;i++)
    {
        sum['L'][i]=sum['L'][i-1];
        sum['R'][i]=sum['R'][i-1];
        sum['D'][i]=sum['D'][i-1];
        sum['U'][i]=sum['U'][i-1];
        sum[s[i]][i]++;
        if(s[i]=='L') tx--;
        if(s[i]=='R') tx++;
        if(s[i]=='U') ty++;
        if(s[i]=='D') ty--;
     }
    scanf("%i %i",&x,&y);
    if(tx==x && ty==y) return 0*printf("0\n");
    for(i=1;i<=n;i++)
    {
        int top=n,bot=i,mid,ans=-1;
        while(top>=bot)
        {
            mid=top+bot>>1;
            int a=Get('U',1,i-1)+Get('U',mid+1,n)-Get('D',1,i-1)-Get('D',mid+1,n);
            int b=Get('R',1,i-1)+Get('R',mid+1,n)-Get('L',1,i-1)-Get('L',mid+1,n);
            if(abs(a-y)+abs(x-b)<=mid-i+1 && (abs(a-y)+abs(x-b))%2==(mid-i+1)%2) ans=mid,top=mid-1;
            else bot=mid+1;
        }
        if(ans!=-1) sol=min(sol,ans-i+1);
    }
    if(sol==inf) printf("-1\n");
    else printf("%i\n",sol);
    return 0;
}