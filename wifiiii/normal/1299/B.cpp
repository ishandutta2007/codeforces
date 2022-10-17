#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//random_device rng;
//mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[200005],b[200005];
int main()
{
    int n;
    cin >> n;
    ii cin>>a[i]>>b[i],a[i+n]=a[i],b[i+n]=b[i];
    int ok=1;
    if(n%2) ok=0;
    else
    {
        for(int i=1;i<=n;++i)
        {
            if(a[i]-a[i+1] == a[i+n/2+1]-a[i+n/2]);
            else ok=0;
            if(b[i]-b[i+1] == b[i+n/2+1]-b[i+n/2]);
            else ok=0;
        }
    }
    if(ok) cout<<"yes";
    else cout<<"no";
}