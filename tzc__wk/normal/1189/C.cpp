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
/*
7
1 2 3 4 5 6 7
5
1 4
1 2
6 7
3 3
4 7
*/