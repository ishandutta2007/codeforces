#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
int main()
{   
    long long t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        char a[n][m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                a[i][j]='B';
            }
        }
        if(n==2&&m==2)
        {
            cout<<"WB"<<endl;
            cout<<"BB"<<endl;
        }
        else if(m>2)
        {
            a[0][m-1]='W';
            a[0][m-2]='W';
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<a[i][j];
                }
                cout<<endl;
            }
        }
        else
        {
            a[n-1][m-2]='W';
            a[n-2][m-1]='W';
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<a[i][j];
                }
                cout<<endl;
            }
            
        }
    }   
}