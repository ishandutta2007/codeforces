#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ll id,x;
	bool operator<(const node c)const{
		if(x==c.x) return id<c.id;
		return x<c.x;
	}
}k[100005];

int n,m;
ll ans;
ll a[100005],c[100005];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),k[i].id=i;
	for(int i=1;i<=n;i++) k[i].x=c[i]=readint();
	sort(k+1,k+n+1);
	int now=1; ll x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); ans=0;
		if(y<=a[x]) a[x]-=y,ans=y*c[x],y=0;
		else ans=a[x]*c[x],y-=a[x],a[x]=0;
//		cout<<"TEST "<<ans<<endl;
		if(y>a[x]){
			while(y&&now<=n){
				if(y<=a[k[now].id]) a[k[now].id]-=y,ans+=y*c[k[now].id],y=0;
				else ans+=a[k[now].id]*c[k[now].id],y-=a[k[now].id],a[k[now].id]=0;
				while(!a[k[now].id]&&now<=n) now++;
			}
		}
		while(!a[k[now].id]&&now<=n) now++;
		if(y) printf("0\n");
		else printf("%lld\n",ans);
	}
	return 0;
}