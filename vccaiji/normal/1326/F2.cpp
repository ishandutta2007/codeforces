#include<bits/stdc++.h>
using namespace std;
int n;
bool kk[20][20]={};
long long a[1<<18][20]={};
long long t[1<<18]={};
int bt[1<<18];
long long tt[20][1<<18]={};
long long anss;
long long ans[1<<17];
int cc[20];
int aa[20]={1};
int bb[20];
int dd[20];
long long now[20][1<<18];
int s;
int ss;
void dfs2(int i){
	if(i==ss){
		int o=(1<<(n-1))-1;
		int u=0;
		for(int j=1;j<ss;j++){
			u+=dd[j];
			o^=(1<<(u-1)); 
		}
		ans[o]=anss;
		return;
	}
	int j=1;
	if((i>0)&&(aa[i+1]==aa[i])) j+=bb[i];
	for(;j<=ss-cc[i+1]+1;j++){
		if(dd[j]==0){
			bb[i+1]=j;
			dd[j]=aa[i+1];
			dfs2(i+1);
			dd[j]=0;
		}
	}
}
void dfs(int i){
	if(s==0){
		anss=0;
		for(int j=0;j<(1<<n);j++){
			if((n-bt[j])&1) anss-=now[i][j];
			else anss+=now[i][j];
		}
		ss=i;
		cc[i]=1;
		for(int j=i-1;j>=1;j--){
			if(aa[j]==aa[j+1]) cc[j]=cc[j+1]+1;
			else cc[j]=1;
		}
		for(int j=1;j<=i;j++) dd[j]=0;
		dfs2(0);
		return;
	}
	for(int j=aa[i];j<=s;j++){
		s-=j;
		aa[i+1]=j;
		for(int u=0;u<(1<<n);u++) now[i+1][u]=now[i][u]*tt[j][u];
		dfs(i+1);
		s+=j;
	}
}
int main(){
	cin>>n;
	bt[0]=0;
	for(int i=1;i<(1<<n);i++) bt[i]=bt[i^(i&(-i))]+1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char l;
			cin>>l;
			if(l=='1') kk[i][j]=true;
		}
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				if(i==(1<<j)) a[i][j]=1;
				else{
					for(int k=0;k<n;k++){
						if((i>>k)&1){
							if((j!=k)&&kk[j][k])
								a[i][j]+=a[i^(1<<j)][k];
						}
					}
				}
			}
			t[i]+=a[i][j];
		}
		tt[bt[i]][i]=t[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<(1<<n);k++){
				if((k>>j)&1) tt[i][k]+=tt[i][k^(1<<j)];
			}
		}
	}
	s=n;
	for(int i=0;i<(1<<n);i++) now[0][i]=1;
	dfs(0);
	for(int i=0;i<n-1;i++){
		for(int j=0;j<(1<<(n-1));j++){
			if((j>>i)&1) ans[j^(1<<i)]-=ans[j];
		}
	}
	for(int j=0;j<(1<<(n-1));j++) printf("%lld ",ans[j]);
	return 0;
}