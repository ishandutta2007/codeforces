#include<bits/stdc++.h>//luogu
using namespace std;
const int p=998244353;
int r,c;
char s[2100][2100];
vector<int> e[4100];
int vis[4100];
int tot;
int cc[4100];
void dfs(int i){
	if(vis[i])return;
	vis[i]=1;
	cc[i]=tot;
	for(int j : e[i])dfs(j);
}
vector<int> ss[4100];
int k[4100];
int main(){
	cin>>r>>c;
	for(int i=1;i<=r;i++)scanf("%s",s[i]+1);
	if(!(r&1)){
		if(!(c&1)){
			int num=1;
			for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)if(s[i][j]=='?')num=(num<<1)%p;
			cout<<num;
		}
		else{
			int num=1;
			for(int i=1;i<=r;i++){
				int o=0,sss=0;
				for(int j=1;j<=c;j++){
					if(s[i][j]=='?')o++,num=(num<<1)%p;
					if(s[i][j]=='1')sss++; 
				}
				if((!o)&&(sss&1))num=0;
				if(o)num=(1ll*num*((p+1)/2))%p;
			}
			int num2=1;
			for(int i=1;i<=r;i++){
				int o=0,sss=0;
				for(int j=1;j<=c;j++){
					if(s[i][j]=='?')o++,num2=(num2<<1)%p;
					if(s[i][j]=='1')sss++; 
				}
				if((!o)&&(!(sss&1)))num2=0;
				if(o)num2=(1ll*num2*((p+1)/2))%p;
			}
			cout<<(num+num2)%p;
		}
	}
	else{
		if(!(c&1)){
			int num=1;
			for(int i=1;i<=c;i++){
				int o=0,sss=0;
				for(int j=1;j<=r;j++){
					if(s[j][i]=='?')o++,num=(num<<1)%p;
					if(s[j][i]=='1')sss++;
				}
				if((!o)&&(sss&1))num=0;
				if(o)num=(1ll*num*((p+1)/2))%p;
			}
			int num2=1;
			for(int i=1;i<=c;i++){
				int o=0,sss=0;
				for(int j=1;j<=r;j++){
					if(s[j][i]=='?')o++,num2=(num2<<1)%p;
					if(s[j][i]=='1')sss++;
				}
				if((!o)&&(!(sss&1)))num2=0;
				if(o)num2=(1ll*num2*((p+1)/2))%p;
			}
			cout<<(num+num2)%p;
		}
		else{
			for(int i=1;i<=c;i++)for(int j=1;j<=r;j++){
				if(s[j][i]!='?')continue;
				e[i].push_back(j+c);
				e[j+c].push_back(i);
			}
			for(int i=1;i<=c+r;i++)if(!vis[i]){
				++tot;
				dfs(i);
			}
			for(int i=1;i<=c+r;i++)ss[cc[i]].push_back(i);
			for(int i=1;i<=c;i++)for(int j=1;j<=r;j++)if(cc[i]!=cc[j+c]&&s[j][i]=='1'){
				k[cc[i]]++;
				k[cc[j+c]]++;
			}
			int ok1=1,ok2=1;
			for(int i=1;i<=tot;i++)if(k[i]&1)ok1=0;
			for(int i=1;i<=tot;i++)if((k[i]&1)!=(((int)ss[i].size())&1))ok2=0;
			int u=0;
			for(int i=1;i<=c;i++)for(int j=1;j<=r;j++)if(s[j][i]=='?')u++;
			u-=c+r;
			u+=tot;
			int ans=1;
			for(int i=1;i<=u;i++)ans=(ans<<1)%p;
			cout<<((ok1+ok2)*ans)%p;
		}
	}
	return 0;
}