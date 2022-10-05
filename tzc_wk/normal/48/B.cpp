#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b,cd[50][50],ans=2500,sum=0;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>cd[i][j];
        }
    }
    cin>>a>>b;
    for (int i=0;i<n-a+1;i++){
        for (int j=0;j<m-b+1;j++){
            for (int k=i;k<i+a;k++){
                for (int l=j;l<j+b;l++){
                    sum+=cd[k][l];
                }
            }
            ans=min(sum,ans);
            sum=0;
        }
    }
    for (int i=0;i<n-b+1;i++){
        for (int j=0;j<m-a+1;j++){
            for (int k=i;k<i+b;k++){
                for (int l=j;l<j+a;l++){
                    sum+=cd[k][l];
                }
            }
            ans=min(sum,ans);
            sum=0;
        }
    }
    cout<<ans;
    return 0;
}