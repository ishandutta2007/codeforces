#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010;

int n,k;
vector<int> s[N];

int ask(vector<int> a)
{
    if(a.empty())
        return 0;
    vector<int> b;
    for(int x:a)
        for(int y:s[x])
            b.push_back(y);
    cout<<"? "<<b.size()<<" ";
    for(int y:b)
        cout<<y<<" ";
    cout<<endl;
    int resp;
    cin>>resp;
    return resp;
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
        cin>>n>>k;
        for(int i=1;i<=k;i++)
        {
            s[i].clear();
            int c;
            cin>>c;
            while(c--)
            {
                int x;
                cin>>x;
                s[i].push_back(x);
            }
        }

        cout<<"? "<<n<<" ";
        for(int i=1;i<=n;i++)
            cout<<i<<" ";
        cout<<endl;
        int mx;
        cin>>mx;

        vector<int> v;
        for(int i=1;i<=k;i++)
            if((i&1)==0)
                v.push_back(i);
        int cur=ask(v);

        int mask=(mx>cur?1:0);
        for(int bit=1;bit<=9;bit++)
        {
            v.clear();
            int full=(1<<(bit+1))-1;
            for(int i=1;i<=k;i++)
                if((i&full)==mask)
                    v.push_back(i);
            cur=ask(v);
            if(mx>cur)
                mask|=1<<bit;
        }

        set<int> oth;
        for(int i=1;i<=n;i++)
            oth.insert(i);
        for(int x:s[mask])
            oth.erase(x);
        cout<<"? "<<oth.size()<<" ";
        for(int x:oth)
            cout<<x<<" ";
        cout<<endl;
        int ans;
        cin>>ans;

        cout<<"! ";
        for(int i=1;i<=k;i++)
            cout<<(i==mask?ans:mx)<<" ";
        cout<<endl;

        string resp;
        cin>>resp;
        if(resp=="Incorrect")
            exit(0);
    }
}