
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//random_device rng;
//mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        int tmp=sqrt(d);
        tmp=max(0,tmp-50);
        int mx = 2e9;
        for(int i=tmp;i<=tmp+100;++i)
        {
            mx = min(mx, i+(d+i)/(i+1));
        }
        if(mx <= n) cout << "YES"<<endl;
        else cout<<"NO"<<endl;
    }
}