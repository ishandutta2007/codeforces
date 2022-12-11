#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		long long x;
		scanf("%d%d%lld\n",&n,&k,&x);
		x--;
		int cnt=0;
		vector<long long>v;
		char s[2005];
		for(int i=1;i<=n;i++)
			if((s[i]=getchar())=='*')cnt++;
			else if(cnt!=0)v.push_back(cnt),cnt=0; 
		if(cnt)v.push_back(cnt);
		long long val[2005];
		if(v.size())val[v.size()-1]=1;
		for(int i=v.size()-1;i>0;i--){
			if(log10(v[i]*k+1)+log10(val[i])>18.5)val[i-1]=2e18;
			else val[i-1]=val[i]*(v[i]*k+1);
		}
		long long tot[2005];
		for(int i=0;i<(int)v.size();i++){
			tot[i]=x/val[i];
			x%=val[i];
		}
		int now=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='*'){
				for(int o=0;o<tot[now];o++)putchar('b');
				while(i<=n&&s[i+1]=='*')i++;
				now++;
				continue;
			}
			if(s[i]=='a')putchar('a');
		}
		puts("");
	}
	return 0;
}