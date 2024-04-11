#include<bits/stdc++.h>
using namespace std;

int query(int u,int v){
	cout<<"? "<<u<<" "<<v<<endl;
	int w;
	cin>>w;
	return w;
}
const int maxn=200007;
int a[maxn];
int main(){
	int n;
	cin>>n;
	int j=1;
	for (int i=2;i<=n;++i){
		int aa=query(i,j), bb=query(j,i);
		if (aa<bb) a[j]=bb, j=i;
		else a[i]=aa;
	}
	a[j]=n;
	cout<<"! ";
	for (int i=1;i<=n;++i) cout<<a[i]<<" ";
}