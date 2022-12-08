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
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        string s,t;
        cin>>s>>t;
        sort(all(s));
        int ok = 0;
        for(int i=0;i<(int)(t.size()-s.size()+1);++i)
        {
            string s2=t.substr(i,s.size());
            sort(all(s2));
            if(s==s2) {ok=1;break;}
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
}