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

int main()
{
    string s;
    cin>>s;
    int mn = 1e9;
    for(int i=0;i<s.size();++i) {
        if(s[i] > mn) cout << "Ann" << endl;
        else cout << "Mike" << endl;
        mn = min((int)s[i], mn);
    }
}