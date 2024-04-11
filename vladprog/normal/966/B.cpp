#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair

const int N=3e5+100;

int n;
pii c[N];

void solve(int x1,int x2,bool sw)
{
    int k1=0;
    while(k1<=n&&x1>k1*c[k1].x)
        k1++;
    if(k1>n)
        return;
    int k2=0;
    while(k1+k2<=n&&x2>k2*c[k1+k2].x)
        k2++;
    if(k1+k2>n)
        return;
    vector<int> ans1;
    for(int i=1;i<=k1;i++)
        ans1.push_back(c[i].y);
    vector<int> ans2;
    for(int i=k1+1;i<=k1+k2;i++)
        ans2.push_back(c[i].y);
    if(sw)
        swap(ans1,ans2);
    cout<<"Yes\n";
    cout<<ans1.size()<<" "<<ans2.size()<<"\n";
    for(int x:ans1)
        cout<<x<<" ";
    cout<<"\n";
    for(int x:ans2)
        cout<<x<<" ";
    cout<<"\n";
    exit(0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int x1,x2;
    cin>>n>>x1>>x2;
    for(int i=1;i<=n;i++)
        cin>>c[i].x,c[i].y=i;
    sort(c+1,c+n+1,greater<>());
    solve(x1,x2,false);
    solve(x2,x1,true);
    cout<<"No\n";
}