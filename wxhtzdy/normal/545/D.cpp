#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int n;
	scanf("%i",&n);
	int t[n];
	for(int i=0;i<n;i++)scanf("%i",&t[i]);
	sort(t,t+n);
	int sum=0,cnt=0;
	for(int i=0;i<n;i++){
		if(t[i]<sum)continue;
		cnt++,sum+=t[i];
	}
	printf("%i",cnt);
}