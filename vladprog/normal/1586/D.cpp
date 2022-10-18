#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int n;
int a[N],p[N];

int ask()
{
    cout<<"? ";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    int k;
    cin>>k;
    return k;
}

void answer()
{
    cout<<"! ";
    for(int i=1;i<=n;i++)
        cout<<p[i]<<" ";
    cout<<endl;
    exit(0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n-1;i++)
        a[i]=1;
    for(int y=2;y<=n;y++)
    {
        a[n]=y;
        int k=ask();
        if(k)
            p[k]=y-1;
    }
    for(int i=1;i<=n-1;i++)
        a[i]=n;
    for(int y=1;y<=n-1;y++)
    {
        a[n]=y;
        int k=ask();
        if(k)
            p[k]=y-n;
    }
    int m=*min_element(p+1,p+n+1);
    for(int i=1;i<=n;i++)
        p[i]-=m,
        p[i]++;
    answer();
}