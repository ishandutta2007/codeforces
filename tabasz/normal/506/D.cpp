#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>

int n, m, q;
vector<PII> C, Q;
vector<int> R;
vector<PII> V[100005];
int T[100005];
int vis[100005];
map<PII, int> M;

int find(int a)
{
    if(T[a]==a) return a;
    return T[a]=find(T[a]);
}

void onion(int a, int b)
{
    T[find(b)]=find(a);
}

int main()
{
    //ios_base:sync_with_stdio(0);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++) C.PB(MP(0, i));
    for(int i=1; i<=n; i++) vis[i]=-1;
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        C[c-1]=MP(C[c-1].F+1, c);
        V[c].PB(MP(a, b));
    }
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Q.PB(MP(a, b));
        R.PB(0);
        M.insert(MP(MP(a, b), 0));
    }
    sort(C.begin(), C.end());
    int i=0;
    for(i=0; i<(int)C.size(); i++)
    {
        if((LL)C[i].F*(LL)C[i].F>m) break;
        if(C[i].F==0) continue;
        int ind=C[i].S;
        vector<int> X;
        for(int j=0; j<(int)V[ind].size(); j++)
        {
            if(vis[V[ind][j].F]!=i)
            {
                vis[V[ind][j].F]=i;
                X.PB(V[ind][j].F);
                T[V[ind][j].F]=V[ind][j].F;
            }
            if(vis[V[ind][j].S]!=i)
            {
                vis[V[ind][j].S]=i;
                X.PB(V[ind][j].S);
                T[V[ind][j].S]=V[ind][j].S;
            }
        }
        for(int j=0; j<(int)V[ind].size(); j++)
            onion(V[ind][j].F, V[ind][j].S);
        for(int j=0; j<(int)X.size(); j++)
        {
            for(int k=0; k<(int)X.size(); k++)
            {
                if(find(X[j])==find(X[k])) M[MP(X[j], X[k])]++;
            }
        }
    }
    for(int qwe=i; qwe<(int)C.size(); qwe++)
    {
        int ind=C[qwe].S;
        for(int j=1; j<=n; j++) T[j]=j;
        for(int j=0; j<(int)V[ind].size(); j++)
            onion(V[ind][j].F, V[ind][j].S);
        for(int j=0; j<(int)Q.size(); j++)
            if(find(Q[j].F)==find(Q[j].S)) R[j]++;
    }
    for(int j=0; j<(int)Q.size(); j++)
    {
        R[j]+=M[Q[j]];
        printf("%d\n", R[j]);
    }
    return 0;
}