#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

bool ok(pii a,pii b,pii c)
{
    a.x-=b.x,a.y-=b.y;
    c.x-=b.x,c.y-=b.y;
    int p=a.x*c.x+a.y*c.y;
    return p>0;
}

const int N=5010;

int n;
map<pii,int> ind;
pii pt[N];

void solve()
{
    random_shuffle(pt+1,pt+n+1);
    vector<pii> v;
    #define sz (int(v.size()))
    #define norm(i) (((i)%sz+sz)%sz)
    #define get(i) v[norm(i)]
    for(int k=1;k<=3;k++)
    {
        pii cur=pt[k];
        v.push_back(cur);
    }
    for(int k=4;k<=n;k++)
    {
        pii cur=pt[k];
        int bad=0;
        for(int i=0;i<sz;i++)
            if(!ok(get(i-1),get(i),get(i+1)))
                bad=i;
        {
            int one=ok(get(bad-2),get(bad-1),cur);
            int two=ok(get(bad-1),cur,get(bad));
            int three=ok(cur,get(bad),get(bad+1));
            if(one+two+three>=2)
            {
                v.insert(v.begin()+bad,cur);
                continue;
            }
        }
        {
            int one=ok(get(bad-1),get(bad),cur);
            int two=ok(get(bad),cur,get(bad+1));
            int three=ok(cur,get(bad+1),get(bad+2));
            if(one+two+three>=2)
            {
                v.insert(v.begin()+bad+1,cur);
                continue;
            }
        }
        return;
    }
    int bad=0;
    for(int i=0;i<sz;i++)
        if(!ok(get(i-1),get(i),get(i+1)))
            bad=i;
    for(int i=0;i<sz;i++)
        cout<<ind[get(bad+i)]<<" ";
    exit(0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0)^int(new char));

    cin>>n;
    for(int k=1;k<=n;k++)
        cin>>pt[k].x>>pt[k].y,
        ind[pt[k]]=k;
    while(true)
        solve();
}