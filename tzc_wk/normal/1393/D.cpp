#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),m=read();
char s[2005][2005];
int l_u[2005][2005],l_d[2005][2005];
int r_u[2005][2005],r_d[2005][2005];
int u_l[2005][2005],u_r[2005][2005];
int d_l[2005][2005],d_r[2005][2005];
signed main(){
	fz(i,1,n) cin>>s[i]+1;
	fz(i,1,n) fz(j,1,m) l_u[i][j]=l_d[i][j]=((s[i][j]==s[i][j-1])?l_u[i][j-1]:j);
	fz(i,1,n) fd(j,m,1) r_u[i][j]=r_d[i][j]=((s[i][j]==s[i][j+1])?r_u[i][j+1]:j);
	fz(j,1,m) fz(i,1,n) u_l[i][j]=u_r[i][j]=((s[i][j]==s[i-1][j])?u_l[i-1][j]:i);
	fz(j,1,m) fd(i,n,1) d_l[i][j]=d_r[i][j]=((s[i][j]==s[i+1][j])?d_l[i+1][j]:i);
	fz(i,1,n) fz(j,1,m) if(s[i][j]==s[i-1][j]) l_u[i][j]=max(l_u[i][j],l_u[i-1][j]-1);
	fd(i,n,1) fz(j,1,m) if(s[i][j]==s[i+1][j]) l_d[i][j]=max(l_d[i][j],l_d[i+1][j]-1);
	fz(i,1,n) fz(j,1,m) if(s[i][j]==s[i-1][j]) r_u[i][j]=min(r_u[i][j],r_u[i-1][j]+1);
	fd(i,n,1) fz(j,1,m) if(s[i][j]==s[i+1][j]) r_d[i][j]=min(r_d[i][j],r_d[i+1][j]+1);
	fz(j,1,m) fz(i,1,n) if(s[i][j]==s[i][j-1]) u_l[i][j]=max(u_l[i][j],u_l[i][j-1]-1);
	fd(j,m,1) fz(i,1,n) if(s[i][j]==s[i][j+1]) u_r[i][j]=max(u_r[i][j],u_r[i][j+1]-1);
	fz(j,1,m) fz(i,1,n) if(s[i][j]==s[i][j-1]) d_l[i][j]=min(d_l[i][j],d_l[i][j-1]+1);
	fd(j,m,1) fz(i,1,n) if(s[i][j]==s[i][j+1]) d_r[i][j]=min(d_r[i][j],d_r[i][j+1]+1);
	long long ans=0;
	fz(i,1,n) fz(j,1,m){
		int val=0x3f3f3f3f;
		val=min(val,j-l_u[i][j]+1);
		val=min(val,j-l_d[i][j]+1);
		val=min(val,r_u[i][j]-j+1);
		val=min(val,r_d[i][j]-j+1);
		val=min(val,i-u_l[i][j]+1);
		val=min(val,i-u_r[i][j]+1);
		val=min(val,d_l[i][j]-i+1);
		val=min(val,d_r[i][j]-i+1);
		ans+=val;
	}
	cout<<ans<<endl;
	return 0;
}