#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=55;
int n,m;
ll ans,a[MAXN],b[MAXN],c[MAXN];
inline bool cmp(const int &x,const int &y){return c[x]<c[y];}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>b[i];
	for (int i=1;i<=n;i++){
		c[i]=-0x7fffffffffffffff;
		for (int j=1;j<=m;j++) c[i]=max(c[i],a[i]*b[j]);
	}
	sort(c+1,c+1+n);
	cout<<c[n-1]<<endl; 
	return 0;
}