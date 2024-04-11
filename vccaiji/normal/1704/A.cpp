#include<bits/stdc++.h>
using namespace std;
char a[1100],b[1100];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		int m;
		cin>>m;
		scanf("%s%s",a+1,b+1);
		bool r=0;
		for(int i=2;i<=m;i++)if(a[i+n-m]!=b[i])r=1;
		if(a[1+n-m]!=b[1]){
			bool t=1;
			for(int j=1;j<=n-m;j++)if(a[j]==b[1])t=0;
			if(t)r=1;
		}
		if(r)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}