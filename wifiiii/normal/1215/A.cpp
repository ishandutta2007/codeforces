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
    int a1,a2;
    int k1,k2;
    cin>>a1>>a2>>k1>>k2;
    int n;
    cin>>n;
    int ans1=0;
    int tmp=a1*(k1-1)+a2*(k2-1);
    if(n<=tmp) ans1=0;
    else ans1=n-tmp;
    if(k1>k2) swap(k1,k2),swap(a1,a2);
    int ans2=0;
    if(n<=a1*k1) ans2=n/k1;
    else ans2=(n-a1*k1)/k2+a1;
    cout<<ans1<<" "<<ans2<<endl;
}