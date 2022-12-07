#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define uint unsigned
using namespace std;
const int N=1000005;
int n;
char ans[N];
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int l=1,r=n,ll=1,rr=n;
	while (r-l+1>=4){
		int p1=100,p2=100;
		For(i,0,2) For(j,0,2)
			if (s[l+i]==s[r-j]&&i+j<p1+p2)
				p1=i,p2=j;
		ans[ll++]=s[l+p1];
		ans[rr--]=s[r-p2];
		l+=p1+1; r-=p2+1;
	}
	if (l<=r) ans[ll++]=s[l];
	For(i,1,ll-1) putchar(ans[i]);
	For(i,rr+1,n) putchar(ans[i]);
}