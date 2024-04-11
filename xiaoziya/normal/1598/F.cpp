#include<stdio.h>
#include<iostream>
#include<string.h>
#define lowbit(x) x&-x
using namespace std;
const int maxn=21,maxv=400005;
int n,m,ans,tot;
int f[1<<maxn],mn[maxn],cnt[maxn],sum[1<<maxn],w[maxn][maxv<<1],ok[maxn][maxv<<1];
string s;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int now=0;
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='(')
				now++;
			if(s[j]==')')
				ok[i][400000+now]=1,now--;
			if(ok[i][400000+now]==0)
				w[i][400000+now]++;
			mn[i]=min(mn[i],now);
		}
		sum[1<<(i-1)]=now;
	}
	memset(f,-1,sizeof(f)),f[0]=0;
	for(int i=1;i<(1<<n);i++){
		sum[i]=sum[i^lowbit(i)]+sum[lowbit(i)];
		for(int j=1;j<=n;j++)
			if((i>>(j-1))&1){
				int pre=(i^(1<<(j-1)));
				if(f[pre]==-1)
					continue;
				if(sum[pre]+mn[j]>=0)
					f[i]=max(f[i],f[pre]+w[j][400000-sum[pre]]);
				else ans=max(ans,f[pre]+w[j][400000-sum[pre]]);
			}
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}