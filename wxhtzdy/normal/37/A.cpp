#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1050;
int n,a[N],cnt[N],sol,mx=0;
void cl(){for(int i=0;i<N;i++)cnt[i]=0;}
int main(){
	scanf("%i",&n);
	cl(); sol=n;
	for(int i=0;i<n;i++){
		scanf("%i",&a[i]);
		cnt[a[i]]++,mx=max(mx,cnt[a[i]]);
		if(cnt[a[i]]>=2)sol--;
	}
	printf("%i %i",mx,sol);
}