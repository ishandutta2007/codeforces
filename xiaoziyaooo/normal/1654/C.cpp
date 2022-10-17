#include<bits/stdc++.h>
#include<map>
#define int long long
using namespace std;
const int maxn=500005;
int n,T,flg,sum;
int a[maxn];
priority_queue<int>q;
map<int,int>mp;
signed main(){
	scanf("%lld",&T);
	while(T--){
		flg=0,mp.clear(),sum=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]),sum+=a[i],mp[a[i]]++;
		q.push(sum);
		int tot=n+n-1;
		while(!q.empty()){
			int x=q.top();
			tot--;
			if(tot<0){
				flg=1;
				break;
			}
			q.pop();
			if(mp[x]){
				mp[x]--;
				continue;
			}
			q.push(x/2),q.push((x+1)/2);
		}
		puts(flg==0? "YES":"NO");
		while(!q.empty())
			q.pop();
	}
	return 0;
}