#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		vector<int> a(n+1),b(n+1),pos(n+1);
		vector<vector<int>> A(n+1),B(n+1);
		for(int i=1;i<=n;i++)scanf("%i",&a[i]),A[a[i]].pb(i);
		for(int i=1;i<=n;i++)scanf("%i",&b[i]),B[b[i]].pb(i);
		bool ok=1;
		for(int i=1;i<=n;i++){
			if(A[i].size()!=B[i].size()){ok=0;break;}
			for(int j=0;j<A[i].size();j++)pos[A[i][j]]=B[i][j];
		}
		if(!ok)printf("NO\n");
		else{
			vector<int> mx(n+1,0);
			for(int i=1;i<=n;i++){
				int ans=0;
				for(int j=a[i]-1;j;j-=j&-j)ans=max(ans,mx[j]);
				if(ans>pos[i]){ok=0;break;}
				for(int j=a[i];j<=n;j+=j&-j)mx[j]=max(mx[j],pos[i]);
			}
			if(ok)printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}