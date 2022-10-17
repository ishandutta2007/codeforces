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
//#define endl '\n'

int n,k;
void query(int x)
{
    cout<<"?";
    for(int i=1;i<=k+1;++i) if(i!=x) cout<<" "<<i;
    cout<<endl;
}
int main()
{
    cin>>n>>k;
    query(k+1);
    int pos,val;
    cin>>pos>>val;
    query(pos);
    int pos2,val2;
    cin>>pos2>>val2;
    int big=max(val,val2),small=min(val,val2);
    int ans=0;
    for(int i=1;i<=k+1;++i)
    {
        if(i==pos||i==pos2) continue;
        query(i);
        int p,v;
        cin>>p>>v;
        if(v==big) ans++;
    }
    cout<<"! "<<ans+1<<endl;
}