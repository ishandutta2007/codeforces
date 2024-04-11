#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
int b[maxn];
int c[maxn];
int h[maxn];
void check(int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>n || y>m) return;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            c[abs(x-i)+abs(y-j)]++;
        }
    }
    for(int i=0;i<=(n*m);++i)
    {
        if(c[i]!=b[i])
        {
            for(int j=0;j<=(n*m);++j)
            {
                c[j]=0;
            }
            return;
        }
    }
    cout<<n<<' '<<m<<endl;
    cout<<x+1<<' '<<y+1<<endl;
    exit(0);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) {cin>>a[i];b[a[i]]++;}
    for(int i=1;i*i<=n;++i)
    {
        int j=(n/i);
        if((i*j)!=n) continue;
        int rc;
        for(int i=1;i<maxn;++i)
        {
            if(b[i]!=4*i)
            {
                rc=(i-1);
                break;
            }
        }
        int d;
        for(int i1=(maxn-1);i1>=0;i1--)
        {
            if(b[i1])
            {
                d=(i+j-2-i1);
                break;
            }
        }
        int x1=rc;
        int y1=d-rc;
        check(x1,y1,i,j);
        int x2=d-rc;
        int y2=rc;
        check(x2,y2,i,j);
    }
    cout<<(-1);
    return 0;
}