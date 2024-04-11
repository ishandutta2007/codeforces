#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define pb push_back
using namespace std;
int n,d,a[200][200],b[200],i,j,con,ans;
char ch;
main()
{
    cin>>n>>d;
    for (i=1;i<=d;i++){
        for (j=1;j<=n;j++){
            cin>>ch;
            a[i][j]=ch-'0';
            b[i]+=a[i][j];
        }
    }
    for (i=1;i<=d;i++){
        if (b[i]<n)con++;
        else {ans=max(con,ans);con=0;}
    }
ans=max(con,ans);
    cout<<ans<<endl;
}