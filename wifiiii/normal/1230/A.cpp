#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'


int a[5];
int sum;
int ok;
void dfs(int p,int tmp)
{
    if(p==5)
    {
        if(tmp*2 == sum) ok = 1;
        return;
    }
    dfs(p+1,tmp+a[p]);
    dfs(p+1,tmp);
}
int main()
{
    
    for(int i=1;i<=4;++i) cin>>a[i];
    for(int i=1;i<=4;++i) sum+=a[i];
    if(sum%2) return cout<<"NO"<<endl,0;
    dfs(1,0);
    if(ok) cout<<"YES"<<endl;
    else cout << "NO"<<endl;
}