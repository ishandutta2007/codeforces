#include<bits/stdc++.h>
using namespace std;

const int N=200005;

int n,Q;
int w[N],v[N];
int id[N],pos[N];
long long a[N];
bool cmp(int x,int y){
	if (v[x]!=v[y])
		return v[x]>v[y];
	return w[x]<w[y];
}

struct Tarr{
	long long t[N];
	void change(int x,long long v){
		for (;x<=n+2;x+=x&(-x)) t[x]+=v;
	}
	long long ask(int x){
		long long s=0;
		for (;x;x-=x&(-x)) s+=t[x];
		return s;
	}
	int find(long long x){
		int p=0,v=1<<17;
		for (;v;v>>=1)
			if (p+v<=n+2&&x>=t[p+v])
				x-=t[p+v],p+=v;
		return p+1;
	}
}T1[19],T2[19];
struct SEG{
	long long tg[N*4];
	long long mn[N*4];
	void add(int k,long long v){
		tg[k]+=v;
		mn[k]+=v;
	}
	void pushdown(int k){
		if (!tg[k]) return;
		add(k*2,tg[k]);
		add(k*2+1,tg[k]);
		tg[k]=0;
	}
	void change(int k,int l,int r,int x,int y,long long v){
		if (x<=l&&r<=y){
			tg[k]+=v; mn[k]+=v;
			return;
		}
		pushdown(k);
		int mid=(l+r)/2;
		if (x<=mid) change(k*2,l,mid,x,y,v);
		if (y>mid) change(k*2+1,mid+1,r,x,y,v);
		mn[k]=min(mn[k*2],mn[k*2+1]);
	}
	long long ask(int k,int l,int r,int x,int y){
		if (l==x&&r==y) return mn[k];
		pushdown(k);
		int mid=(l+r)/2;
		if (y<=mid) return ask(k*2,l,mid,x,y);
		if (x>mid) return ask(k*2+1,mid+1,r,x,y);
		return min(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
	}
	int find(int k,int l,int r,int p,long long c){
		if (mn[k]>c) return -1;
		if (l==r) return l;
		pushdown(k);
		int mid=(l+r)/2;
		if (p<=mid){
			int ans=find(k*2,l,mid,p,c);
			if (ans!=-1) return ans;
		}
		return find(k*2+1,mid+1,r,p,c);
	}
	int find(int p,long long c,int low){
		//assert(c<=low);
		long long v;
		if (p==1) v=0;
		else{
			v=ask(1,1,n,p-1,p-1);
			if (w[id[p-1]]<=low/2) v-=1ll<<60;
			else if (w[id[p-1]]<=low){
				if (a[id[p-1]]) v-=w[id[p-1]];
				else v-=1ll<<60;
			}
			else v-=1ll<<60;
		}
		//cout<<p<<' '<<c<<' '<<v<<endl;
		return find(1,1,n,p,c+v);
	}
}T3[19];
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++)
		scanf("%lld%d%d",&a[i],&w[i],&v[i]);
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (int i=1;i<=n;i++)
		pos[id[i]]=i;
	for (int j=0;j<=17;j++)
		T1[j].change(n+1,1ll<<60);
	for (int i=1;i<=n;i++)
		for (int j=0;j<=17;j++)
			if (w[i]<=(1<<j)){
				T1[j].change(pos[i],1ll*a[i]*w[i]);
				T2[j].change(pos[i],1ll*a[i]*v[i]);
				if (w[i]<=((1<<j)>>1)){
					T3[j].change(1,1,n,pos[i],n,1ll*a[i]*w[i]);
					T3[j].change(1,1,n,pos[i],pos[i],1ll<<60);
				}
				else{
					if (a[i])
						T3[j].change(1,1,n,pos[i],pos[i],1ll*w[i]);
					else
						T3[j].change(1,1,n,pos[i],pos[i],1ll<<60);
				}
			}
			else	
				T3[j].change(1,1,n,pos[i],pos[i],1ll<<60);
	while (Q--){
		int tp;
		scanf("%d",&tp);
		if (tp<=2){
			int p,x;
			scanf("%d%d",&x,&p);
			if (tp==2) x*=-1;
			a[p]+=x;
			for (int j=0;j<=17;j++)
				if (w[p]<=(1<<j)){
					T1[j].change(pos[p],1ll*x*w[p]);
					T2[j].change(pos[p],1ll*x*v[p]);
					if (w[p]<=((1<<j)>>1))
						T3[j].change(1,1,n,pos[p],n,1ll*x*w[p]);
					else{
						if (!(a[p]-x)&&a[p])
							T3[j].change(1,1,n,pos[p],pos[p],w[p]-(1ll<<60));
						if ((a[p]-x)&&!a[p])
							T3[j].change(1,1,n,pos[p],pos[p],(1ll<<60)-w[p]);
					}
				}
		}
		else{
			long long c,ans=0;
			scanf("%lld",&c);
			int p=1;
			for (int i=17;i>=0;i--){
				long long low=(1<<i);
				if (c>=low){
					int np=T1[i].find(T1[i].ask(p-1)+(c-low));
					ans+=T2[i].ask(np-1)-T2[i].ask(p-1);
					c-=T1[i].ask(np-1)-T1[i].ask(p-1);
					p=np;
					if (p>n) break;
					long long val=min(a[id[p]],c/w[id[p]]);
					c-=val*w[id[p]];
					ans+=val*v[id[p]];
					++p;
					if (p>n) break;
				}
				assert(c<low);
				
				//cout<<p<<' '<<c<<' '<<low<<' '<<a[id[p]]<<' '<<ans<<endl;
				if (c>=low/2){
					int np=T3[i].find(p,c,low);
					if (np==-1)	continue;
					ans+=T2[i-1].ask(np-1)-T2[i-1].ask(p-1);
					c-=T1[i-1].ask(np-1)-T1[i-1].ask(p-1);
					//cout<<np<<' '<<p<<' '<<ans<<endl;
					p=np;
					if (p>n) break;
					
					long long val=min(a[id[p]],c/w[id[p]]);
					c-=val*w[id[p]];
					ans+=val*v[id[p]];
					++p;
					if (p>n) break;
				}
			}
			printf("%lld\n",ans);
		}
	}
}