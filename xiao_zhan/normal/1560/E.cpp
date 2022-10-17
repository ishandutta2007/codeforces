#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[305],vis[305],sum;
char c;
string ord,s,ans,tmp;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s;s="0"+s;
		n=s.size()-1;
		ord.clear();
		m=0;
		sum=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			if(!a[s[i]]){m++;}
			a[s[i]]++;
		}
		for(i=m;i>=1;i--){
			for(j=n;j>=1;j--){
				if(!vis[s[j]]){c=s[j];vis[c]=1;break;}
			}
			if(a[c]%i){
				cout<<-1<<'\n';goto aaa;
			}
			a[c]/=i;
			sum+=a[c];
			ord=c+ord;
		}
		
		ans.clear();
		for(i=1;i<=sum;i++){
			a[s[i]]--;
			if(a[s[i]]<0){cout<<-1<<'\n';goto aaa;}
			ans+=s[i];
		}
		tmp.clear();
		memset(vis,0,sizeof(vis));
		for(auto i:ord){
			for(auto j:ans){
				if(!vis[j]){tmp+=j;}
			}
			vis[i]=1;
		}
		tmp="0"+tmp;
		if(tmp!=s){
			cout<<-1<<'\n';goto aaa;
		}
		cout<<ans<<' '<<ord<<'\n';
		aaa:;
	}
}