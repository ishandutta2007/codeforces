#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)

int a[100005];
int main()
{
    int n;cin>>n;
    int cnt=0;
    forii cin>>a[i];
    forii if(!a[i]) cnt++;
    if(cnt>=2) {cout<<"cslnb"<<endl;return 0;}
    sort(a+1,a+1+n);
    int p=0;
    for(int i=2;i<=n;++i) if(a[i]==a[i-1]) p++;
    if(p>1) {cout<<"cslnb"<<endl;return 0;}
    if(p==1)
    {
        for(int i=2;i<=n;++i) if(a[i]==a[i-1]) {a[i]--;break;}
        sort(a+1,a+1+n);
        int p=0;
        for(int i=2;i<=n;++i) if(a[i]==a[i-1]) p++;
        if(p) {cout<<"cslnb"<<endl;return 0;}
        ll sum=0;
        forii sum+=a[i]-i+1;
        if(sum%2) cout<<"cslnb"<<endl;
        else cout<<"sjfnb"<<endl;
        return 0;
    }
    ll sum=0;
    forii sum+=a[i]-i+1;
    if(sum%2==0) cout<<"cslnb"<<endl;
    else cout<<"sjfnb"<<endl;
}