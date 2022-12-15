#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MN = 1e5+5;
int arr[MN], N, L, X, Y, i, f1, f2, f3;
set<int> s;

int main(){
	for(scanf("%d%d%d%d",&N,&L,&X,&Y),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=N;i++){
		if(s.count(arr[i]-X)) f1=1;
		if(s.count(arr[i]-Y)) f2=1;
		if(s.count(arr[i]-abs(X-Y))){
			if(arr[i]+min(X,Y)<=L) f3=arr[i]+min(X,Y);
			if(arr[i]-max(X,Y)>=0) f3=arr[i]-max(X,Y);
		}
		if(s.count(arr[i]-X-Y)) f3=arr[i]-X;
		s.insert(arr[i]);
	}
	if((!f1)&&(!f2)){
		if(f3){
			printf("1\n%d\n",f3);
		}
		else printf("2\n%d %d\n",X,Y);
	}
	else if(!f1) printf("1\n%d ",X);
	else if(!f2) printf("1\n%d ",Y);
	else printf("0\n");
	return 0;
}