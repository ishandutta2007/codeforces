#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const int M=100000;
int a[N];
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    ll ans=1e18;
    for(int i=1;i<=M;i++){
        int j=i;
        {
            bool ok=true;
            ll cnt=0;
            for(int k=1;k<=n;k++){
                int x=a[k]/j,y=a[k]%j;
                if(y>0)x++;
                if(y>0&&j>x+y)ok=false;
                cnt+=x;
            }
            if(ok)ans=min(ans,cnt);
        }
        j=max(1,a[1]/i);
        {
            bool ok=true;
            ll cnt=0;
            for(int k=1;k<=n;k++){
                int x=a[k]/j,y=a[k]%j;
                if(y>0)x++;
                if(y>0&&j>x+y)ok=false;
                cnt+=x;
            }
            if(ok)ans=min(ans,cnt);
        }
        j=a[1]/i+1;
        {
            bool ok=true;
            ll cnt=0;
            for(int k=1;k<=n;k++){
                int x=a[k]/j,y=a[k]%j;
                if(y>0)x++;
                if(y>0&&j>x+y)ok=false;
                cnt+=x;
            }
            if(ok)ans=min(ans,cnt);
        }
    }
    printf("%lld",ans);
    return 0;
}