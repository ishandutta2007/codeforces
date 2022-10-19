#include<bits/stdc++.h>
using namespace std;
int n,T;
pair<int,int>p[1010];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d",&p[i].first,&p[i].second);
		sort(p+1,p+n+1);
		bool ok=true;
		for(int i=1;i<=n;i++)if(p[i-1].second>p[i].second)ok=false;
		if(!ok){puts("NO");continue;}
		puts("YES");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=p[i].first-p[i-1].first;j++)putchar('R');
			for(int j=1;j<=p[i].second-p[i-1].second;j++)putchar('U');
		}
		puts("");
	}
	return 0;
}