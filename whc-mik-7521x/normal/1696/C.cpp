#include<bits/stdc++.h>
using namespace std;
const long long N=5e4+10;
long long t,n,m,k,a[N],b[N];
vector<pair<long long,long long>>x,y;
int main(){
    scanf("%d",&t);
	while(t--){
        scanf("%d%d",&n,&m);
        x.clear();
        y.clear();
        for(long long i=1;i<=n;i++)scanf("%d",&a[i]);
        scanf("%d",&k);
        for(long long i=1;i<=k;i++)scanf("%d",&b[i]);
        for(long long i=1;i<=n;i++){
            long long cnt=1;
            while(!(a[i]%m)){
                a[i]/=m;
                cnt*=m;
            }
            if(x.size()&&x.back().first==a[i])x.back().second+=cnt;
            else x.push_back({a[i],cnt});
        }
        for(long long i=1;i<=k;i++){
            long long cnt=1;
            while(!(b[i]%m)){
                b[i]/=m;
                cnt*=m;
            }
            if(y.size()&&y.back().first==b[i]) y.back().second+=cnt;
            else y.push_back({b[i],cnt});
        }
        puts(x==y?"Yes":"No");
    }
	return 0;
}