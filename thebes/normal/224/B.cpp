#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
map<int,int> cnt;
int tot, N, K, i, arr[MN], l, r, ans=1<<30, a=-1, b=-1;

int main(){
	for(scanf("%d%d",&N,&K),i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}
	for(r=l=1;r<=N;r++){
		cnt[arr[r]]++;
		while(true){
			cnt[arr[l]]--;
			if(cnt[arr[l]]==0) cnt.erase(arr[l]);
			if(cnt.size()<K) break;
			else l++;
		}
		cnt[arr[l]]++;
		if(r-l+1<ans&&cnt.size()>=K) ans=r-l+1,a=l,b=r;
	}
	printf("%d %d\n",a,b);
	return 0;
}