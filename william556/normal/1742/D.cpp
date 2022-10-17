#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=2e5+5;
int n,a[N],lst[N];
int mp[1005][1005];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void solve(){
	n=in();
	int ans=-1;
	for(int i=1;i<=n;i++){
		a[i]=in();
		lst[a[i]]=i;
		for(int j=1;j<=1000;j++){
			if(mp[a[i]][j]&&lst[j]>0){
				ans=max(ans,i+lst[j]);
			}
		}
	}
	for(int i=1;i<=n;i++)lst[a[i]]=0;
	printf("%d\n",ans);
}
int main(){
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			mp[i][j]=(gcd(i,j)==1);
	int t=in();
	while(t--)solve();
	return 0;
}