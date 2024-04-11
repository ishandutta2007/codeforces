#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 mrand(random_device());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 10005;
int a[maxn],b[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ii cin>>a[i];
        ii cin>>b[i];
        sort(alll(a));
        sort(alll(b));
        ii cout<<a[i]<<" ";cout<<endl;
        ii cout<<b[i]<<" ";cout<<endl;
    }
}