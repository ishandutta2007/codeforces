#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    long long x,y,z;
};
signed main(){
    long long T;
    scanf("%lld",&T);
	while(T--){
        long long n,m;
        long long tim[N];
        vector<long long>ans;
        vector<node>a[N];
        scanf("%lld%lld",&n,&m);
        for(long long i=0;i<n;i++)scanf("%lld",&tim[i]);
        for(long long i=0;i<m;i++){
            long long e,t,p;
            scanf("%lld%lld%lld",&e,&t,&p);
            e--;
            a[e].push_back(node{t,p,i});
        }
        long long sum=0,pd=0;
        for(long long i=0;i<n;i++){
            long long N = a[i].size();
            vector dp(N+1,vector<long long>(101,2e9+1));
            dp[0][0]=0;
            for(long long j=0;j<N;j++){
                dp[j+1]=dp[j];
                auto [t,p,ty] = a[i][j];
                for(long long k=0;k<=100;k++){
                    long long nk=min(100ll,k+p);
                    dp[j+1][nk]=min(dp[j+1][nk],dp[j][k]+t);
                }
            }
            sum+=dp[N][100];
            if(sum>tim[i]){
                pd=1;
                break;
            }
            long long nd=100;
            for(long long j=N-1;j>=0;j--){
                auto [t,p,id] = a[i][j];
                if(dp[j+1][nd]==dp[j][nd])continue;
                ans.push_back(id);
                for(long long k=0;k<=100;k++){
                    long long nk=min(100ll,k+p);
                    if(nk==nd&&dp[j][k]+t==dp[j+1][nk]){
                        nd=k;
                        break;
                    }
                }
            }
        }
        if(pd==1)puts("-1");
        else{
            printf("%lld\n",(long long)ans.size());
            for(auto x : ans)printf("%lld ",x+1);
            puts("");
        }
    } 
}