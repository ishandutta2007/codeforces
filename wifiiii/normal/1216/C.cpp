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
 
int a[5],b[5],c[5],d[5];
bool ainb(int *a,int *b)
{
    return a[1]>=b[1] && a[2]<=b[2] && a[3]>=b[3] && a[4]<=b[4];
}
int init()
{
    if(a[1] > b[2] || a[2] < b[1] || a[3] > b[4] || a[4] < b[3]) return 0;
    if( !(a[1]>=b[1] && a[2]<=b[2])  && !(a[3]>=b[3] && a[4]<=b[4]) ) return 0;
    if(  (b[1]> a[1] && b[2]< a[2]) ||   (b[3]> a[3] && b[4]< a[4]) ) return 0;
    if(a[1]>=b[1] && a[2]<=b[2])
    {
        if(b[4] >= a[4])
        {
            d[3] = a[3], d[4] = b[3];
            d[1] = a[1], d[2] = a[2];
        }
        else
        {
            d[3] = b[4], d[4] = a[4];
            d[1] = a[1], d[2] = a[2];
        }
    }
    else
    {
        if(b[2] >= a[2])
        {
            d[1] = a[1], d[2] = b[1];
            d[3] = a[3], d[4] = a[4];
        }
        else
        {
            d[1] = b[2], d[2] = a[2];
            d[3] = a[3], d[4] = a[4];
        }
    }
    return 1;
}
int main()
{
    for(int i=1;i<=4;++i) cin>>a[i];
    for(int i=1;i<=4;++i) cin>>b[i];
    for(int i=1;i<=4;++i) cin>>c[i];
    swap(a[2],a[3]);
    swap(b[2],b[3]);
    swap(c[2],c[3]);
    if(ainb(a,b) || ainb(a,c)) return cout<<"NO"<<endl,0;
    int ok = init();
    if(!ok) return cout<<"YES"<<endl,0;
    if(ainb(d,c)) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}