#include<bits/stdc++.h>

using namespace std;

const int maxn = 107;
int n,k;
int a[maxn];

int main(){
	cin>>n>>k;
	for (int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	int l=0,r=0,ans=0;
	while(r<n){
		if (a[r]-a[l]>k){
			ans=max(ans,r-l);
			while(a[r]-a[l]>k){
				l++;
			}
		}
		r++;
	}
	ans=max(ans,r-l);
	printf("%d\n",n-ans);
}