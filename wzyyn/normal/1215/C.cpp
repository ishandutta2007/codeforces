#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
char a[200005],b[200005];
int n,q1[200005],q2[200005];
int k,ans1[500005],ans2[500005];
int main(){
	scanf("%d%s%s",&n,a+1,b+1);
	For(i,1,n)
		if (a[i]=='a'&&b[i]=='b') q1[++*q1]=i;
		else if (a[i]=='b'&&b[i]=='a') q2[++*q2]=i;
	if (((*q1)+(*q2))%2==1) return puts("-1"),0;
	for (;*q1>=2;*q1-=2) ans1[++k]=q1[*q1],ans2[k]=q1[(*q1)-1];
	for (;*q2>=2;*q2-=2) ans1[++k]=q2[*q2],ans2[k]=q2[(*q2)-1];
	if (*q1){
		ans1[++k]=q1[1]; ans2[k]=q1[1];
		ans1[++k]=q1[1]; ans2[k]=q2[1];
	}
	printf("%d\n",k);
	For(i,1,k) printf("%d %d\n",ans1[i],ans2[i]);
}