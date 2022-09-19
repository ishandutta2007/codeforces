#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string z;
        cin>>z;
        int a[n];
        for(int i=0;i<n;++i) {a[i]=z[i]-'0';}
        bool b[n]={0};
        string ans[n];
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) ans[i].push_back(' ');
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<=i;++j)
            {
                if(i==j) ans[i][j]='X';
                else if(a[i]==1 || a[j]==1) {ans[i][j]='=';ans[j][i]='=';}
                else if(!b[j]) {ans[i][j]='-';ans[j][i]='+';b[j]=true;}
                else {ans[i][j]='+';ans[j][i]='-';b[i]=true;}
            }
        }
        bool h=true;
        for(int i=0;i<n;++i) if(a[i]==2) h=(h && b[i]);
        if(h) {cout<<"YES"<<endl;for(int i=0;i<n;++i) cout<<ans[i]<<endl;}
        else {cout<<"NO"<<endl;}
    }
    return 0;
}