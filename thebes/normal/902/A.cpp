#include <bits/stdc++.h>
using namespace std;

int p, N, M, i;
pair<int,int> a[100];
bool cmp(pair<int,int>i,pair<int,int>j){return(i.first<j.first);}

int main(){
	for(scanf("%d%d",&N,&M),i=0;i<N;i++){
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	sort(a, a+N, cmp);
	for(i=0;i<N;i++){
		if(a[i].first <= p)
			p = max(p, a[i].second);
	}
	printf("%s\n",(p>=M)?"YES":"NO");
	return 0;
}