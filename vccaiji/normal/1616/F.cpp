#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300],b[300],c[300];
int t[300][300];
int tot;
int o[10000][300];
int x[10000];
int y[300];
int main(){
	int _;
	cin>>_;
	while(_--){
		tot=0;
		cin>>n>>m;
		for(int i=1;i<=m;i++)cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)t[i][j]=0;
		for(int i=1;i<=m;i++)t[a[i]][b[i]]=t[b[i]][a[i]]=i;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++){
			if(t[i][j]&&t[j][k]&&t[i][k]){
				++tot;
				for(int j=1;j<=m;j++)o[tot][j]=0;
				o[tot][t[i][j]]=1;
				o[tot][t[j][k]]=1;
				o[tot][t[i][k]]=1;
				x[tot]=0;
			}
		}
		for(int i=1;i<=m;i++)if(c[i]>=0){
			++tot;
			for(int j=1;j<=m;j++)o[tot][j]=0;
			o[tot][i]=1;
			x[tot]=c[i]-1;
		}
		int j=0;
		for(int i=1;i<=m;i++){
			if(!o[j+1][i]){
				for(int k=j+2;k<=tot;k++){
				if(o[k][i]){
					for(int p=i;p<=m;p++)swap(o[j+1][p],o[k][p]);
					swap(x[j+1],x[k]);
					break;
				} 
			}
			}
			if(!o[j+1][i])continue;
			for(int k=j+2;k<=tot;k++){
				int u=((3-o[j+1][i])*o[k][i])%3;
				for(int p=i;p<=m;p++)o[k][p]=(o[k][p]+u*o[j+1][p])%3;
				x[k]=(x[k]+u*x[j+1])%3; 
			}
			j++;
		}
		bool r=0;
		for(int k=j+1;k<=tot;k++)if(x[k])r=1;
		if(r){
			cout<<-1<<endl;
			continue;
		}
		for(int k=j;k>=1;k--){
			int s=-1;
			int ans=x[k];
			for(int p=1;p<=m;p++){
				if(s>-1)ans=(ans+(3-y[p])*o[k][p])%3;
				if(o[k][p]&&(s==-1))s=p;
			}
			y[s]=(ans*o[k][s])%3;
		}
		for(int j=1;j<=m;j++)cout<<y[j]+1<<" ";
		cout<<endl;
	}
	return 0;
}