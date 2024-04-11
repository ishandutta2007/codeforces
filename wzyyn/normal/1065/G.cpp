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
const ll INF=(1ll<<60);
const int N=205;
int n,m,_len;
int nxt[N];
ll k;
ll ADD(ll x,ll y){
	return min(INF,x+y);
}
struct node{
	char pref[N];
	char suff[N];
	ll len;
	ll sum;
}t[N*4],eddd;
char s[N*4];
char ans[N];
node operator +(node a,node b){ 
	node ans;
	ans.len=ADD(a.len,b.len);
	ans.sum=ADD(a.sum,b.sum);
	int l1=min(a.len,2ll*_len);
	int l2=min(b.len,2ll*_len);
	For(i,1,min(l1,_len)) s[i]=a.pref[i];
	For(i,1,min(l1,_len)) s[l1-i+1]=a.suff[i];
	For(i,1,min(l2,_len)) s[l1+i]=b.pref[i];
	For(i,1,min(l2,_len)) s[l1+l2-i+1]=b.suff[i];
	int p=0;
	s[l1+l2+1]=0;
	//printf("%d %d %s\n",l1,l2,s+1);
	For(i,l1-min(l1,_len-1)+1,l1+1+min(l2,_len-1)-1){
		for (;p&&s[i]!=::ans[p+1];p=nxt[p]);
		if (s[i]==::ans[p+1]) ++p;
		if (p==_len) ++ans.sum,p=nxt[p];//cout<<"FIND "<<endl;
	}
	For(i,1,min(_len,l1+l2)) ans.pref[i]=s[i];
	For(i,1,min(_len,l1+l2)) ans.suff[i]=s[l1+l2-i+1];
	return ans;
}
/*
0
1
01
101
01101
10101101
*/
ll count(int l){
	_len=l;
	nxt[1]=0;
	For(i,2,l){
		int j=nxt[i-1];
		for (;j&&ans[j+1]!=ans[i];j=nxt[j]);
		nxt[i]=j+(ans[j+1]==ans[i]);
	}
	t[0].pref[1]=t[0].suff[1]='0';
	t[1].pref[1]=t[1].suff[1]='1';
	eddd.pref[1]=eddd.suff[1]='2';
	t[0].len=t[1].len=eddd.len=1;
	t[0].sum=(l==1&&ans[1]=='0');
	t[1].sum=(l==1&&ans[1]=='1');
	eddd.sum=(l==1&&ans[1]=='2');
	For(i,2,n){
		t[i]=t[i-2]+t[i-1];
		//cout<<t[i].sum<<endl;
	}
	return (t[n]+eddd).sum;
}
int main(){
	scanf("%d%lld%d",&n,&k,&m);
	k++;
	For(i,1,m){
		ans[i]='2';
		ll val=count(i);
		//printf("%d %d %lld\n",i,2,val);
		if (val>=k) break;
		k-=val;
		ans[i]='0';
		val=count(i);
		//printf("%d %d %lld\n",i,0,val);
		if (val>=k){
			putchar('0');
			//puts("");
			continue;
		}
		k-=val;
		ans[i]='1';
		val=count(i);
		//printf("%d %d %lld\n",i,1,val);
		if (val>=k){
			putchar('1');
			//puts("");
			continue;
		}
		assert(0);
	}
}
//