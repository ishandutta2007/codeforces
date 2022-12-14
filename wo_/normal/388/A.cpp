#include<cstdio>

using namespace std;

int a[110];

bool check(int n){
	int cnt=0;
	for(int i=0;i<110;i++){
		cnt+=a[i];
		if(cnt>n*(i+1)) return false;
	}
	return true;
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	int lb=0,ub=N;
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		if(check(mid)) ub=mid;
		else lb=mid;
	}
	printf("%d\n",ub);
}