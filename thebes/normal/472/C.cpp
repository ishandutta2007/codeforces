#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
struct st{string s, t;}arr[MN];
int x, N, i, flag; string mx="";

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		cin >> arr[i].s >> arr[i].t;
		if(arr[i].s>arr[i].t) 
			swap(arr[i].s,arr[i].t);
	}
	for(i=1;i<=N;i++){
		scanf("%d",&x);
		if(arr[x].s>mx) mx=arr[x].s;
		else if(arr[x].t>mx) mx=arr[x].t;
		else flag = 1;
	}
	printf("%s\n",(flag)?"NO":"YES");
	return 0;
}