#include<bits/stdc++.h>
using namespace std;

int n,ans[2000007];
int main(){
	cin>>n;
	if (n%2){
		puts("YES");
		for (int i=1;i<=n;++i){
			if (i%2){
				ans[i]=i;
			}
			else{
				ans[i]=2*(n+1)-i;
			}
		}
		for (int i=1;i<=n;++i){
			if (ans[i]%2){
				ans[n+i]=ans[i]+1;
			}
			else{
				ans[n+i]=ans[i]-1;
			}
		}
		for (int i=1;i<=2*n;++i){
			cout<<ans[i]<<" ";
		}
	}
	else{
		puts("NO");
	}
	return 0;
}