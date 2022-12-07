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
using namespace std;
const int N=500005;
int n,Q,a[N],pr[N][26];
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n) a[i]=(a[i-1]+(s[i]!=s[i-1])); 
	For(i,1,n){
		For(j,0,25) pr[i][j]=pr[i-1][j];
		pr[i][s[i]-'a']=i;
	} 
	scanf("%d",&Q);
	while (Q--){
		int l,r,c=0;
		scanf("%d%d",&l,&r);
		For(j,0,25) c+=(pr[r][j]>=l);
		//cout<<a[l]<<' '<<a[r]<<endl;
		if (l==r) puts("Yes");
		else if (c==1) puts("No");
		else if (c==2) puts(s[l]==s[r]?"No":"Yes");
		else puts("Yes");
	}
}