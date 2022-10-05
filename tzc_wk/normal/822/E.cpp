#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
const int B=127;
int n,m,x;
string s,t;
int f[100005][32],s1[100005],s2[100005],c[100005];
bool check(int l1,int r1,int l2,int r2){
	return ((s1[r1]-s1[l1-1]*c[r1-l1+1])%MOD+MOD)%MOD==((s2[r2]-s2[l2-1]*c[r2-l2+1])%MOD+MOD)%MOD;
}
int get(int x,int y){
	int l=x,r=min(n,m+x-y);
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(x,mid,y,mid-x+y))	l=mid+1;
		else						r=mid-1;
    }
    return r;
}
signed main(){
	cin>>n>>s>>m>>t>>x;
	s=" "+s;t=" "+t;
	c[0]=1;
	for(int i=1;i<=n;c[i]=c[i-1]*B%MOD,i++)
		s1[i]=(s1[i-1]*B+s[i]-'a'+1)%MOD;
    for(int i=1;i<=m;i++)
		s2[i]=(s2[i-1]*B+t[i]-'a'+1)%MOD;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=x;j++){
			f[i+1][j]=max(f[i][j],f[i+1][j]);
			if(j!=x){
				int p1=get(i+1,f[i][j]+1);
				if(p1>i)	f[p1][j+1]=max(f[p1][j+1],p1-i+f[i][j]);
			}
		}
	}
	for(int i=1;i<=x;i++)
		if(f[n][i]==m)
			return puts("YES"),0;
	puts("NO");
}