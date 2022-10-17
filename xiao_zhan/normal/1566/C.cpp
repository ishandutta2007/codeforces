#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,res,l,r,vis[200500];
char s1[100500],s2[100500];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	//scanf("%d",&t);
	while(t--){
		res=0;
		cin>>n;
		cin>>s1+1;
		cin>>s2+1;
		memset(vis,0,n*4+50);
		
		for(i=1;i<=n;i++){
			s1[i]-='0';s2[i]-='0';
			if(s1[i]^s2[i]){
				res+=2;vis[i]=1;
			}
		}
		vis[0]=vis[n+1]=1;
		for(i=1;i<=n;i++){
			if(vis[i]){continue;}
			if(s1[i]==1){
				if(!vis[i-1]&&s1[i-1]==0){
					res+=2;vis[i-1]=vis[i]=1;continue;
				}
				if(!vis[i+1]&&s1[i+1]==0){
					res+=2;vis[i+1]=vis[i]=1;continue;
				}
			}
		}
		for(i=1;i<=n;i++){
			if(!vis[i]&&s1[i]==0){
				res++;
			}
		}
		cout<<res<<'\n';
	}
}