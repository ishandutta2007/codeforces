#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		vector<int> a(n*2);
		for(int &i:a)scanf("%i",&i),i=i==2?-1:1;
		map<int,int>mn;
		mn[0]=n;
		for(int i=0,bal=0;i<n;i++)bal+=a[i],mn[bal]=n-i-1;
		int ans=mn[0]+n;
		for(int i=n*2-1,bal=0;i>=n;i--)bal-=a[i],ans=min(ans,i-n+(mn.count(bal)?mn[bal]:n*5));
		printf("%i\n",ans);
	}
	return 0;
}