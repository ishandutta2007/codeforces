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

int a[100005];
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i];
    ll sum=0,tmp=0;
    sort(a+1,a+1+n);
    ii sum+=a[i];
    for(int i=1;i<=n/2;++i) tmp+=a[i];
    sum-=tmp;
    cout<<tmp*tmp+sum*sum<<endl;
}