#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,a[10005];
		scanf("%d",&n);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			scanf("%1d",&a[i]);
			if(a[i]==0)cnt1++;
			else cnt2++;
		}
		queue<int>q;
		for(int i=1;i<=cnt1;i++){
			if(a[i]==1)q.push(i);
		}
		for(int i=cnt1+1;i<=n;i++){
			if(a[i]==0)q.push(i);
		}
		if(!(int)q.size())printf("0\n");
		else{
			printf("1\n%d ",(int)q.size());
			while(q.size())printf("%d ",q.front()),q.pop();
			puts("");
		}
	}
	return 0;
}