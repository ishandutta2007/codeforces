#include <bits/stdc++.h>
using namespace std;

int arr[101], tot, n, i;
int rnd(double lol){
	int w = lol; lol-=w;
	if(lol>=0.5) return w+1;
	else return w;
}
int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]),tot+=arr[i];
	sort(arr+1,arr+n+1);
	if(rnd(tot/(double)n)==5) printf("0\n");
	else{
		for(i=1;i<=n;i++){
			tot += 5-arr[i];
			if(rnd(tot/(double)n)==5){
				printf("%d\n",i);
				break;
			}
		}
	}
	getchar(); getchar();
}