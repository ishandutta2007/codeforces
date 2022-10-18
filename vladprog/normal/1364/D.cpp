#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

vector<int> g[N];

vector<int> dep[2];

void tree(int v,int p,int d)
{
    dep[d].push_back(v);
    for(int to:g[v])
        if(to!=p)
            tree(to,v,!d);
}

bool used[N];
vector<int> ans;

int cyc(int v,int p)
{
    if(used[v])
        return ans.push_back(v),1;
    used[v]=true;
    for(int to:g[v])
        if(to!=p)
        {
            int cur=cyc(to,v);
            if(cur==1)
                if(ans.front()==v)
                    return 2;
                else
                    return ans.push_back(v),1;
            if(cur==2)
                return 2;
        }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    bool is_tree=m==n-1;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(is_tree)
    {
        tree(1,0,0);
        ans=(dep[0].size()>dep[1].size()?dep[0]:dep[1]);
        while(ans.size()>(k+1)/2)
            ans.pop_back();
        cout<<1<<"\n";
    }
    else
    {
        cyc(1,0);
        map<int,int> ind;
        for(int i=0;i<ans.size();i++)
            ind[ans[i]]=i;
        for(int a=1;a<=n;a++)
            for(int b:g[a])
                if(ind.count(a)&&ind.count(b))
                {
                    int x=ind[a],y=ind[b];
                    if(x>y)
                        swap(x,y);
                    int in=y-x,out=ans.size()-in;
                    if(in==1||out==1)
                        continue;
                    if(in>out)
                        ans.erase(ans.begin()+x+1,ans.begin()+y);
                    else
                        ans.erase(ans.begin()+y+1,ans.end()),
                        ans.erase(ans.begin(),ans.begin()+x);
                    ind.clear();
                    for(int i=0;i<ans.size();i++)
                        ind[ans[i]]=i;
                }
        if(ans.size()>k)
        {
            vector<int> ans2;
            for(int i=0;i+1<ans.size();i+=2)
                ans2.push_back(ans[i]);
            ans=ans2;
            while(ans.size()>(k+1)/2)
                ans.pop_back();
            cout<<1<<"\n";
        }
        else
            cout<<2<<"\n"<<ans.size()<<"\n";
    }
    for(int v:ans)
        cout<<v<<" ";
}