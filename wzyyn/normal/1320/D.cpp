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
const int N=200005;
int t[N],S[N],n,mo;
int pos[N],len[N];
int le[N],ri[N];
int P0[N],P1[N];
int hsh0[N],hsh1[N];
char s[N];
int Ql(int x){
	return (ri[x]-x+1)&1;
}
int Qr(int x){
	return (x-le[x]+1)&1;
}
pii Qhash(int l,int r){
	l++; r++;
	int v0=(hsh0[r]-1ll*P0[r-l+1]*hsh0[l-1]%mo+mo)%mo;
	int v1=(hsh1[r]-1ll*P1[r-l+1]*hsh1[l-1]%mo+mo)%mo;
	return pii(v0,v1);
}
bool isprime(int x){
	for (int i=2;1ll*i*i<=x;i++)
		if (x%i==0) return 0;
	return 1;
}
int main(){
	//freopen("1.in","r",stdin);
	srand(time(NULL));
	mo=1000000007+rand();
	for (;!isprime(mo);++mo);
	//cout<<mo<<endl;
	scanf("%d",&n);
	scanf("%s",s+1);
	le[0]=1; ri[n+1]=n;
	For(i,1,n) S[i]=S[i-1]+(s[i]=='0');
	For(i,1,n) le[i]=(s[i]=='0'?i+1:le[i-1]);
	Rep(i,n,1) ri[i]=(s[i]=='0'?i-1:ri[i+1]);
	For(i,1,n) if (s[i]=='1') len[S[i]+1]^=1;
	P0[0]=P1[0]=1;
	For(i,1,n+1) P0[i]=233ll*P0[i-1]%mo;
	For(i,1,n+1) P1[i]=237ll*P1[i-1]%mo;
	For(i,1,n+1) hsh0[i]=(hsh0[i-1]*233ll+len[i])%mo;
	For(i,1,n+1) hsh1[i]=(hsh1[i-1]*237ll+len[i])%mo;
	//For(i,1,n) cout<<len[i]<<' '<<endl;
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int l,r,len;
		scanf("%d%d%d",&l,&r,&len);
		int s1=S[r+len-1]-S[r-1];
		int s2=S[l+len-1]-S[l-1];
		//cout<<s1<<' '<<s2<<endl;
		if (s1!=s2) puts("No");
		else if (!s1||s1==len) puts("Yes");
		else if (Ql(l)!=Ql(r)) puts("No");
		else if (Qr(l+len-1)!=Qr(r+len-1)) puts("No");
		else{
			int p1=S[l-1]+1,p2=S[l+len-1]-1;
			int p3=S[r-1]+1,p4=S[r+len-1]-1;
			//cout<<p1<<' '<<p2<<' '<<p3<<' '<<p4<<endl;
			puts(Qhash(p1,p2)==Qhash(p3,p4)?"Yes":"No");
		}
	}
}
/*
a,b<->a+2,b-2
:1, 
15
000001001000000
5
1 5 2
1 5 3
1 5 4
2 5 4
2 5 8
*/