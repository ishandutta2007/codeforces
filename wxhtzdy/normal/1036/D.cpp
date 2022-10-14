#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=300050;
int n,a[N],m,b[N];
ll sum1=0,sum2=0;
int main(){
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]),sum1+=a[i];
    scanf("%i",&m);
    for(int i=0;i<m;i++)scanf("%i",&b[i]),sum2+=b[i];
    if(sum1!=sum2)return 0*printf("-1");
    vector<ll> c,d;
    c.pb(a[0]);d.pb(b[0]);
    int x=1,y=1;
    while(x<n&&y<m){
        while(x<n&&y<m&&c.back()!=d.back()){
            if(c.back()<d.back()&&x<n){
                c[(int)c.size()-1]+=a[x];
                x++;
            }else{
                if(y<m){
                    d[(int)d.size()-1]+=b[y];
                    y++;
                }
            }
        }
        if(x<n)c.pb(a[x]),x++;
        if(y<m)d.pb(b[y]),y++;
    }
    printf("%i",min((int)c.size(),(int)d.size()));
    return 0;
}