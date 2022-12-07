#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;

int a[205];
int ipow(int x){
	for (;x%10==0;x/=10);
	return x==1;
}
int split(int x){
	int t=x,v=1;
	for (;x>=10;x/=10,v*=10);
	return v==t?v/10:v;
}
void solve(){
	int s,n;
	scanf("%d%d",&s,&n);
	int t=1; a[1]=s;
	for (;t!=n;){
		int p=-1;
		for (int i=1;i<=t;i++)
			if (!ipow(a[i])) p=i;
		if (p==-1)
			for (int i=1;i<=t;i++)
				if (a[i]!=1&&(p==-1||a[i]<a[p])) p=i;
		int x=a[p];
		for (int j=p+1;j<=t;j++) a[j-1]=a[j];
		a[t]=split(x); a[++t]=x-split(x);
	}
	for (int i=1;i<=t;i++)
		printf("%d ",a[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}