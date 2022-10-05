#include<bits/stdc++.h>
using namespace std;
int p[210000];
int ch[210000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		cin>>n;
		for(int i=0;i<=n;i++)ch[i]=0;
		p[1]=0;
		for(int i=2;i<=n;i++)cin>>p[i];
		for(int i=1;i<=n;i++)ch[p[i]]++;
		sort(ch,ch+n+1);
		int ans=0;
		for(int j=n;j>=0;j--){
			if(ch[j])ans++;
		}
		int o=n-ans+1;
		for(int j=n;j>=o;j--)ch[j]=max(0,ch[j]-(ans-(n-j)));
		int l=0,r=n;
		for(;l<r;){
			int md=(l+r)/2;
			int s=0;
			for(int j=n;j>=o;j--)s+=max(ch[j]-md,0);
			if(s<=md)r=md;
			else l=md+1;
		}
		cout<<ans+l<<endl;
	}
	return 0; 
}