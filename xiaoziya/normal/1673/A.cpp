#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		cin>>s,n=s.size();
		for(int i=0;i<n;i++)
			ans+=s[i]-96;
		int sum=ans;
		if(n&1)
			ans-=min(s[0],s[n-1])-96;
		if(ans>sum-ans)
			printf("Alice %d\n",ans-sum+ans);
		else printf("Bob %d\n",sum-ans-ans);
	}
	return 0;
}