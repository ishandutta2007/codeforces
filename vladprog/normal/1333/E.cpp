#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510;

int a[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    if(n<=2)
        cout<<-1,exit(0);
    if(n==3)
        cout<<"2 3 4\n8 1 7\n6 5 9",exit(0);
    int t=1;
    for(int i=1;i<=n-1;i++)
    {
        int mx=n;
        if(i==n-1)
            mx-=2;
        if(i==n-3)
            mx--;
        if(i%2==1)
            a[i][1]=t++;
        else
            a[i][2]=t++;
        for(int j=3;j<=mx;j++)
            a[i][j]=t++;
        if(i%2==0)
            a[i][1]=t++;
        else
            a[i][2]=t++;
    }
    if(n%2==1)
        a[n][1]=t++;
    else
        a[n][2]=t++;
    if(n%2==0)
        a[n][1]=t++;
    else
        a[n][2]=t++;
    for(int j=3;j<=n-2;j++)
        a[n][j]=t++;
    a[n][n]=t++;
    a[n][n-1]=t++;
    a[n-1][n]=t++;
    a[n-1][n-1]=t++;
    a[n-3][n]=t++;
    for(int i=1;i<=n;i++,cout<<"\n")
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
}