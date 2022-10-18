#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int cnt[N],c[N];
vector<int> vals[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    while(n--)
    {
        int m;
        cin>>m;
        cnt[m]++;
    }
//    for(int i=1;i<=k;i++)
//        cout<<cnt[i]<<" ";
//    cout<<endl;
    for(int i=1;i<=k;i++)
        cin>>c[i];
    set<int,greater<int>> s;
    for(int i=1,last=1;i<=k;i++)
    {
        if(c[i]!=c[last])
            last=i;
        while(cnt[i]--)
            vals[last].push_back(i);
    }
    for(int i=1,last=1;i<=k;i++)
        if(!vals[i].empty())
            s.insert(i);
    vector<vector<int>> ans;
    while(!s.empty())
    {
//        for(int x:s)
//        {
//            cout<<x<<" : ";
//            for(int y:vals[x])
//                cout<<y<<" ";
//            cout<<endl;
//        }
        ans.push_back(vector<int>());
        for(auto it=s.begin(),nxt=next(it);it!=s.end();it=nxt,(nxt==s.end()?nxt:++nxt))
        {
            while(!vals[*it].empty()&&ans.back().size()<c[*it])
                ans.back().push_back(vals[*it].back()),
                vals[*it].pop_back();
            if(vals[*it].empty())
                s.erase(it);
        }
//        for(int x:ans.back())
//            cout<<x<<" ";
//        cout<<"\n=========="<<endl;
    }
    cout<<ans.size()<<"\n";
    for(auto v:ans)
    {
        cout<<v.size()<<" ";
        for(int x:v)
            cout<<x<<" ";
        cout<<"\n";
    }
}