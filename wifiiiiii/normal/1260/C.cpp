#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r,b,k;
        cin>>r>>b>>k;
        int g=gcd(r,b);
        r/=g,b/=g;
        if(r>b) swap(r,b);
        if((b-1+r-1)/r < k) cout<<"OBEY"<<endl;
        else cout<<"REBEL"<<endl;
    }
}