#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,S=5e6+100;

int a[N];
pii p1[S],p2[S],p3[S];

void check(int x,int y,int z,int w)
{
    if(x&&y&&z&&w&&
       x!=y&&x!=z&&x!=w&&
       y!=z&&y!=w&&z!=w)
        cout<<"YES\n"<<x<<" "<<y<<" "<<z<<" "<<w,exit(0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    n=min<int>(n,5500);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int s=a[i]+a[j];
            check(p1[s].x,p1[s].y,i,j);
            check(p2[s].x,p2[s].y,i,j);
            check(p3[s].x,p3[s].y,i,j);
            if(!p1[s].x)
                p1[s]={i,j};
            else if(!p2[s].x)
                p2[s]={i,j};
            else if(!p3[s].x)
                p3[s]={i,j};
        }
    cout<<"NO";
}