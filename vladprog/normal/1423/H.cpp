#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

vector<pair<int, int> > t[2000500];
vector<pair<pair<int, int>, int> > days[500500];

void add(int v, int l, int r, int l0, int r0, pair<int, int> ed)
{
    if ((l==l0) and (r==r0))
    {
        t[v].pb(ed);
        return;
    }
    int m=(l+r)/2;
    if (r0<=m) add(2*v, l, m, l0, r0, ed);
    else
    if (l0>m) add(2*v+1, m+1, r, l0, r0, ed);
    else
    {
        add(2*v, l, m, l0, m, ed);
        add(2*v+1, m+1, r, m+1, r0, ed);
    }
}

int p[500500];
int sz[500500];
int qur[500500];
int zet[500500];
vector<int> ans;

int curch=0;
vector<pair<int, int> > pch[500500];
vector<pair<int, int> > szch[500500];

int get(int v)
{
    if (p[v]==v)
        return v;
    pch[curch].pb({v, p[v]});
    p[v]=get(p[v]);
    return p[v];
}

void un(int u, int v)
{
    u = get(u);
    v = get(v);
    if (u==v)
        return;
    if (sz[u] > sz[v])
        swap(u, v);
    pch[curch].pb({u, p[u]});
    p[u]=v;
    szch[curch].pb({v, sz[v]});
    sz[v]+=sz[u];
}

void undo()
{
    reverse(pch[curch].begin(), pch[curch].end());
    reverse(szch[curch].begin(), szch[curch].end());
    for (auto pa:pch[curch])
        p[pa.fi]=pa.se;
    for (auto pa:szch[curch])
        sz[pa.fi]=pa.se;
    szch[curch].clear();
    pch[curch].clear();
}

void dfs(int v, int l, int r)
{
    for (auto pa:t[v])
        un(pa.fi, pa.se);

    if (l==r)
    {
//        cout<<"time: "<<l<<"\n";
//        for (int i=1; i<=5; i++)
//            cout<<p[i]<<" ";
//        cout<<"\n";
//        for (int i=1; i<=5; i++)
//            cout<<sz[i]<<" ";
//        cout<<"\n";

        if (qur[l]!=-1)
            ans[qur[l]]=sz[get(zet[l])];
    }
    else
    {
        curch++;
        int m=(l+r)/2;
        dfs(2*v, l, m);
        dfs(2*v+1, m+1, r);
        curch--;
    }

    undo();
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q, k;
    cin>>n>>q>>k;
    int cur=0;
    int qnum=0;
    memset(qur, 255, sizeof(qur));

    for (int i=1; i<=q; i++)
    {
        int typ;
        cin>>typ;
        if (typ==1)
        {
            int x, y;
            cin>>x>>y;
            days[cur].pb( {{x, y}, i} );
        }
        if (typ==2)
        {
            int z;
            cin>>z;
            qur[i]=qnum++;
            zet[i]=z;
        }
        if (typ==3)
        {
            cur++;
            if (cur-k >= 0)
                for (auto pa: days[cur-k])
                {
                    add(1, 1, q, pa.se, i, pa.fi);
                }
        }
    }
    for (int c=max(0, cur-k+1); c<=cur; c++)
        for (auto pa: days[c])
            {
                add(1, 1, q, pa.se, q, pa.fi);
            }
//    for (int i=1; i<=100; i++)
//        for (auto pa:t[i])
//            cout<<i<<" "<<pa.fi<<" "<<pa.se<<endl;

    for (int i=1; i<=n; i++)
        p[i]=i, sz[i]=1;
    ans.resize(qnum);
    dfs(1, 1, q);
    for (int i:ans)
        cout<<i<<"\n";
//    cout<<"\n";
    return 0;
}