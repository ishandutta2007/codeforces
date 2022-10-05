#include<bits/stdc++.h>
using namespace std;
char a[210000];
char b[210000];
int f(int n){
	return (n+1)/3;
}
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		scanf("%s",a+1);
		bool p=0;
		for(int i=1;i<=n;i++)if(a[i]!=a[1])p=1;
		if(!p){
			cout<<1+f(n-2)<<endl;
			continue;
		}
		if((a[1]=='L')||(a[n]=='R')){
			for(int i=1;i<n;i++){
				if((a[i]=='L')&&(a[i+1]=='R')){
					for(int j=1;j<=n;j++) b[j]=a[(j+i-1)%n+1];
					break;
				}
			}
		}
		else for(int i=1;i<=n;i++) b[i]=a[i];
		int ans=0;
		for(int i=1;i<=n-1;i++){
			if((b[i]=='R')&&(b[i+1]=='L')){
				int cnt=0;
				for(int j=i-1;j>=1;j--){
					if(b[j]=='R')cnt++;
					else break;
				}
				int cnt2=0;
				for(int j=i+2;j<=n;j++){
					if(b[j]=='L')cnt2++;
					else break;
				}
				ans+=f(cnt)+f(cnt2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}