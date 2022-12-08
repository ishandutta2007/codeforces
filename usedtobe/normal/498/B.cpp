#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define dep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
#define N 5005
#define eps 1e-9
long double dp[2][N],p[N],ans;
int n,T,t[N];
int main() {
	//freopen("2.in","r",stdin);
    scanf("%d%d",&n,&T);
    rep(i,1,n)cin>>p[i]>>t[i],p[i]/=100;
    dp[0][0]=1;int cur=0;
    rep(i,1,n) {
    	if(i>T)break;
    	cur^=1;memset(dp[cur],0,sizeof dp[cur]);
        int L=max(0,i-(t[i]-1)),R=i-1;long double sum=p[i],tmp=0,tot;
        dep(j,R,L)tmp+=dp[cur^1][j]*sum,sum*=(1-p[i]);
        sum=p[i];
        rep(j,1,t[i]-2)sum*=(1-p[i]);if(t[i]==1)sum/=(1-p[i]+eps);
        tot=pow(1.0-p[i],t[i]-1);
        if (i-t[i]>=0) dp[cur][i]=tmp+dp[cur^1][i-t[i]]*tot;
        else dp[cur][i]=tmp;ans+=dp[cur][i];
        rep(j,i+1,T) {
        	if (t[i]!=1){
        		if (j-t[i]>=0)tmp-=dp[cur^1][j-t[i]]*sum;
            //	cout<<tot*p[i]/(1-p[i]+eps)<<" "<<sum<<endl;
            }
            tmp*=(1.0-p[i]);
			if (t[i]!=1)tmp+=dp[cur^1][j-1]*p[i];
            if (j-t[i]>=0) dp[cur][j]=tmp+dp[cur^1][j-t[i]]*tot;
            else dp[cur][j]=tmp;ans+=dp[cur][j];
        }
    }
    printf("%.11lf\n",(double)ans);
    return 0;
}