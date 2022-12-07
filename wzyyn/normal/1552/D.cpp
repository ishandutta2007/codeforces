#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

int n,a[20],S[1050];
void solve(){
	scanf("%d",&n);
	memset(S,0,sizeof(S));
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<1<<n;i++)
		for (int j=0;j<n;j++)
			if (i&(1<<j)) S[i]+=a[j+1];
	for (int i=0;i<1<<n;i++){
		int rem=(1<<n)-i-1;
		for (int j=rem;j;j=(j-1)&rem)
			if (S[i]==S[j]){
				puts("YES");
				return;
			}
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}