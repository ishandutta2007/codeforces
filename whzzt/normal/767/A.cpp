#include"bits/stdc++.h"
using namespace std;

const int N=100005;
int n,a[N],p[N],mx;
vector<int>e[N];

int main(){
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[a[i]]=i;
	for(int i=n;i>=1;i--){
		mx=max(mx,p[i]);
		e[mx].push_back(i);
	}
	
	for(int i=1;i<=n;i++){
		int L=e[i].size();
		for(int j=0;j<L;j++)
			printf("%d ",e[i][j]);
		putchar('\n');
	}
		 
	return 0;
}