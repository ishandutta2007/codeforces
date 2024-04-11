#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N=100005;
char s[N];
int a[N],b[N],c[N],n,m,f[N],k,tot;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=n;i;i--)f[i]=(s[i]=='0'?1:-1)+max(0,f[i+1]);
	for (int i=1,j=1;i<=n;i=j){
		while (s[i]=='0')i++,j++;
		if (i>n)break;
		while (j<=n&&s[j]==s[i])j++;
		int k=f[j];
		for (int l=i;l<j-k;l++)s[l]='0';
	}
	puts(s+1);
}