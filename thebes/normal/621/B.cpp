#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
long long ans;int N, i, x, y, j;
pii arr[200005]; int v(int i){return(arr[i].first-arr[i].second);}
int v2(int i){return(arr[i].first+arr[i].second);}
bool cmp(pii i,pii j){return(i.first-i.second>j.first-j.second);}
bool cmp2(pii i,pii j){return(i.first+i.second<j.first+j.second);}

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d%d",&arr[i].first,&arr[i].second);
	sort(arr+1, arr+N+1, cmp);
	for(i=1;i<=N;i=j){
		j=i;
		while(j<=N&&v(j)==v(i)) j++;
		ans += (j-i)*(j-i-1)/2;
	}
	sort(arr+1, arr+N+1, cmp2);
	for(i=1;i<=N;i=j){
		j=i;
		while(j<=N&&v2(j)==v2(i)) j++;
		ans += (j-i)*(j-i-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}