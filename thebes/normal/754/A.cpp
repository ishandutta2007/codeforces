#include <bits/stdc++.h>
using namespace std;

int arr[101], n, i, x, fl;
vector<pair<int,int>> wtf;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		if(arr[i]) fl=1;
	}
	if(!fl) printf("NO\n");
	else{
		printf("YES\n");
		int last = 1;
		for(i=1;i<=n;i++){
			if(arr[i]) wtf.push_back({last,i}),last=i+1;
		}
		if(!arr[n]) wtf.back().second=n;
		for(printf("%d\n",wtf.size()),i=0;i<wtf.size();i++)
			printf("%d %d\n",wtf[i].first,wtf[i].second);
	}
	return 0;
}