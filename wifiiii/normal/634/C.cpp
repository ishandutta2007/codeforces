#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll bit[200005][2];
int n;
void add(int x,int v,int p) {for(;x<=n;x+=x&-x) bit[x][p]+=v;}
ll sum(int x,int p){int ret=0;for(;x;x-=x&-x)ret+=bit[x][p];return ret;}
int c[200005];
int main()
{
    int k,a,b,q;
    cin>>n>>k>>a>>b>>q;
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int m,d;
            cin>>d>>m;
            add(d,min(c[d]+m,a)-min(c[d],a),0);
            add(d,min(c[d]+m,b)-min(c[d],b),1);
            c[d] += m;
        }
        if(op == 2)
        {
            int x;
            cin>>x;
            // x,x+k-1;
            cout<<sum(x-1,1)+sum(n,0)-sum(x+k-1,0)<<endl;
        }
    }
}