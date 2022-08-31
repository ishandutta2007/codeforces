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

int n,m;
int l[200005],r[200005],cnt[600005],tag[600005];
char s[200005],t[200005];

void build(int id,int l,int r){
	tag[id]=-1;
	if(l==r) return (void)(cnt[id]=t[l]=='1');
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	cnt[id]=cnt[id<<1]+cnt[id<<1|1];
}

void addtag(int id,int l,int r,int c){
	tag[id]=c,cnt[id]=c*(r-l+1);
}

void pushdown(int id,int l,int r){
	if(tag[id]>=0){
		int mid=(l+r)/2;
		addtag(id<<1,l,mid,tag[id]);
		addtag(id<<1|1,mid+1,r,tag[id]);
		tag[id]=-1;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr) return addtag(id,l,r,c);
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	cnt[id]=cnt[id<<1]+cnt[id<<1|1];
}

int query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return cnt[id];
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		scanf("%s%s",s+1,t+1);
		int fl=0;
		build(1,1,n);
		for(int i=1;i<=m;i++) l[i]=readint(),r[i]=readint();
		for(int i=m;i>=1;i--){
			int num=query(1,1,n,l[i],r[i]);
			if((r[i]-l[i]+1)%2==0&&num==(r[i]-l[i]+1)/2){
				fl=1;
				break;
			}
			if(num<=(r[i]-l[i]+1)/2) change(1,1,n,l[i],r[i],0);
			else change(1,1,n,l[i],r[i],1);
		}
		for(int i=1;i<=n;i++){
			if(query(1,1,n,i,i)!=s[i]-'0'){
				fl=1;
				break;
			}
		}
		if(fl) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}