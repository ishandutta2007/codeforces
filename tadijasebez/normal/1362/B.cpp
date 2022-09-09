#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%i",&t);
	while(t--){
		int n;scanf("%i",&n);
		vector<int> a(n);
		for(int&i:a)scanf("%i",&i);
		sort(a.begin(),a.end());
		int ans=1e9;
		for(int j=1;j<n;j++){
			int k=a[j]^a[0];
			vector<int> b;
			for(int i=0;i<n;i++)b.push_back(a[i]^k);
			sort(b.begin(),b.end());
			if(a==b)ans=min(ans,k);
		}
		if(ans==1e9)printf("-1\n");
		else printf("%i\n",ans);
	}
	return 0;
}