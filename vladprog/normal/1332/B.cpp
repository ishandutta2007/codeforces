#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int PR_SIZE=11;
const int PR[PR_SIZE]={2,3,5,7,11,13,17,19,23,29,31};
const int N=1010;

int lp[N];
int c[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=1;i<N;i++)
        for(int p:PR)
            if(i%p==0)
            {
                lp[i]=p;
                break;
            }

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int> m;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            int p=lp[a];
            if(!m[p])
                m[p]=m.size();
            c[i]=m[p];
        }
        cout<<m.size()<<"\n";
        for(int i=1;i<=n;i++)
            cout<<c[i]<<" ";
        cout<<"\n";
    }
}