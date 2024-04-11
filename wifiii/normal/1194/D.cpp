#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define F(i,n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=0;i<n;++i)
#define ALL(i) i.begin(),i.end()

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(!n) {cout<<"Bob\n";continue;}
        if(k%3)
        {
            if(n%3) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
        else if(k==3)
        {
            if(n%4) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
        else
        {
            int p=k/3,t=3*p+1;
            n=(n-1)%t+1;
            if(n==t) cout<<"Bob\n";
            else if(n==t-1) cout<<"Alice\n";
            else if(n%3==0) cout<<"Bob\n";
            else cout<<"Alice\n";
        }
    }
}