#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 urng(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
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
        int n;
        cin>>n;
        unordered_map<int, int> mp;
        int f = 1;
        ii
        {
            int tmp;
            cin>>tmp;
            if(mp[tmp-1] || mp[tmp+1]) f = 2;
            mp[tmp]++;
        }
        cout<<f<<endl;
    }
}