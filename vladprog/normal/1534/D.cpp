#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2010;

int n;
int d[N];
bool p[N];

set<pii> ans;

void ask(int r)
{
    cout<<"? "<<r<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        if(d[i]==1)
            ans.insert(minmax(i,r));
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ask(1);
    int odd=0,even=0;
    for(int i=1;i<=n;i++)
        if(d[i]%2)
            odd++;
        else
            even++;
    for(int i=1;i<=n;i++)
        p[i]=(odd<even)==(d[i]%2);
    for(int i=2;i<=n;i++)
        if(p[i])
            ask(i);
    cout<<"!\n";
    for(auto[x,y]:ans)
        cout<<x<<" "<<y<<"\n";
}