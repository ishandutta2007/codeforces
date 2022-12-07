#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=5555;
int n,a[N],q[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		if (a[i]%2!=i%2)
			return puts("-1"),void(0);
	int p=n; *q=0;
	for (;p!=1;p-=2){
		int p1=-1,p2=-1;
		for (int i=1;i<=n;i++)
			if (a[i]==p) p2=i;
		q[++*q]=p2;
		reverse(a+1,a+p2+1);
		for (int i=1;i<=n;i++)
			if (a[i]==p-1) p1=i;
		q[++*q]=p1-1;
		reverse(a+1,a+p1);
		q[++*q]=p1+1;
		reverse(a+1,a+p1+2);
		q[++*q]=3;
		reverse(a+1,a+4);
		q[++*q]=p;
		reverse(a+1,a+p+1);
	}
	printf("%d\n",*q);
	for (int i=1;i<=*q;i++) printf("%d ",q[i]);
	puts(""); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}