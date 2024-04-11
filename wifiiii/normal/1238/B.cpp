
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

int a[100005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n,r;
        cin>>n>>r;
        ii cin>>a[i];
        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);
        int cnt = 0;
        for(int i=1;i<=n;++i)
        {
            if(a[i]-cnt*r <= 0) break;
            if(i<n && a[i] == a[i+1]) continue;
            ++cnt;
        }
        cout<<cnt<<endl;
    }
}