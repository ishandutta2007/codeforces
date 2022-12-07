#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second 
#define PB push_back
#define ll long long
using namespace std;

const int N=100005;
char s[N];
int q[N],q2[N],n;
void solve(){
	scanf("%d",&n); 
	scanf("%s",s+1);
	*q=*q2=0;
	For(i,1,n)
		if (s[i]=='M') q[++*q]=i;
		else q2[++*q2]=i;
	if (*q!=n/3) puts("NO");
	else{
		bool flg=0;
		For(i,1,*q) if (q2[i]>q[i]) flg=1;
		For(i,1,*q) if (q2[i+(*q)]<q[i]) flg=1;
		puts(flg?"NO":"YES");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}