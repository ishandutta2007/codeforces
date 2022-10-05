#include<bits/stdc++.h>
using namespace std;
int a[1100000],b[1100000];
char s[1100000];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		scanf("%s",s+1);
		if(s[1]!='9'){
			for(int j=1;j<=n;j++)printf("%d",9-(s[j]-'0'));
			printf("\n");
			continue;
		}
		int r=0;
		for(int i=n;i>=1;i--){
			int u=1-r-(s[i]-'0');
			if(u<0)b[i]=u+10,r=1;
			else b[i]=u,r=0; 
		}
		for(int j=1;j<=n;j++)printf("%d",b[j]);
		printf("\n");
		continue;
	}
	return 0;
}