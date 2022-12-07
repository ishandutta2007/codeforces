#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

char s[200005];
int n,a[30],id[30];
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=0;i<=25;i++) a[i]=0;
	for (int i=1;i<=n;i++) ++a[s[i]-'a'];
	int sum=0,p=-1,q=-1,r=-1;
	for (int i=0;i<=25;i++)
		if (a[i]){
			++sum;
			if (p==-1) p=i; 
			else if (q==-1) q=i;
			else if (r==-1) r=i;
		}
	for (int i=0;i<=25;i++)
		if (a[i]==1){
			putchar(i+'a');
			for (int j=0;j<=25;j++) if (j!=i)
				for (int k=0;k<a[j];k++)
					putchar(j+'a');
			puts("");
			return;
		}
	if (sum==1){
		for (int i=0;i<=25;i++)
			for (int j=0;j<a[i];j++)
				putchar(i+'a');
	}
	else if (sum==2){
		if (a[p]<=a[q]+2){
			putchar(p+'a');
			putchar(p+'a');
			for (int i=3;i<=a[p];i++){
				putchar(q+'a');
				putchar(p+'a'); 
			}
			for (int i=a[p]-1;i<=a[q];i++)
				putchar(q+'a');
		}
		else{
			putchar(p+'a');
			--a[p];
			for (int i=25;i>=0;i--)
				for (int j=0;j<a[i];j++)
					putchar(i+'a');
		}
	}
	else if (a[p]*2<=n+2){
		q=0;
		putchar(p+'a');
		putchar(p+'a');
		a[p]-=2;
		for (;a[p];){
			for (;q==p||!a[q];++q);
			putchar(q+'a');
			putchar(p+'a');
			--a[p]; --a[q];
		}
		for (;;){
			for (;q<=25&&!a[q];++q);
			if (q>25) break;
			putchar(q+'a');
			--a[q];
		}
	}
	else{
		putchar(p+'a');
		putchar(q+'a');
		--a[p]; --a[q];
		for (int i=1;i<=a[p];i++)
			putchar(p+'a');
		putchar(r+'a'); --a[r];
		for (int i=p+1;i<=25;i++)
			for (int j=0;j<a[i];j++)
				putchar(i+'a');	
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*

*/