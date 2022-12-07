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
const int N=100005;
const int mo=1000000007;
char s1[N],s2[N];
struct node{
	int S0,S1,S2;
	int l,r;
}f[N],ans;
int P[N];
node merge(node x,node y){
	node ans;
	ans.S0=(x.S0+y.S0+1)%mo;
	ans.S1=(x.S1+y.S1+1ll*x.r+y.l)%mo;
	ans.S2=(x.S2+y.S2+1ll*x.r*y.l)%mo;
	ans.l=x.l; ans.r=y.r;
	return ans;
}
node add(node x,int v){
	node ans;
	ans.S0=x.S0;
	ans.S1=(x.S1+2ll*x.S0*v)%mo;
	ans.S2=(x.S2+1ll*x.S0*v%mo*v+1ll*x.S1*v)%mo;
	ans.l=(x.l+v)%mo;
	ans.r=(x.r+v)%mo;
	return ans;
}
node query(int k,int x,int y,int v,int fl){
	//cout<<k<<' '<<x<<' '<<y<<' '<<v<<' '<<fl<<endl;
	if ((!x&&!y)||!k) return add(f[k],v);
	node tmp;
	int vis=0;
	if (!fl&&(!x||s1[k]<=0)&&(!y||s2[k]>=0)){
		node ttmp=query(k-1,x&(s1[k]==0),y&(s2[k]==0),v,0);
		vis?tmp=merge(tmp,ttmp):(vis=1,tmp=ttmp);
	}
	if ((!x||s1[k]<=4)&&(!y||s2[k]>=4)){
		node ttmp=query(k-1,x&(s1[k]==4),y&(s2[k]==4),(v+4ll*P[k-1])%mo,1);
		vis?tmp=merge(tmp,ttmp):(vis=1,tmp=ttmp);
	}
	if ((!x||s1[k]<=7)&&(!y||s2[k]>=7)){
		node ttmp=query(k-1,x&(s1[k]==7),y&(s2[k]==7),(v+7ll*P[k-1])%mo,1);
		vis?tmp=merge(tmp,ttmp):(vis=1,tmp=ttmp);
	}
	assert(vis);
	return tmp;
}
int main(){
	scanf("%s%s",s1+1,s2+1);
	int l1=strlen(s1+1);
	int l2=strlen(s2+1);
	reverse(s1+1,s1+l1+1);
	reverse(s2+1,s2+l2+1);
	For(i,1,l1) s1[i]-='0';
	For(i,1,l2) s2[i]-='0';
	P[0]=1;
	For(i,1,l2) P[i]=10ll*P[i-1]%mo;
	f[0]=(node){0,0,0,0,0};
	For(i,1,l2){
		int v4=4ll*P[i-1]%mo;
		int v7=7ll*P[i-1]%mo;
		f[i]=merge(add(f[i-1],v4),add(f[i-1],v7));
	}
	ans=query(l2,1,1,0,0);
	//cout<<ans.S0<<' '<<ans.S1<<' '<<ans.l<<' '<<ans.r<<endl;
	printf("%d ",ans.S2);
}