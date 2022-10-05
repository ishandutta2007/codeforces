#include <bits/stdc++.h>
using namespace std;
int n,T,a[200010],s[100010];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	scanf("%d",a+i),s[i]=s[i-1]+a[i];
	cin>>T;
	while(T--){
		int l,r;
		scanf("%d%d",&l,&r);
		cout<<(s[r]-s[l-1])/10<<endl;
	}
	return 0;
}