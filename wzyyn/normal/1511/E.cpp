#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=300005;
const int mo=998244353;
char s[N];
char t1[N*2],t2[N*2];
int n,m,ans,f1[N*2][2],f2[N*2][2];
void solve(int n,char* c){
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	f1[0][1]=1;
	for (int i=1;i<=n;i++){
		f1[i][1]=(f1[i-1][0]+f1[i-1][1])%mo;
		f2[i][1]=(f2[i-1][0]+f2[i-1][1])%mo;
		if (c[i]=='o'){
			f1[i][0]=(f1[i][0]+f1[i-1][1])%mo;
			f1[i][1]=(f1[i][1]+f1[i-1][0])%mo;
			f2[i][0]=(f2[i][0]+f2[i-1][1])%mo;
			f2[i][1]=(f2[i][1]+f2[i-1][0])%mo;
			f2[i][1]=(f2[i][1]+f1[i-1][0])%mo;
		}
	}
	ans=(1ll*ans+f2[n][0]+f2[n][1])%mo;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			t1[(i-1)*(m+1)+j]=t2[(j-1)*(n+1)+i]=s[j];
	}
	solve(n*(m+1),t1);
	solve(m*(n+1),t2);
	cout<<ans<<endl;
}