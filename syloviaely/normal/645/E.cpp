#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char ch[1100000];
int where[26],n,m,K,x[2100000],dp[2100000];
const int mo=1e9+7;
int main(){
	scanf("%d%d",&n,&K);
	scanf("%s",ch+1); m=strlen(ch+1);
	memset(where,0x00,sizeof where);
	for (int i=1;i<=m;i++) x[i]=ch[i]-'a',where[x[i]]=i;
	for (int i=1;i<=n;i++){
		x[i+m]=0;
		for (int j=0;j<K;j++) if (where[j]<where[x[i+m]]) x[i+m]=j;
		where[x[i+m]]=i+m;
	}
	for (int i=0;i<K;i++) where[i]=n+m+1;
//	for (int i=1;i<=n+m;i++) cout<<x[i]<<" "; cout<<endl;
	for (int i=n+m;i;i--){
		dp[i]=1;
		for (int j=0;j<K;j++) dp[i]=(dp[i]+dp[where[j]])%mo;
		where[x[i]]=i;
	//	cout<<"fa "<<i<<" "<<dp[i]<<endl;
	}
	int ans=1;
	for (int i=0;i<K;i++) ans=(ans+dp[where[i]])%mo;
	cout<<ans<<endl; return 0;
}