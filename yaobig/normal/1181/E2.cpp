#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct node
{
    int x1,x2,id;
    node(){}
    node(int a,int b,int c):x1(a),x2(b),id(c){}
    bool operator < (const node &a) const
    {
        if(x1==a.x1) return id<a.id;
        return x1<a.x1;
    }
}rec[maxn+5][4];

bool check(set<node> a[4])
{
    int n=a[0].size();
    if(n==1) return 1;
    int mx[4]={-inf,-inf,-inf,-inf};
    set<node>::iterator it[4];
    rep(j,0,3) it[j]=a[j].begin();
    rep(i,1,n) rep(j,0,3)
    {
        mx[j]=max(mx[j],it[j]->x2);
        it[j]++;
        if(mx[j]<=it[j]->x1)
        {
            set<node> b[4];
            for(auto IT=a[j].begin();IT!=it[j];)
            {
                int id=IT->id;
                IT++;
                rep(k,0,3)
                {
                    b[k].insert(rec[id][k]);
                    a[k].erase(rec[id][k]);
                }
            }
            return check(a) && check(b);
        }
    }
    return 0;
}

int main()
{
    int n; scanf("%d",&n);
    set<node> s[4];
    rep(i,1,n)
    {
        int x1,x2,y1,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        rec[i][0]=node(x1,x2,i);
        rec[i][1]=node(-x2,-x1,i);
        rec[i][2]=node(y1,y2,i);
        rec[i][3]=node(-y2,-y1,i);
    }
    rep(i,1,n) rep(j,0,3) s[j].insert(rec[i][j]);
    if(check(s)) puts("YES");
    else puts("NO");
    return 0;
}