#include<bits/stdc++.h>

using namespace std;

int n,k;
int a[105],b[105];
void solve(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i]>a[j]){
				swap(a[i],a[j]);
				swap(b[i],b[j]);
			}
	for (int i=1;i<=n;i++)
		if (k>=a[i]) k+=b[i];
	cout<<k<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}