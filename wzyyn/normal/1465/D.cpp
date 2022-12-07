#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=100005;
char s[N];
int n,x,y,q[N];
int pr[N][2],su[N][2];
ll ans;
void update0(){
	ll sum=0;
	int s0=0,s1=0;
	For(i,1,n)
		if (s[i]=='1')
			sum+=1ll*x*s0,++s1;
		else sum+=1ll*y*s1,++s0;
	ans=min(ans,sum);
	For(i,1,*q){
		int p=q[i];
		sum-=1ll*(pr[p][1]+i-1)*y;//10
		sum-=1ll*(su[p][1])*x;//01
		sum+=1ll*(pr[p][0])*x;//01
		sum+=1ll*(su[p][0]+(*q-i))*y;//10
		ans=min(ans,sum);
	}
}
void update1(){
	ll sum=0;
	int s0=0,s1=0;
	For(i,1,n)
		if (s[i]=='0')
			sum+=1ll*y*s1,++s0;
		else sum+=1ll*x*s0,++s1;
	ans=min(ans,sum);
	For(i,1,*q){
		int p=q[i];
		sum-=1ll*(pr[p][0]+i-1)*x;//01
		sum-=1ll*(su[p][0])*y;//10
		sum+=1ll*(pr[p][1])*y;//10
		sum+=1ll*(su[p][1]+(*q-i))*x;//01
		ans=min(ans,sum);
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d%d",&x,&y);
	For(i,1,n) if (s[i]=='?') q[++*q]=i;
	For(i,1,n){
		pr[i][0]=pr[i-1][0]+(s[i]=='0');
		pr[i][1]=pr[i-1][1]+(s[i]=='1');
	}
	Rep(i,n,1){
		su[i][0]=su[i+1][0]+(s[i]=='0');
		su[i][1]=su[i+1][1]+(s[i]=='1');
	}
	ans=1ll<<60;
	update0();
	update1();
	cout<<ans<<endl;
}