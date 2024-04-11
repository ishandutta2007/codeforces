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
const int mo=1000000007;
char s[505];
int f[505][1<<16];
int a[1<<16],b[1<<16];
int n,nd;
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int solve(int l,int r){
	int x=++nd;
	if (l==r){
		//cout<<l<<' '<<r<<endl;
		For(i,0,3)
			if (s[l]=='?'||s[l]=='A'+i){
				int sta=0;
				For(j,0,15)
					sta|=((j>>i)&1)<<j;
				++f[x][sta];
			}
		For(i,0,3)
			if (s[l]=='?'||s[l]=='a'+i){
				int sta=0;
				For(j,0,15)
					sta|=(((j>>i)&1)^1)<<j;
				++f[x][sta];
			}
	}
	else{
		int sum=0,mid=0;
		For(j,l,r)
			if (s[j]==')') sum--;
			else if (s[j]=='(') sum++;
			else if (!sum){
				mid=j;
				break;
			}
		int ls=solve(l+1,mid-2);
		int rs=solve(mid+2,r-1);
		//cout<<ls<<' '<<rs<<endl;
		if (s[mid]=='?'||s[mid]=='|'){
			memcpy(a,f[ls],sizeof(a));
			memcpy(b,f[rs],sizeof(b));
			for (int d=1;d<1<<16;d<<=1)
				for (int i=0;i<1<<16;i+=d<<1)
					for (int j=0;j<d;j++){
						UPD(a[i+j+d],a[i+j]);
						UPD(b[i+j+d],b[i+j]);
					}	
			For(i,0,(1<<16)-1)
				a[i]=1ll*a[i]*b[i]%mo;
			for (int d=1;d<1<<16;d<<=1)
				for (int i=0;i<1<<16;i+=d<<1)
					for (int j=0;j<d;j++)
						UPD(a[i+j+d],mo-a[i+j]);
			For(i,0,(1<<16)-1)
				UPD(f[x][i],a[i]);
		}
		if (s[mid]=='?'||s[mid]=='&'){
			memcpy(a,f[ls],sizeof(a));
			memcpy(b,f[rs],sizeof(b));
			for (int d=1;d<1<<16;d<<=1)
				for (int i=0;i<1<<16;i+=d<<1)
					for (int j=0;j<d;j++){
						UPD(a[i+j],a[i+j+d]);
						UPD(b[i+j],b[i+j+d]);
					}
			For(i,0,(1<<16)-1)
				a[i]=1ll*a[i]*b[i]%mo;
			for (int d=1;d<1<<16;d<<=1)
				for (int i=0;i<1<<16;i+=d<<1)
					for (int j=0;j<d;j++)
						UPD(a[i+j],mo-a[i+j+d]);
			For(i,0,(1<<16)-1)
				UPD(f[x][i],a[i]);
		}
	}
	return x;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	solve(1,n);
	int m;
	scanf("%d",&m);
	For(i,1,m){
		a[i]=0;
		For(j,1,4){
			int x;
			scanf("%d",&x);
			a[i]|=x<<(j-1);
		}
		scanf("%d",&b[i]);
		//cout<<a[i]<<' '<<b[i]<<endl;
	}
	int ans=0;
	For(i,0,(1<<16)-1){
		//if (f[1][i]) cout<<f[1][i]<<' '<<i<<endl;
		bool flg=0;
		For(j,1,m)
			if (((i>>a[j])^b[j])&1)
				flg=1;
		if (!flg)
			UPD(ans,f[1][i]);
	}
	printf("%d\n",ans);
}