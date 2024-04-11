#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=305;
int a[N],b[N];
int px[N],py[N],n,t;
void solve(){
	scanf("%d",&n);
	int s=0;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
		s+=a[i]-b[i];
	if (s){
		puts("-1");
		return;
	}
	t=0;
	for (int i=1;i<=n;i++)
		for (;a[i]>b[i];){
			for (int j=1;j<=n;j++)
				if (a[j]<b[j]){
					px[++t]=i;
					py[t]=j;
					--a[i];
					++a[j];
					break;
				}
		}
	printf("%d\n",t);
	for (int i=1;i<=t;i++)
		printf("%d %d\n",px[i],py[i]);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}