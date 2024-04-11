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
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==b) {cout<<0<<endl;continue;}
        int d=abs(a-b);
        for(ll i=1;;++i)
        {
            ll tmp=i*(i+1)/2;
            if(tmp>=d&&(tmp+d)%2==0)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}