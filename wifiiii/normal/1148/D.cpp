
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

struct node
{
    int a,b,id;
    bool operator < (const node & n) const {
        return a<n.a || (a==n.a && b<n.b);
    }
};
vector<node> v1,v2;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,n)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
        {
            v1.push_back(node{b,a,i});
        }
        else if(a<b)
        {
            v2.push_back(node{a,b,i});
        }
    }
    if(v1.size() > v2.size())
    {
        cout<<v1.size()<<endl;
        sort(v1.begin(),v1.end());
        for(node n:v1) cout<<n.id<<" ";
    }
    else
    {
        cout<<v2.size()<<endl;
        sort(v2.begin(),v2.end());
        reverse(v2.begin(),v2.end());
        for(node n:v2) cout<<n.id<<" ";
    }
    cout<<endl;
}