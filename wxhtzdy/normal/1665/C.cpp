#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int t,n,cnt[N];
int main(){
	for(scanf("%i",&t);t;t--){
		scanf("%i",&n);
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=2;i<=n;i++){
			int p;scanf("%i",&p);
			cnt[p]++;
		}
		vector<int> a(1,1);
		for(int i=1;i<=n;i++)if(cnt[i]>0)a.push_back(cnt[i]);
		sort(a.rbegin(),a.rend());
		int sz=a.size();
		for(int i=0;i<sz;i++)a[i]-=(sz-i);
		int low=0,high=n,ans=0;
		while(low<=high){
			int mid=low+high>>1;
			int s=0;
			for(int i=0;i<sz;i++)s+=max(0,a[i]-mid);
			if(s<=mid)ans=mid,high=mid-1;
			else low=mid+1;
		}
		printf("%i\n",ans+sz);
	}
}