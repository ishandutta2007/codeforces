#include<bits/stdc++.h>
using namespace std;
int _,n,m,x[20];
char s[20][11000];
int jj[11000];
int k[11000];
pair<int,int> kk[11000];
int main(){
	cin>>_;
	while(_--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		long long ans=0;
		for(int i=0;i<(1<<n);i++){
			long long anss=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1)anss-=x[j+1];
				else anss+=x[j+1];
			}
			for(int j=1;j<=m;j++){
				k[j]=0;
				for(int o=0;o<n;o++){
					if(s[o+1][j]=='1'){
						if((i>>o)&1)k[j]++;
						else k[j]--;
					}
				}
				kk[j]=make_pair(k[j],j);
			}
			sort(kk+1,kk+m+1);
			for(int j=1;j<=m;j++)anss+=j*kk[j].first;
			if(anss>=ans){
				ans=anss;
				for(int j=1;j<=m;j++)jj[kk[j].second]=j;
			}
		}
		for(int i=1;i<=m;i++)cout<<jj[i]<<' ';
		cout<<endl;
	}
	return 0;
}