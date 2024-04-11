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
 
unordered_map<int,int> mp;
int main()
{
    int a=1,b=2;
    int n;
    cin>>n;
    while(a<=n || b<=n)
    {
        mp[a]=mp[b]=1;
        if(b&1) swap(a,b);
        int aa=a+b+1,bb=b+b+1;
        a=aa,b=bb;
    }
    cout<<mp[n]<<endl;
}