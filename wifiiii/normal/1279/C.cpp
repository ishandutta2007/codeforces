#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[100005],id[100005];
int bit[100005];
int n,m;
void add(int x,int v){for(;x<=n;x+=x&-x)bit[x]+=v;}
int sum(int x) {int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(bit,0,sizeof(int)*(n+1));
        ii cin>>a[i],id[a[i]]=i;
        ii add(i,1);
        ll ans = 0;
        int cur = 0;
        for(int i=1;i<=m;++i)
        {
            int tmp;
            cin>>tmp;
            if(id[tmp] <= cur) ans++;
            else ans+=2*sum(id[tmp]-1)+1;
            add(id[tmp],-1);
            cur = max(cur, id[tmp]);
        }
        cout << ans << endl;
    }
}