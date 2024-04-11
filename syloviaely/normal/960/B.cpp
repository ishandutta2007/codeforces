#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int A[2000],B[2000],n,a,b,m;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<=n;i++) scanf("%d",&B[i]);
	for (int i=1;i<=n;i++) A[i]=abs(A[i]-B[i]);
	for (int i=1;i<=a+b;i++){
		int where=1;
		for (int i=2;i<=n;i++) if (A[i]>A[where]) where=i;
		A[where]=abs(A[where]-1);
	}
	long long ans=0;
	for (int i=1;i<=n;i++) ans+=1ll*A[i]*A[i];
	cout<<ans<<endl;
}