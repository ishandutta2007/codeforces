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
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[5];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a[1]>>a[2]>>a[3];
        sort(a+1,a+4);
        if(a[1]+a[2]<a[3]-1) puts("No");
        else puts("Yes");
    }
}