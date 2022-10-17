#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        ii cin>>a[i];
        int ok=1;
        for(int i=1;i<n;++i)
        {
            m+=a[i]-max(0, a[i+1]-k);
            if(m<0) {ok=0;break;}
        }
        cout<< (ok?"YES":"NO") <<endl;
    }
}