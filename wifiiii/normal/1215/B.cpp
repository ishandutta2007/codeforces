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

const int maxn = 200005;
int cntn,cntp;
int main()
{
    int n;
    cin>>n;
    ll ansp=0,ansn=0;
    ii
    {
        int tmp;
        cin>>tmp;
        if(tmp>0)
        {
            ansp+=cntp+1;
            ansn+=cntn;
            cntp++;
        }
        else
        {
            ansp+=cntn;
            ansn+=cntp+1;
            swap(cntn,cntp);
            cntn++;
        }
    }
    cout<<ansn<<" "<<ansp<<endl;
}