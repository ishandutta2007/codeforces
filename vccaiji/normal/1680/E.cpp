#include<bits/stdc++.h>
using namespace std;
int n;
char s[2][210000];
int num[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		scanf("%d%s%s",&n,s[0]+1,s[1]+1);
		for(int i=1;i<=n;i++){
			num[i]=0;
			for(int j=0;j<2;j++)if(s[j][i]=='*')num[i]++;
		}
		for(int i=1;i<=n;i++)num[i]+=num[i-1];
		int ans=0;
		for(int i=1;i<=n;i++)if(s[0][i]=='*'||s[1][i]=='*'){
			ans-=i;
			break;
		}
		for(int i=n;i>=1;i--)if(s[0][i]=='*'||s[1][i]=='*'){
			ans+=i;
			break;
		}
		bool r1=0,r2=0;
		for(int i=1;i<=n;i++){
			if(s[0][i]=='*')r1=1;
			if(s[1][i]=='*')r2=1;
			if(r1&&r2){
				ans++;
				r1=0;
				r2=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}