#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],jump[N],c[N],l[N],r[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!l[a[i]])
            l[a[i]]=i;
        r[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
        if(l[a[i]]!=r[a[i]])
            jump[l[a[i]]]=r[a[i]];
    int last=0;
    while(last<n)
    {
        int x=last+1;
        if(!jump[x])
        {
            last++;
            continue;
        }
        while(true)
        {
            int y=jump[x];
//            cout<<x<<" "<<y<<"\n";
            int best=y,pos=0;
            for(int i=max(last,x)+1;i<=y-1;i++)
                tie(best,pos)=max(pair(best,pos),pair(jump[i],i));
            for(int i=max(last,x)+1;i<=y-1;i++)
                if(i!=pos)
                    c[i]=1;
            last=y-1;
            if(pos)
                x=pos;
            else
                break;
        }
    }
//    for(int i=1;i<=n;i++)
//        cout<<c[i]<<" ";
//    cout<<"\n";
    cout<<accumulate(c+1,c+n+1,0ll)<<"\n";
}