#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int dp1[1<<20],dp2[1<<20];
int n,m,k,p[N],a[N],popct[1<<20],ct1,ct2,A,B;
char s1[N],s2[N];
int calc(char *s){
	int res=0;
    for(int i=1;i<=k;i++)a[p[i]]=s[i]=='1';
    for(int i=1;i<=k;i++)(res<<=1)|=a[i];
    return res;
}
int main(){
    scanf("%d%d%d%s%s",&n,&m,&k,s1+1,s2+1);
    for(int i=1;i<1<<k;i++)popct[i]=popct[i>>1]+(i&1);
	for(int i=1;i<=k;i++)p[i]=i,ct1+=s1[i]=='1',ct2+=s2[i]=='1';
	memset(dp1,63,sizeof(dp1));
	memset(dp2,-63,sizeof(dp2));
    int A=calc(s1),B=calc(s2);
    dp1[A]=min(dp1[A],0);
    dp2[B]=max(dp2[B],0);
	for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        swap(p[x],p[y]);
		A=calc(s1),B=calc(s2);
		dp1[A]=min(dp1[A],i);
		dp2[B]=max(dp2[B],i);
	}
	for(int i=(1<<k)-1;i>=0;i--){
		for(int o=0;o<k;o++){
			if((i)&(1<<o)){
				dp1[i^(1<<o)]=min(dp1[i^(1<<o)],dp1[i]);
				dp2[i^(1<<o)]=max(dp2[i^(1<<o)],dp2[i]);
			}
		}
	}
    pair<int,pair<int,int>>ans={0,{0,0}};
    for(int i=0;i<1<<k;i++){
        if(dp2[i]-dp1[i]>=m)ans=max(ans,{popct[i]*2+k-ct1-ct2,{dp1[i]+1,dp2[i]}});
    }
    printf("%d\n%d %d",ans.first,ans.second.first,ans.second.second);
	return 0;
}