#include<bits/stdc++.h>
using namespace std;
char c[210000];
int s[210000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n,m;
		scanf("%d%d",&n,&m);
		scanf("%s",c+1);
		int u=0;
		for(int i=1;i<=n;i++)if(c[i]=='1') u++;
		long long r=1ll*u*m;
		if(r%n){
			printf("-1\n");
			continue;
		}
		r/=n;
		s[0]=0;
		for(int i=1;i<=n;i++) s[i]=s[i-1]+(c[i]-'0');
		bool rr=0;
		for(int i=0;i<=n-m;i++) if(s[i+m]-s[i]==r){
			printf("1\n");
		    printf("%d %d\n",i+1,i+m);
			rr=1;
			break;
		}
		if(rr) continue;
		for(int i=1;i<m;i++){
			if(s[i]+s[n]-s[n-(m-i)]==r){
				printf("2\n1 %d\n%d %d\n",i,n-(m-i)+1,n);
				break;
			}
		}
	}
	return 0;
}