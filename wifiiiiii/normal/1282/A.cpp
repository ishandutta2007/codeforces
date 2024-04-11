
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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,r;
        cin>>a>>b>>c>>r;
        // c-r c+r
        if(a>b) swap(a,b);
        if(c-r<=a && b<=c+r) cout << 0 << endl;
        else if(a<=c-r && c-r<=b && a<=c+r && c+r<=b) cout << b-a-2*r << endl;
        else if(a<=c-r && c-r <= b) cout << c-r-a << endl;
        else if(a<=c+r && c+r <= b) cout << b-(c+r) << endl;
        else cout << b-a << endl;
    }
}