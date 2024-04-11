#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T;
int a[maxn],vis[maxn],ans[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),vis[a[i]]++;
		int L=1,R=n;
		ans[n]=1;
		for(int i=1;i<=n;i++)
			ans[n]&=vis[i]==1;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				ans[i]=1;
				if(a[L]==i)
					L++;
				else if(a[R]==i)
					R--;
				else break;
				if(vis[i]!=1)
					break;
			}
			else break;
		}
		for(int i=1;i<=n;i++)
			putchar(ans[n-i+1]+48);
		for(int i=1;i<=n;i++)
			vis[i]=ans[i]=0;
		putchar('\n');
	}
	return 0;
}