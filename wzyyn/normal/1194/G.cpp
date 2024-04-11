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
#define y1 hfjskghsdjkfg
using namespace std;
const int mo=998244353;
int len,ans;
int vis1[15],vis2[15];
char n[105];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
struct state{
	int jw1,jw2;
	int les1,les2;
	int sta1,sta2;
	state(){
		jw1=jw2=les1=les2=sta1=sta2=0;
	}
	bool operator <(const state &a)const{
		if (jw1!=a.jw1) return jw1<a.jw1;
		if (jw2!=a.jw2) return jw2<a.jw2;
		if (les1!=a.les1) return les1<a.les1;
		if (les2!=a.les2) return les2<a.les2;
		if (sta1!=a.sta1) return sta1<a.sta1;
		if (sta2!=a.sta2) return sta2<a.sta2;
		return 0;
	}
	bool operator ==(const state &a)const{
		return jw1==a.jw1&&jw2==a.jw2&&
			   les1==a.les1&&les2==a.les2&&
			   sta1==a.sta1&&sta2==a.sta2;
	}
	bool operator !=(const state &a)const{
		return !(jw1==a.jw1&&jw2==a.jw2&&
			   les1==a.les1&&les2==a.les2&&
			   sta1==a.sta1&&sta2==a.sta2);
	}
};
state work(state las,int v1,int v2,int vnow,int bit){
	state now=las;
	now.jw1=now.jw1+v1*vnow;
	now.jw2=now.jw2+v2*vnow;
	v1=now.jw1%10; now.jw1/=10;
	v2=now.jw2%10; now.jw2/=10;
	if (v1!=n[bit]) now.les1=(v1<n[bit]?0:1);
	if (v2!=n[bit]) now.les2=(v2<n[bit]?0:1);
	if (now.sta1!=-1){
		if (vis1[v1]!=-1) now.sta1|=1<<vis1[v1];
		if (vis2[v2]!=-1) now.sta2|=1<<vis2[v2];
		if (now.sta1&now.sta2) now.sta1=now.sta2=-1;
	}
	return now;
}
map<state,int> mp[105];
void solve(int v1,int v2,int val){
	For(i,0,9){
		vis1[i]=-1;
		vis2[i]=-1;
	}
	int nd=0;
	For(i,1,9/v2){
		vis1[i*v1]=nd;
		vis2[i*v2]=nd;
		nd++;
	}
	For(i,0,len+2) mp[i].clear();
	state tmp; mp[0][tmp]=1;
	For(i,1,len+2)
		for (auto j:mp[i-1]){
			state tmp=j.fi;
			int val=j.se;
			For(nowv,0,9){
				state now=work(tmp,v1,v2,nowv,i);
				mp[i][now]=(mp[i][now]+val)%mo;
			}
		}
	int ans=0;
	for (auto i:mp[len+2]){
		//printf("%d %d %d %d %d %d %d\n",i.fi.jw1,i.fi.jw2,i.fi.les1,i.fi.les2,i.fi.sta1,i.fi.sta2,i.se);
		if (i.fi.sta1==-1&&i.fi.les1==0&&i.fi.les2==0&&i.fi.jw1==0&&i.fi.jw2==0)
			ans=(ans+i.se)%mo;
	}
	//printf("%d %d %d\n",v1,v2,ans);
	::ans=(::ans+1ll*val*ans)%mo;
}
int main(){
	scanf("%s",n+1);
	len=strlen(n+1);
	reverse(n+1,n+len+1);
	For(i,1,len) n[i]-='0';
	For(i,1,9) For(j,i,9)
		if (gcd(i,j)==1) solve(i,j,(i==j?1:2));
	printf("%d\n",ans);
}