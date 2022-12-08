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
#define asd cout<<"ok"<<endl;
#define endl '\n'

int r[505],c[505];
int r2[505],c2[505];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
    int a,b;
    cin>>a>>b;
    if(a==1 && b==1) return cout<<0<<endl,0;
    if(b==1) {
        for(int i=1;i<=a;++i) cout<<i+1<<endl;
        return 0;
    }
    for(int i=1;i<=a;++i) r[i]=i;
    for(int i=1;i<=b;++i) c[i]=a+i;
    for(int i=1;i<=a;++i) {
        for(int j=1;j<=b;++j)
            cout<<r[i]*c[j]<<" ";cout<<endl;
    }
//    for(int i=1;i<=a;++i) for(int j=1;j<=b;++j) r2[i]=gcd(r2[i],r[i]*c[j]),c2[j]=gcd(c2[j],r[i]*c[j]);
//    for(int i=1;i<=a;++i) cout<<r2[i]<<" ";cout<<endl;
//    for(int i=1;i<=b;++i) cout<<c2[i]<<" ";cout<<endl;
    
}