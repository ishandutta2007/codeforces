#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,flg;
long long ans;
int a[maxn];
string s;
map<int,int>mp;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),cin>>s,ans=0;
		int sum=0;
		mp.clear(),mp[0]++;
		for(int i=1;i<=n;i++){
			a[i]=s[i-1]-48,sum+=a[i]-1;
			ans+=mp[sum],mp[sum]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}