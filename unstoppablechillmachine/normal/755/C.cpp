#include <bits/stdc++.h>
#include <iostream>


using namespace std;

#define itn int
#define fro for
#define ld long double
#define ll long long
#define f first
#define sec second

itn n,sum,used[100000],a;
vector <vector<int> >Vec;

void dfs(int v)
{
    used[v]=true;
    for (int i=0;i<Vec[v].size();i++)
    {
        if (!used[Vec[v][i]]) dfs(Vec[v][i]);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&n);
    Vec.resize(n+1);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        Vec[i].push_back(a);
        Vec[a].push_back(i);
    }
    for (int i=1;i<=n;i++)
    {
        if (!used[i])
        {
            dfs(i);
            sum++;
        }
    }
    cout<<sum;
    return 0;
}