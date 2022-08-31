#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1019260817;
int n,q;
int cnt[200005],nxt[200005],lst[200005];
ll pw[200005],t[200005];
char s[200005];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	n=readint();
	scanf("%s",s+1);
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*31%cys;
	for(int i=1;i<=n;i++) cnt[i]=cnt[i-1]+(s[i]=='1');
	s[n+1]='0';
	for(int i=1;i<=n;i++){
		if(s[i]=='0') continue;
		int num=0;
		for(int j=i;j<=n+1;j++){
			if(s[j]=='0'){
				num=j-i;
				break;
			}
		}
		if(num&1) t[i]+=pw[i-cnt[i-1]];
		for(int j=i;j<i+num;j++) nxt[j]=i+num-1,lst[j]=i;
		i+=num-1;
	}
	for(int i=1;i<=n;i++) t[i]=(t[i]+t[i-1])%cys;
	q=readint();
	int x,y,z;
	while(q--){
		x=readint(); y=readint(); z=readint();
		if(cnt[x+z-1]-cnt[x-1]!=cnt[y+z-1]-cnt[y-1]){
			printf("No\n");
			continue;
		}
		if(cnt[x+z-1]-cnt[x-1]==z){
			printf("Yes\n");
			continue;
		}
		ll tmpx=mod(t[x+z-1]-t[x-1]+cys);
		if(s[x]=='1'&&s[x-1]=='1'&&(nxt[x]-x+1)%2==1) tmpx=mod(tmpx+pw[x-cnt[x-1]]);
		if(s[x+z-1]=='1'&&s[x+z]=='1'){
			if((x+z-1-lst[x+z-1]+1)%2!=(nxt[x+z-1]-lst[x+z-1]+1)%2){
				if((x+z-1-lst[x+z-1]+1)%2==0) tmpx=mod(tmpx+cys-pw[lst[x+z-1]-cnt[lst[x+z-1]-1]]);
				else tmpx=mod(tmpx+pw[lst[x+z-1]-cnt[lst[x+z-1]-1]]);
			}
		}
		ll tmpy=mod(t[y+z-1]-t[y-1]+cys);
		if(s[y]=='1'&&s[y-1]=='1'&&(nxt[y]-y+1)%2==1) tmpy=mod(tmpy+pw[y-cnt[y-1]]);
		if(s[y+z-1]=='1'&&s[y+z]=='1'){
			if((y+z-1-lst[y+z-1]+1)%2!=(nxt[y+z-1]-lst[y+z-1]+1)%2){
				if((y+z-1-lst[y+z-1]+1)%2==0) tmpy=mod(tmpy+cys-pw[lst[y+z-1]-cnt[lst[y+z-1]-1]]);
				else tmpy=mod(tmpy+pw[lst[y+z-1]-cnt[lst[y+z-1]-1]]);
			}
		}
		if(pw[y-cnt[y-1]]*tmpx%cys!=pw[x-cnt[x-1]]*tmpy%cys) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}