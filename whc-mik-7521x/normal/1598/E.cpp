#include<bits/stdc++.h>
using namespace std;
int n,m,q,mp[1005][1005];
long long solve(int x,int y){
	return max(0,(n-x+1)*(m-y+1));
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<=n+1;i++)mp[i][0]=mp[i][m+1]=1;
	for(int i=0;i<=m+1;i++)mp[0][i]=mp[n+1][i]=1;
	long long ans=n*m+n*(m-1);
	for(int i=2;i<=n;i++){
		ans+=solve(i,i-1);
		ans+=solve(i,i)*2;
		ans+=solve(i,i+1);
	}
	while(q--){
		int x,y,sum=0;
		scanf("%d%d",&x,&y);
		int l=x,r=y,ct1=0,ct2=0;
		while(1){
			l++;
			if(mp[l][r])break;
			ct1++;
			r++;
			if(mp[l][r])break;
			ct1++;
		}
		l=x,r=y;
		while(1){
			r--;
			if(mp[l][r])break;
			ct2++;
			l--;
			if(mp[l][r])break;
			ct2++;
		}
		sum+=1ll*(ct1+1)*(ct2+1);
		l=x,r=y,ct1=0,ct2=0;
		while(1){
			r++;
			if(mp[l][r])break;
			ct1++;
			l++;
			if(mp[l][r])break;
			ct1++;
		}
		l=x,r=y;
		while(1){
			l--;
			if(mp[l][r])break;
			ct2++;
			r--;
			if(mp[l][r])break;
			ct2++;
		}
		sum+=1ll*(ct1+1)*(ct2+1);
		sum-=1;
		if(mp[x][y])ans+=sum;
		else ans-=sum;
		mp[x][y]=1-mp[x][y];
		printf("%lld\n",ans);
	}
	return 0;
}