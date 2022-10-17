#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn];
map<int,int>mp;
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=-1,mp.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(mp.count(a[i]))
				ans=max(ans,n-i+mp[a[i]]);
			mp[a[i]]=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}