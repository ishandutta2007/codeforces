#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int q[N],a[N];
bool in[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            in[i]=false;
        set<int> s;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            q[i]=a[i];
            if(s.count(a[i]))
                a[i]=0;
            else
                s.insert(a[i]),
                in[a[i]]=true;
        }
        cout<<s.size()<<"\n";
//        for(int i=1;i<=n;i++)
//            cout<<a[i]<<" ";
//        cout<<"\n";
//        for(int i=1;i<=n;i++)
//            cout<<in[i]<<" ";
//        cout<<"\n";
        int start=0,last=0;
        for(int i=1;i<=n;i++)
            if(!in[i])
            {
                if(last)
                    a[last]=i;
                if(!start)
                    start=i;
                int j=i;
                while(a[j])
                    j=a[j];
                last=j;
            }
        if(last!=start||last==0)
            a[last]=start;
        else
        {
            int x=last;
            int y=q[last];
            int z=0;
            for(int i=1;i<=n;i++)
                if(a[i]==y)
                    z=i;
            a[x]=y;
            a[z]=x;
        }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}