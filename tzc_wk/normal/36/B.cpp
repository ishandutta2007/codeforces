#include <bits/stdc++.h>
using namespace std;
int n,m=1,k;
char s[300][300],st[7][7],tmp[300][300];
int main()
{
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w", stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++)
    		cin>>st[i][j];
    while(k--){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                for(int ii=1;ii<=n;ii++){
                    for(int jj=1;jj<=n;jj++){
                        if(s[i][j]=='*') tmp[(i-1)*n+ii][(j-1)*n+jj] = s[i][j];
                        else tmp[(i-1)*n+ii][(j-1)*n+jj] = st[ii][jj];
                    }
                }
            }
        }
        m*=n;
        for(int i=1;i<=m;i++) strcpy(s[i]+1, tmp[i]+1);
    }
    for(int i=1;i<=m;i++) puts(s[i]+1);
    return 0;
}