#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
 
int n,s,e;
long long int x[5050],a[5050],b[5050],c[5050],d[5050];
 
const long long int INF=9999999999999;
 
long long int memo[5050][5050];
 
long long int pd(int i, int j)//i=until, j=right arrows, k=left arrow offset
{
    if(memo[i][j]!=-1)
        return memo[i][j];
    long long int la=j+(i>s?-1:0)+(i>e?1:0);
    long long int &ans=memo[i][j];

    if(la<0 || j<0 ||(la==0&&j==0&&i<n&&i!=0)) return ans=INF;
    if(i==n)
    {
        //std::cout << "on " << i << ", " << j << ", " << j+k-1 << '\n';
        if(j==0 && la==0)
            return ans=0;
        else
            return ans=INF;
    }
    
   
   
   
    long long int fl,fr,tl,tr;
    tl=c[i];
    tr=d[i];
    fr=b[i];
    fl=a[i];
    long long int cost=la+j;
    if(i==0)
        cost=0;
    else
        cost*=x[i]-x[i-1];
   
    
   
    //std::cout << "on " << i << ", " << j << ", " << la << '\n';
    //printf("fl=%lli, fr=%lli, tl=%lli, tr=%lli\n",fl,fr,tl,tr);
   
    ans=INF;
   
    if(n-i<j || n-i<la)
    {
        return ans;
    }
   
   
   
    if(i==s)
    {
        ans=std::min(ans,cost+pd(i+1,j)+tl);//tirando <-
        ans=std::min(ans,cost+pd(i+1,j+1)+tr);//criando ->
    }
    else if(i==e)
    {
        ans=std::min(ans,cost+pd(i+1,j-1)+fl);//fechando ->
        ans=std::min(ans,cost+pd(i+1,j)+fr);//criando <-
    }
    else
    {
        if((j>1 && la>0)||(j>0 && la>1)||(i==n-1 && j==1 && la==1))
            ans=std::min(ans,cost+pd(i+1,j-1)+fl+tl);//fechando
        ans=std::min(ans,cost+pd(i+1,j+1)+fr+tr);//abrindo
        if(j>0)
            ans=std::min(ans,cost+pd(i+1,j)+fl+tr);//->->
        if(la>0)
            ans=std::min(ans,cost+pd(i+1,j)+fr+tl);//<-<-
    }
    //std::cout << "returned " << ans << " on " << i << ", " << j << ", " << j+k-1 << " cost: " << cost<< '\n';
    //printf("fl=%lli, fr=%lli, tl=%lli, tr=%lli\n",fl,fr,tl,tr);
    return ans;
}
 
int main()
{
    std::cin >> n >> s >> e;
    s--;e--;
    for(int i=0;i<n;i++)
        std::cin >> x[i];
    for(int i=0;i<n;i++)
        std::cin >> a[i];
    for(int i=0;i<n;i++)
        std::cin >> b[i];
    for(int i=0;i<n;i++)
        std::cin >> c[i];
    for(int i=0;i<n;i++)
        std::cin >> d[i];
    memset(memo,-1,sizeof memo);
    std::cout << pd(0,0) << '\n';
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(memo[i][j][k]<INF && visit[i][j][k])
                    printf("on %i, %i, %i returned %lli\n",i,j,j+k-1,memo[i][j][k]);
            }
        }
    }*/
   
}