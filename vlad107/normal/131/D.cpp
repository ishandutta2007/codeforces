#include<iostream>
#include<vector>


using namespace std;

vector<vector<int> > g(3010);
vector<int> color(3010,0);
vector<int> pr(3010),pr1(3010);
int nach, kon;

void dfs1(int i)
{
    for(int j=0;j<g[i].size();j++)
    {
        int to=g[i][j]; pr1[to]=i;
        if(color[to]==-1&&pr1[i]!=to) 
        {
            color[to]=color[i]+1; 
            dfs1(to);
        }
    }
}

bool dfs(const int i)
{
    color[i]=1;
    for(int j=0;j<g[i].size();j++)
    {
        int to=g[i][j];
        if(color[to]==0)
        {
            pr[to]=i; if(dfs(to)) return true;
        }
        if(color[to]==1&&pr[i]!=to)
        {
            nach=i; kon=to; return true;
        }
    }
    color[i]=2;
    return false;
}

int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b; cin>>a>>b;

    g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    dfs(0);
            for(int i=0;i<n;i++) color[i]=-1; 
            for(int i=nach;i!=kon;i=pr[i]) color[i]=0; 
            color[kon]=0;
            for(int i=nach;i!=kon;i=pr[i])
                dfs1(i);
            dfs1(kon);
            for(int i=0;i<n;i++)
                cout<<color[i]<<" ";
            return 0;
}