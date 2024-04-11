#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N],q[N];
void construct(int l,int r){
	for (int i=l;i<=r-2;i+=2)
		q[++*q]=i;
	for (int i=r-4;i>=l;i-=2)
		q[++*q]=i;
}
void output(){
	puts("YES");
	for (int i=0;i<=*q;i++)
		printf("%d%c",q[i],i==0||i==*q?'\n':' ');
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int s=0;
	for (int i=1;i<=n;i++) s^=a[i];
	if (s) return puts("NO"),void(0);
	if (n&1){
		*q=0;
		construct(1,n);
		output();
	}
	else{
		s=0;
		for (int i=1;i<=n;i++){
			s^=a[i];
			if (i&1)
				if (!(s&1)){
					*q=0;
					construct(1,i);
					construct(i+1,n);
					output();
					return;
				}
		}
		puts("NO");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}