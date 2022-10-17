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

int a[10005];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int i1=0;
        ii cin>>a[i],a[i+n]=a[i];
        ii if(a[i]==1) i1=i;
        int ok=1;
        for(int i=i1;i<i1+n-1;++i) if(a[i+1]-a[i]!=1) ok=0;
        if(ok) {cout<<"YES"<<endl;continue;}
        ok=1;
        for(int i=n+1;i<=2*n;++i) if(a[i]==1) i1=i;
        for(int i=i1;i>i1-n+1;--i) if(a[i-1]-a[i]!=1) ok=0;
        if(ok) {cout<<"YES"<<endl;continue;}
        cout<<"NO"<<endl;
    }
}