#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int n;
vector<int> g[N];
int cnt[N];

int calc_cnt(int v,int p)
{
    int&res=cnt[v]=1;
    for(int to:g[v])
        if(to!=p)
            res+=calc_cnt(to,v);
    return res;
}

int find_centroid(int v,int p)
{
    for(int to:g[v])
        if(to!=p&&cnt[to]*2>=n)
            return find_centroid(to,v);
    return v;
}

int calc_ans(int v,int p,int d)
{
    int ans=d;
    for(int to:g[v])
        if(to!=p)
            ans+=calc_ans(to,v,d+1);
    return ans;
}

vector<int> sub[N];

void find_sub(int v,int p,int ind)
{
    sub[ind].push_back(v);
    for(int to:g[v])
        if(to!=p)
            find_sub(to,v,ind);
}

int v[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    calc_cnt(1,0);
    int c=find_centroid(1,0);
    cout<<calc_ans(c,0,0)*2<<"\n";
    int mn=1e18;
    for(int to:g[c])
    {
        find_sub(to,c,to);
        mn=min<int>(mn,sub[to].size());
    }
    for(int to:g[c])
        if(sub[to].size()==mn)
        {
            sub[to].push_back(c);
            break;
        }
//    cout<<c<<"\n";
//    for(int to:g[c])
//    {
//        cout<<to<<" : ";
//        for(int x:sub[to])
//            cout<<x<<" ";
//        cout<<"\n";
//    }
    vector<int> v1;
    for(int to:g[c])
        for(int x:sub[to])
            v1.push_back(x);
    vector<int> v2;
    rotate_copy(v1.begin(),v1.begin()+n/2,v1.end(),back_inserter(v2));
    for(int i=0;i<n;i++)
        v[v1[i]]=v2[i];
    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
}