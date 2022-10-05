#include<bits/stdc++.h>
using namespace std;
int n;
char s[110000];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n;
		scanf("%s",s+1);
		int ans=0;
		for(int i=1;i<=n;i++)if(s[i]!=s[i%n+1])ans++;
		cout<<(n-ans)/2<<endl;
	}
	return 0;
}