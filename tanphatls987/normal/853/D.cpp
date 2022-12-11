#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
typedef long long ll;

#define X first
#define Y second

const int N=3e5+10;
const int inf=1e9;
int n,a[N];

int next10[N];

void prepare(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) a[i]/=100;
    next10[n+1]=n+1;
    for(int i=n;i>=1;i--) if (a[i]==10) next10[i]=i;
    else next10[i]=next10[i+1];
}


void modified(int &sav,int &use,int cost){
    int rec=min(cost,sav);
    sav-=rec;
    use+=cost-rec;
}
int solve(){
    int sum=0;
    for(int i=1;i<=n;i++) sum+=a[i];
    int ans=sum;
    for(int i=1,csum=0;i<=n;i++){
        ans=min(ans,sum-min(sum-csum,csum/10));
        if (a[i]==10){
            int rsav=csum/10;
            int rans=csum,rsum=csum+10;
            modified(rsav,rans,10);
            for(int j=i+1;j<=n&&a[j]==20;j++){
                rans+=20;
                rsav+=2,rsum+=20;
                ans=min(ans,rans+(sum-rsum)-min(rsav,sum-rsum));
            }
        }
        if (a[i]==20){
            int idx=next10[i];
            int rsav=csum/10;
            int rans=csum,rsum=csum+20*(idx-i);
            modified(rsav,rans,20*(idx-i));
            if (idx<=n){
                rsav++;
                rans+=10,rsum+=10;
                ans=min(ans,rans+(sum-rsum)-min(rsav,sum-rsum));
            }
        }
        csum+=a[i];
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve()*100;
}