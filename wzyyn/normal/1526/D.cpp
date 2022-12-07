#include<bits/stdc++.h>
using namespace std;

const int N=100005;
char s[N];
int a[N][5];
int p[5],pp[5];
int n;
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++){
		for (int j=0;j<=3;j++)
			a[i][j]=a[i-1][j];
		if (s[i]=='A') ++a[i][0];
		if (s[i]=='N') ++a[i][1];
		if (s[i]=='T') ++a[i][2];
		if (s[i]=='O') ++a[i][3];
	}
	p[0]=0; p[1]=1; p[2]=2; p[3]=3;
	long long ans=-1;
	for (;;){
		long long value=0;
		int p=0;
		for (int i=0;i<=3;i++)
			for (int j=1;j<=n;j++){
				if (a[j][::p[i]]!=a[j-1][::p[i]]){
					++p;
					for (int k=0;k<i;k++)
						value+=a[n][::p[k]]-a[j][::p[k]];
				}
			}
		if (value>ans){
			pp[0]=::p[0]; pp[1]=::p[1];
			pp[2]=::p[2]; pp[3]=::p[3];
			ans=value;
		}
		if(!next_permutation(::p,::p+4)) break;
	}
	//cout<<ans<<endl;
	for (int i=0;i<=3;i++)
		for (int j=1;j<=a[n][pp[i]];j++){
			if (pp[i]==0) putchar('A');
			if (pp[i]==1) putchar('N');
			if (pp[i]==2) putchar('T');
			if (pp[i]==3) putchar('O');
		}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}