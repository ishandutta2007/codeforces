#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	int ans=-1e9; scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1);
		if (k1<0){
			ans=max(ans,k1);
		} else {
			int num=sqrt(k1);
			while (num*num>k1) num--;
			while (num*num<k1) num++;
			if (num*num!=k1) ans=max(ans,k1);
		}
	}
	cout<<ans<<endl;	
}