#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[100005],b[100005];
int d[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n+1;++i) cin>>a[i],b[i]=a[i];
    int ok = 1;
    assert(a[1] == 1);
    int h=0;
    for(int i=1;i<=n;++i) if(a[i]>1 && a[i+1]>1) h=i,ok=0;
    if(ok) return cout<<"perfect"<<endl,0;
    cout<<"ambiguous"<<endl;
    int tp=0;
    for(int i=1;i<=n+1;++i)
    {
        while(a[i])
        {
            ++tp;
            --a[i];
            if(!d[i]) d[i]=tp;
            cout<<d[i-1]<<" ";
        }
    }
    cout<<endl;
    tp=0;
    d[h]++;
    int cnt=0;
    for(int i=1;i<=n+1;++i)
    {
        while(b[i])
        {
            --b[i];
            if(i==h+1 && cnt++==1) cout<<d[i-1]-1<<" ";
            else cout<<d[i-1]<<" ";
        }
    }
    cout<<endl;
}