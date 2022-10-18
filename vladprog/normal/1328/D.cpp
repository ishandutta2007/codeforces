#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int t[N],c[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>t[i];
        int start=-1;
        bool all_eq=true;
        for(int i=0;i<n;i++)
            if(t[i]==t[(i+1)%n])
                start=(i+1)%n;
            else
                all_eq=false;
        int k;
        if(all_eq)
            k=1,
            fill(c,c+n,1);
        else if(start==-1)
        {
            if(n%2==0)
                k=2;
            else
                k=3;
            for(int i=0;i<n;i++)
                c[i]=i%2+1;
            if(n%2==1)
                c[n-1]=3;
        }
        else
        {
            k=2;
            for(int i=start;i<start+n;i++)
                c[i%n]=i%2+1;
        }
        cout<<k<<"\n";
        for(int i=0;i<n;i++)
            cout<<c[i]<<" ";
        cout<<"\n";
    }
}