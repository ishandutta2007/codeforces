#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,a[300005],to=0;
		memset(a,0,sizeof a);
		char s;
		string s1;
		scanf("%d %c\n",&n,&s);
		cin>>s1;
		for(int i=0;i<(int)s1.length();i++){
			if(s1[i]==s)a[i+1]=1;
			else to++;
		}
		if(to==0){
			printf("0\n");
			continue;
		}
		int pd=0;
		for(int i=n/2+1;i<=n;i++){
			if(a[i]){
				printf("1\n%d\n",i);
				pd=1;
				break;
			}
		}
		if(pd)continue;
		printf("2\n%d %d\n",n,n-1);
	}
	return 0;
}