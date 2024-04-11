
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
    int n;
    cin>>n;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;++i)
    {
        int tmp;
        cin>>tmp;
        if(tmp&1) ++cnt1;
        else ++cnt2;
    }
    cout << min(cnt1,cnt2) << endl;
}