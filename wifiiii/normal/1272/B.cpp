
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
        string s;
        cin>>s;
        int l=0,r=0,u=0,d=0;
        for(char c:s) if(c=='L') l++;else if(c=='R') r++;else if(c=='U') u++;else d++;
        if(min(l,r) && min(u,d))
        {
            cout << 2*(min(l,r)+min(u,d)) << endl;
            for(int i=0;i<min(l,r);++i) cout<<'L';
            for(int i=0;i<min(u,d);++i) cout<<'U';
            for(int i=0;i<min(l,r);++i) cout<<'R';
            for(int i=0;i<min(u,d);++i) cout<<'D';
            cout << endl;
        }
        else if(min(l,r))
        {
            cout << 2 << endl;
            cout << "LR" << endl;
        }
        else if(min(u,d))
        {
            cout << 2 << endl;
            cout << "UD" << endl;
        }
        else cout << 0 << endl << endl;
    }
}