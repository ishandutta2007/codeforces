#include <bits/stdc++.h>
using namespace std;

const int MN = 100005;
pair<int,int> ans[MN];
int N, M, i, l, tp, mx, arr[MN];
deque<int> a[2];

void mono(int p, int x){
	while(a[p].size() && ((p==0&&x<a[p].back())||(p==1&&x>a[p].back())))
		a[p].pop_back();
	a[p].push_back(x);
}

int main(){
	for(scanf("%d%d",&N,&M),l=1,i=1;i<=N;i++){
		scanf("%d",&arr[i]);
		mono(0, arr[i]); mono(1, arr[i]);
		while(a[1].front()-a[0].front() > M){
			if(a[0].front() == arr[l]) a[0].pop_front();
			if(a[1].front() == arr[l]) a[1].pop_front();
			l++;
		}
		if(i-l+1 > mx){
			mx = i-l+1; tp = 0;
			ans[tp] = {l,i};
		}
		else if(i-l+1 == mx) ans[++tp] = {l,i};
	}
	printf("%d %d\n",mx,tp+1);
	for(i=0;i<=tp;i++) 
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}