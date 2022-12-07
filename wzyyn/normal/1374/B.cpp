#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
#define all(v) v.begin(),v.end()
using namespace std;

void mian(){
	int n,s2=0,s3=0;
	cin>>n;
	for (;n%2==0;n/=2,s2++);
	for (;n%3==0;n/=3,s3++);
	if (n!=1||s2>s3) puts("-1");
	else printf("%d\n",s3+max(s3-s2,0));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) mian();
}