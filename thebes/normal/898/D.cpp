#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int arr[MN], cnt, n, m, k, i;
deque<int> v;

int main(){
	for(scanf("%d%d%d",&n,&m,&k),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	sort(arr+1, arr+n+1);
	for(i=1;i<=n;i++){
		v.push_back(arr[i]);
		while(v.front()<v.back()-m+1) v.pop_front();
		while(v.size()>=k){v.pop_back(); cnt++;}
	}
	printf("%d\n",cnt);
	return 0;
}