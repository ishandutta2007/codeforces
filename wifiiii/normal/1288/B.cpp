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
        int a,b;
        cin>>a>>b;
        int tmp = 9;
        ll ans = 0;
        while(1)
        {
            if(tmp > b) break;
            ans += a;
            tmp = tmp * 10 + 9;
        }
        cout << ans << endl;
    }
}


// b : 1
// ab+a+b=a*10+b
// ab+a=10a
// b+1=10
// b=9

// b : 2
//  = 100a + b
//