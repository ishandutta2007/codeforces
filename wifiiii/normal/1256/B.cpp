#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[105],f[105];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        memset(f,0,sizeof(f));
        int n;cin>>n;
        ii cin>>a[i];
        for(int i=1;i<=n;++i) {
            int pos=1;
            while(a[pos]!=i) ++pos;
            while(pos>1 && f[pos]==0 && a[pos]<a[pos-1]) swap(a[pos-1],a[pos]),f[pos]=1,pos--;
        }
        ii cout<<a[i]<<" ";cout<<endl;
    }
}