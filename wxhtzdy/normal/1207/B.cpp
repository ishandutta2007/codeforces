#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%i",&a[i][j]);
    bool was[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)was[i][j]=0;
    vector<pair<int,int>> v;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            //if(was[i][j])continue;
            if(a[i][j]==1){
                if(a[i+1][j]==1&&a[i][j+1]==1&&a[i+1][j+1]==1){
                    v.push_back({i+1,j+1});
                    was[i][j]=1;
                    was[i+1][j]=1;
                    was[i][j+1]=1;
                    was[i+1][j+1]=1;
                }
            }
        }
    }
    /*for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(a[i][j]==1&&a[i+1][j]==1&&!was[i+1][j]){
                was[i+1][j]=1;
                was[i+1][j+1]=1;
                was[i][j+1];
                v.push_back({i+1,j+1});
            }
        }
    }*/
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)if(a[i][j]!=was[i][j])return 0*printf("-1");
    }
    printf("%i\n",(int)v.size());
    for(auto c:v)printf("%i %i\n",c.first,c.second);
    return 0;
}