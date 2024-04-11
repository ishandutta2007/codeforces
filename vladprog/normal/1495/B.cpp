#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int p[N];
int l[N],r[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(10);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    l[0]=r[n+1]=0;
    for(int i=1;i<=n;i++)
        l[i]=(p[i]>p[i-1]?l[i-1]+1:1);
    for(int i=n;i>=1;i--)
        r[i]=(p[i]>p[i+1]?r[i+1]+1:1);
    int m=max(*max_element(l+1,l+n+1),
              *max_element(r+1,r+n+1));
    set<int> lmax,rmax;
    for(int i=1;i<=n;i++)
    {
        if(l[i]==m)
            lmax.insert(i);
        if(r[i]==m)
            rmax.insert(i);
    }
    if(lmax.size()+rmax.size()==1)
    {
        int pos=(lmax.empty()?*rmax.begin():*lmax.begin());
        int a=l[pos],b=r[pos];
        if(a<b)
            swap(a,b);
        if(a%2)
            a--;
        cout<<(b-1>a-1)<<"\n";
    }
    else if(lmax.size()>=2||
            rmax.size()>=2)
        cout<<0<<"\n";
    else if(*lmax.begin()==*rmax.begin()&&
            m%2)
        cout<<1<<"\n";
    else
        cout<<0<<"\n";
}