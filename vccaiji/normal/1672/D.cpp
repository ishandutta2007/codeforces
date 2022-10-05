#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[210000];
int a[210000];
int b[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)cnt[i]=0;
		int j=n,k=n;
		bool ok=1;
		while(j>0){
			if(k>=2&&b[k]==b[k-1]){
				cnt[b[k]]++;
				k--;
				continue;
			}
			if(k>=1&&b[k]==a[j]){
				j--;k--;
				continue;
			}
			if(cnt[a[j]]==0){
				ok=0;
				break;
			}
			cnt[a[j]]--;
			j--;
		}
		printf(ok ? "YES\n" : "NO\n");
	}
	return 0;
}