#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    char a[n][m];
    for(int i=0;i<n;i++)scanf("%s",&a[i]);
    char ans[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)ans[i][j]='.';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!='S')continue;
            //cout<<"mudja"<<endl;
            ans[i][j]='S';
            if(i>0&&a[i-1][j]!='S')ans[i-1][j]='D';
            if(j>0&&a[i][j-1]!='S')ans[i][j-1]='D';
            if(i<n-1&&a[i+1][j]!='S')ans[i+1][j]='D';
            if(j<m-1&&a[i][j+1]!='S')ans[i][j+1]='D';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='W'&&ans[i][j]=='D'){
                printf("No");
                return 0;
            }else{
                if(a[i][j]=='W')ans[i][j]='W';
            }
        }
    }
    printf("Yes\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)printf("%c",ans[i][j]);
        printf("\n");
    }
    return 0;
}