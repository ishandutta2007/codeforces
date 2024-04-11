#include <bits/stdc++.h>
#define ll long long int
#define inf 0x3f3f3f3f
#define con 400000
using namespace std;
int dis[3][2]={1,0,-1,0,0,1};
long long n;
long long a[2][con],sum[con];
long long c[2][con];
 ll val[2][con],xn[2][con];
 bool vis[2][con];
 bool is(int x,int y){ return x>=0&&x<2&&y>=0&&y<n; }
 void dfs(int x,int y,long long q)
 {
     vis[x][y]=true;
     c[x][y]=q;
     for(int i=0;i<3;i++){
         int x1=x+dis[i][0];
         int y1=y+dis[i][1];
         if(is(x1,y1)&&!vis[x1][y1]){
             xn[x1][y1]=xn[x][y]+q*a[x][y];
             dfs(x1,y1,q+1);
         }
     }
}
 
int main()
{
     cin>>n;
     for(int i=0;i<2;i++)
	 {
        for(int j=0; j<n;j++)
		{
            cin>>a[i][j];
            sum[j] += a[i][j];
        }
    }
     for(int i=n-2;i>=0;--i)
         sum[i] += sum[i+1];
     dfs(0,0,0);
     int up,down;
     if(n&1)
	 {
         up = n-1;
         long long cc = c[0][up];
         val[0][up] = cc*a[0][up] + (cc + 1)*a[1][up];
         down = n-2;
         cc = c[1][down];
         val[1][down] = cc*a[1][down] + (cc+1)*a[1][down+1] +(cc+2)*a[0][down+1] + (cc+3)*a[0][down];
     }
	 else
	 {
         up = n-2;
         long long cc = c[0][up];
         val[0][up] = cc*a[0][up] + (cc+1)*a[0][up+1] + (cc+2)*a[1][up+1] + (cc+3)*a[1][up];
         down = n-1;
         cc = c[1][down];
         val[1][down] = cc*a[1][down] + (cc+1)*a[0][down];
     }
 
     for(int i = up; i>=2;i=i-2){
         long long cc = c[0][i-2];
         val[0][i-2] = val[0][i] - sum[i]*2;
         val[0][i-2] += cc*a[0][i-2] + (cc+1)*a[0][i-1];
         cc += (n-i)*2 + 2;
         val[0][i-2] += cc*a[1][i-1] + (cc+1)*a[1][i-2];
     }
 
     for(int i = down; i>=2; i=i-2)
	 {
         long long cc = c[1][i-2];
         val[1][i-2] = val[1][i] - sum[i]*2;
         val[1][i-2] += cc*a[1][i-2] + (cc+1)*a[1][i-1];
         cc +=(n-i)*2 + 2;
         val[1][i-2] += cc*a[0][i-1] + (cc+1)*a[0][i-2];
      } 
      long long ans = 0;
      for(int i=0;i<2;++i){
          for(int j=0;j<n;++j){
              if((i+j)%2==0){
                  ans = max(ans,val[i][j]+xn[i][j]);
              }
          }
      }
      cout<<ans<<endl;
     return 0;
}