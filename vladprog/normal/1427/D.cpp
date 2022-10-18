#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=100;

int n;
vector<int> c;
vector<vector<int>> ans;

void op(vector<int> d)
{
//    for(int x:d)
//        cout<<x<<" ";
//    cout<<endl;
//    assert(accumulate(d.begin(),d.end(),0ll)==n);
    for(auto it=d.begin();it!=d.end();)
        if(*it==0)
            d.erase(it);
        else
            it++;
//    assert(accumulate(d.begin(),d.end(),0ll)==n);
    if(d.size()==1)
        return;
    ans.push_back(d);
    vector<int> v;
    while(!d.empty())
    {
        int len=d.back();
        d.pop_back();
        vector<int> cur;
        while(len--)
            cur.push_back(c.back()),
            c.pop_back();
        while(!cur.empty())
            v.push_back(cur.back()),
            cur.pop_back();
    }
    c=v;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    c.resize(n);
    for(int i=0;i<n;i++)
        cin>>c[i];
    vector<int> ord;
    for(int i=1;i<=n;i++)
        if(i%2)
            ord.push_back(i);
        else
            ord.insert(ord.begin(),i);
    for(int i=1;i<=n;i++)
    {
        int cur;
        for(int j=0;j<n;j++)
            if(ord[j]==i)
                cur=j+1;
        int pos;
        for(int j=0;j<n;j++)
            if(c[j]==cur)
                pos=j;
        if(i%2)
            op({pos,n-pos-i+1,i-1});
        else
            op({i-1,pos-i+2,n-pos-1});
    }

//    cout<<"\n";
//    for(int x:c)
//        cout<<x<<" ";
//    cout<<"\n\n";

    cout<<ans.size()<<"\n";
    for(auto x:ans)
    {
        cout<<x.size()<<" ";
        for(int y:x)
            cout<<y<<" ";
        cout<<"\n";
    }
}