#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
int n,m;
int main(){
	cin>>n>>m;
	if(n+m==2)return cout<<0,0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",m>1?i*(n+j):j*(m+i));
		}
		puts("");
	}
	return 0;
}