#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%i",&t);
	while(t--){
		int n;scanf("%i",&n);
		vector<int> a(n);
		int cnt=0;
		for(int&i:a)scanf("%i",&i),cnt+=i&1;
		sort(a.begin(),a.end());
		bool has=0;
		for(int i=1;i<n;i++)if(a[i-1]+1==a[i])has=1;
		if(cnt%2==0||has)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}