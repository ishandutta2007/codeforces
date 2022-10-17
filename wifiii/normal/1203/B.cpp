#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[505];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=4*n;++i) cin>>a[i];
        sort(a+1,a+1+4*n);
        int ok=1;
        for(int i=1;i<=4*n;i+=2) if(a[i]!=a[i+1]) ok=0;
        if(!ok) {puts("NO");continue;}
        int tmp=a[1]*a[4*n];
        for(int i=1;i<=4*n;++i) if(a[i]*a[4*n+1-i]!=tmp) ok=0;
        if(!ok) {puts("NO");continue;}
        else puts("YES");
    }
}