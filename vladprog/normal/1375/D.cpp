#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010;

int n;
int a[N];
bool b[N];

int mex()
{
    for(int i=0;i<=n;i++)
        b[i]=false;
    for(int i=1;i<=n;i++)
        b[a[i]]=true;
    for(int i=0;i<=n;i++)
        if(!b[i])
            return i;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int val=0;
        vector<int> ans;
        while(!is_sorted(a+1,a+n+1))
        {
            int m=mex();
            int op;
            if(m<=val)
                op=m+1,
                val++;
            else
                op=m;
            ans.push_back(op);
            a[op]=m;
        }
        cout<<ans.size()<<"\n";
        for(int op:ans)
            cout<<op<<" ";
        cout<<"\n";
    }
}