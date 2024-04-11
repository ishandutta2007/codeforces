#include<bits/stdc++.h>
using namespace std;

const int maxn=300007;
int a[maxn],p[maxn],n,pos=0,s[maxn];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i+n]=a[i+n*2]=a[i];
	}
	for (int i=1;i<=3*n;++i){
		while (pos&&a[s[pos]]<=a[i]) pos--;
		s[++pos]=i;
		if (a[s[1]]<=2*a[i]){
			p[i]=0;
			continue;
		}
		int l=1,r=pos;
		while (l<r){
			int md=(l+r)>>1;
			if (a[s[md+1]]<=2*a[i]){
				r=md;
			}
			else{
				l=md+1;
			}
		}
		p[i]=s[l];
	}
	int u=1;
	for (int i=1;i<=n;++i){
		while (u<=3*n&&p[u]<i) u++;
		if (u==3*n+1){
			printf("-1 ");
		} 
		else{
			printf("%d ",u-i);
		}
	}
	return 0;
}