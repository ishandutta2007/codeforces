#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		cin>>n>>s;
		for(int i=0;i+1<n;i++)
			ans+=s[i]==s[i+1];
		printf("%d\n",(ans+1)/2);
	}
	return 0;
}