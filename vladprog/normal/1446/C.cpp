#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int LOG=30;

struct node
{
    node*son[2];
    node()
    {
        son[0]=son[1]=0;
    }
};
typedef node*pnode;

pnode root=new node();

void add(int x)
{
    pnode v=root;
    for(int i=LOG;i>=0;i--)
    {
        int cur=(x>>i)&1;
        if(!v->son[cur])
            v->son[cur]=new node();
        v=v->son[cur];
    }
}

int solve(pnode v)
{
    if(!v)
        return 0;
    int a=solve(v->son[0]);
    int b=solve(v->son[1]);
    if(a)
        if(b)
            return max(a,b)+1;
        else
            return a;
    else
        if(b)
            return b;
        else
            return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        add(x);
    }
    cout<<n-solve(root);
}