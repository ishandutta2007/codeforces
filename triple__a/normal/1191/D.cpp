#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
int n;
long long a[maxn],ans[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%dll",&a[i]);
	}
	sort(a+1,a+n+1);
	bool fg=false;
	for (int i=1;i<=n-2;++i){
		if (a[i]==a[i+1]-1&&a[i+1]==a[i+2]){
			cout<<"cslnb";
			return 0;
		}
	} 
	for (int i=1;i<=n-1;++i){
		if (a[i]==a[i+1]){
			if (fg||a[i]==0){
				cout<<"cslnb";
				return 0;
			}
			else{
				fg=true;
			}
		}
	}
	long long u=0;
	for (int i=1;i<=n;++i){
		if (a[i]+1<i){
			cout<<"cslnb";
			return 0;
		}
		u+=(a[i]-i+1);
	}
	if (u%2){
		cout<<"sjfnb";
	}
	else{
		cout<<"cslnb";
	}
	return 0;
}