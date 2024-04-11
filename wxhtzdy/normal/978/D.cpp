#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int INF=1e8;
int d1[3]={-1,0,1},d2[3]={-1,0,1};
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int ans=INF;
    for(auto c1:d1){
        for(auto c2:d2){
            int b[n];
            for(int i=0;i<n;i++)b[i]=a[i];
            b[0]+=c1,b[1]+=c2;
            int r=b[0]-b[1],cnt=abs(c1)+abs(c2);
            bool ok=1;
            for(int i=1;i<n-1;i++){
                int nr=b[i]-b[i+1];
                if(nr-r>=-1&&nr-r<=1)cnt+=abs(nr-r);
                else ok=0;
                b[i+1]+=nr-r;
            }
            if(ok)ans=min(ans,cnt);
        }
    }
    if(ans!=INF)printf("%i",ans);
    else printf("-1");
    return 0;
}