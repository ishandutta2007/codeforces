#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=500005;
int n,m;
char s[N];
int a[N][3];
int Calc(int l,int r,string s){
	int sum=0;
	for (int i=0;i<=2;i++){
		int nl=l+i,nr=max(r+1,l+i);
		for (;nr%3!=nl%3;++nr);
		sum+=(nr>=3?a[nr-3][s[i]-'a']:0)-
			 (nl>=3?a[nl-3][s[i]-'a']:0); 
	}
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n+3;i++)
		for (int j=0;j<=2;j++)
			a[i][j]=((i>=3?a[i-3][j]:0)+(s[i]=='a'+j));
	while (m--){
		int l,r;
		scanf("%d%d",&l,&r);
		int M=0;
		M=max(M,Calc(l,r,"abc"));
		M=max(M,Calc(l,r,"acb"));
		M=max(M,Calc(l,r,"bac"));
		M=max(M,Calc(l,r,"bca"));
		M=max(M,Calc(l,r,"cab"));
		M=max(M,Calc(l,r,"cba"));
		printf("%d\n",(r-l+1)-M);
	}
}