#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>
#include <functional>

int f[1000][1000][20];
char p[1000][1000][20];
int n,m,k,a[1000][1000];

int main(){
//      freopen("","r",stdin);
//      freopen("","w",stdout);
        scanf("%d%d%d\n",&n,&m,&k);
        ++k;
        for (int i=1;i<=n;i++){
                char c;
                for (int j=1;j<=m;j++){ 
                        scanf("%c",&c);
                        a[i][j]=c-'0';
                }
                scanf("\n");
        }
        memset(f,-1,sizeof(f));
        for (int j=1;j<=m;j++)
                f[n][j][a[n][j]%k]=a[n][j];
        for (int i=n;i>1;i--)
                for (int j=1;j<=m;j++)
                        for (int q=0;q<k;q++)if(f[i][j][q]>-1){
                                int o;
                                if (j>1)o=f[i][j][q]+a[i-1][j-1];
                                o%=k;
                                if (j>1&&f[i][j][q]+a[i-1][j-1]>f[i-1][j-1][o]){
                                        f[i-1][j-1][o]=f[i][j][q]+a[i-1][j-1];
                                        p[i-1][j-1][o]='L';
                                }       
                                if (j<m)o=f[i][j][q]+a[i-1][j+1];
                                o%=k;
                                if (j<m&&f[i][j][q]+a[i-1][j+1]>f[i-1][j+1][o]){
                                        f[i-1][j+1][o]=f[i][j][q]+a[i-1][j+1];
                                        p[i-1][j+1][o]='R';
                                }
                        }
        int y=1;
        for (int j=2;j<=m;j++)
                if (f[1][j][0]>f[1][y][0])
                        y=j;
        printf("%d\n",f[1][y][0]);
        if (f[1][y][0]<0)return 0;
        int x=0,z=0; 
        std::string s="";
        for (int x=1;x<n;x++){
                s=p[x][y][z]+s;
                int yy=y,zz=z;
                zz-=a[x][y];
                while (zz<0)zz+=k;
                if (p[x][y][z]=='R')
                        yy--;
                else yy++;
                y=yy;z=zz;
        }
        printf("%d\n",y);
        for (int i=0;i<n-1;i++)
                putchar(s[i]);
        return 0;
}