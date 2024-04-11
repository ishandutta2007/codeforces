#include<bits/stdc++.h>
using namespace std;
char a[1100000];
int o[1100000];
int oo[1100000];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n,m;
		cin>>n>>m;
		scanf("%s",a+1);
		int cnt=0;
		o[0]=0;
		for(int i=1;i<=n*m;i++){
			cnt+=a[i]-'0';
			if(i>m)cnt-=a[i-m]-'0';
			if(cnt)o[i]=1;
			else o[i]=0;
		}
		for(int i=m;i<=n*m;i++)o[i]+=o[i-m];
		for(int i=1;i<=n*m;i++){
			if(i>=m+1)oo[i]=oo[i-m];
			else oo[i]=0;
			if(a[i]=='1')oo[i]=1;
		}
		int ans=0;
		for(int i=1;i<=n*m;i++){
			ans+=oo[i];
			if(i>m)ans-=oo[i-m];
			printf("%d ",ans+o[i]);
		}
		printf("\n");
	}
	return 0;
}