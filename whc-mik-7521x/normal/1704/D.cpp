#include<bits/stdc++.h>
using namespace std;
const int N=1000007;
int t,n,m;
long long sum[100007],res;
vector<long long>c[100007];
int main(){
    scanf("%d",&t);
	while(t--){
        scanf("%d%d",&n,&m);
        res=-1e18;
        for(int i=1;i<=n;i++){
            c[i].resize(m); sum[i]=0;
            for(auto &o:c[i])scanf("%lld",&o);
            for(int o=1;o<(int)c[i].size();o++)c[i][o]+=c[i][o-1];
            for(auto o:c[i])sum[i]+=o;
            res=max(res,sum[i]);
        }
        for(int i=1;i<=n;i++){
            if(sum[i]!=res)printf("%d %lld\n",i,res-sum[i]);
        }
    }
	return 0;
}