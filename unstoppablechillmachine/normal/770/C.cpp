#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define sec second
#define itn int
#define fro for

int used[100001],n,k,a,from,sum,p;
bool t[100001];
vector<vector<int> > Vec,Vec2;
vector<int> Vec1,arr;
queue<int> q;

void dfs(int v)
{
    used[v]=1;
    for (int i=0;i<Vec[v].size();i++)
    {
        if (!t[Vec[v][i]]) continue;
        if (!used[Vec[v][i]])
        {
            dfs(Vec[v][i]);
        }
        else if (used[Vec[v][i]]==1)
        {
            cout<<-1;
            exit(0);
        }
    }
    used[v]=2;
    Vec1.push_back(v);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);

    scanf("%d%d",&n,&k);
    Vec.resize(n+1);
    Vec2.resize(n+1);
    arr.resize(k);
    for (int i=0;i<k;i++)
    {
        scanf("%d",&arr[i]);
    }

    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for (int j=0;j<a;j++)
        {
            scanf("%d",&from);
            Vec[from].push_back(i);
            Vec2[i].push_back(from);
        }
    }

    for (int i=0;i<arr.size();i++)
    {
        q.push(arr[i]);
        if (!t[arr[i]]) sum++;
        t[arr[i]]=true;
        used[arr[i]]=true;

        while (!q.empty())
        {
            p=q.front();
            for (int j=0;j<Vec2[p].size();j++)
            {
                if (!used[Vec2[p][j]])
                {
                    sum++;
                    q.push(Vec2[p][j]);
                    used[Vec2[p][j]]=true;
                    t[Vec2[p][j]]=true;
                }
            }
            q.pop();
        }
    }

    for (int i=1;i<=n;i++) used[i]=false;

    for (int i=1;i<=n;i++)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }

    reverse(Vec1.begin(),Vec1.end());

    printf("%d%c",sum,'\n');

    for (int i=0;i<Vec1.size();i++)
    {
        if (t[Vec1[i]]) printf("%d%c",Vec1[i],' ');
    }

    return 0;
}