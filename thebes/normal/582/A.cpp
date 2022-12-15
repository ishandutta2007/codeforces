#include <bits/stdc++.h>
using namespace std;
map<int,int> cnt;
int n, i, j, x, arr[505], d[505];
void _(map<int,int>::iterator it,int i){
	if(!(it->second+=i)) cnt.erase(it);
}
void _(int id,int i){
	auto it = cnt.find(id);
	_(it, i);
}
int gcd(int a,int b){return(a)?gcd(b%a,a):b;}
int main(){
	for(scanf("%d",&n),i=1;i<=n*n;i++)
		scanf("%d",&x), cnt[x]++;
	for(j=1;j<=n;j++){
		memset(d, 0, sizeof(d));
		auto it = cnt.end(); it--;
		arr[j] = it->first; _(it,-1);
		for(i=1;i<j;i++) _(gcd(arr[i],arr[j]),-2);
		printf("%d ",arr[j]);
	}
	return 0;
}