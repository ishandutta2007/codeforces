#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define x first
#define y second

int query(int t,int i,int j,int k)
{
    cout<<t<<" "<<i<<" "<<j<<" "<<k<<endl;
    int ans;
    cin>>ans;
    if(t==2)
        ans*=-1;
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<pii> up,down;
    for(int i=3;i<=n;i++)
    {
        int area=query(1,1,2,i);
        int sign=query(2,1,2,i);
        if(sign==1)
            down.push_back(mp(area,i));
        else
            up.push_back(mp(area,i));
    }

    sort(down.begin(),down.end());
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    auto it=l.begin();
    for(auto p:down)
    {
        int i=p.y;
        if(query(2,*it,i,*next(it))==-1)
            l.insert(next(it),i),
            it++;
        else
            l.insert(it,i),
            it--;
    }
    vector<int> ans(l.begin(),l.end());

    sort(up.begin(),up.end());
    l.clear();
    l.push_back(1);
    l.push_back(2);
    it=l.begin();
    for(auto p:up)
    {
        int i=p.y;
        if(query(2,*it,i,*next(it))==1)
            l.insert(next(it),i),
            it++;
        else
            l.insert(it,i),
            it--;
    }
    l.pop_front();
    l.pop_back();
    for(auto i=l.rbegin();i!=l.rend();i++)
        ans.push_back(*i);

    cout<<"0 ";
    for(int x:ans)
        cout<<x<<" ";
    cout<<endl;
}