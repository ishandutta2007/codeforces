#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int Ask(int i){
	printf("? %i\n",i);
	fflush(stdout);
	int x;
	scanf("%i",&x);
	return x;
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		vector<int> vis(n+1),ans(n+1);
		for(int i=1;i<=n;i++)if(!vis[i]){
			vector<int> v;
			v.pb(Ask(i));
			while(true){
				v.pb(Ask(i));
				if(v[0]==v.back())break;
			}
			v.pop_back();
			for(int x:v)vis[x]=1;
			for(int j=0;j<v.size();j++)ans[v[j]]=v[(j+1)%v.size()];
		}
		printf("! ");
		for(int i=1;i<=n;i++)printf("%i ",ans[i]);
		fflush(stdout);
		printf("\n");
	}
	return 0;
}