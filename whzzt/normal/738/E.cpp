#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N=200005;
int n,s,fa[N],sum[N],ans,up;
int main(){
	cin>>n>>s;int last=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&fa[i]),sum[fa[i]]++;
		last=max(last,fa[i]);
	}
	if (fa[s]) ans++,sum[fa[s]]--,sum[0]++;
	if (sum[0]>1) ans+=sum[0]-1,up+=sum[0]-1,sum[0]=1;
	while (sum[last]==0) last--;
	for(int i=1;i<=last;i++){
		if(sum[i]==0){
			if (up) up--,sum[i]++;
			else {
				ans++,sum[last]--;
				sum[i]++;
			}
		}
		while(sum[last]==0) last--;
	}
	cout<<ans<<endl;
	return 0;
}