#include<cstdio>
#include<algorithm>
#define ll long long
#define N 30005
#define C 5

inline ll bnm(int x,int y){
	if(x<0||y<0||x<y)
		return y==0;
	ll res=1;
	for(int i=1;i<=y;i++)
		res=res*(x-i+1);
	for(int i=1;i<=y;i++)
		res=res/i;
	return res;
}
inline ll cal(int n,int c){
	ll res=0;
	for(int i=0;i<=c;i++)
		res+=bnm(n-1,i);
	return res;
}

int T;

int n,c,m,a[N];

struct node{
	int l,r;
	ll w;
	node(int l_=0,int r_=0,ll w_=0){
		l=l_,r=r_,w=w_;
	}
};

node q[C][N*C<<1];
int L[C],R[C];
inline bool cmp(node x,node y){
	return a[x.r]<a[y.r];
}

int cnt[C][N];
ll sum[C][N*C<<1];
inline node sch(int s,int i,ll x){
	int j=L[s]+cnt[s][i-1]-1,l=j+1,r=R[s],res=r+1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(sum[s][mid]-sum[s][j]>=x){
			res=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return node(q[s][res].l,q[s][res].r,sum[s][res-1]-sum[s][j]);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&c,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int s=1;s<=c;s++){
			L[s]=N*C,R[s]=N*C-1;
			for(int i=1;i<=n;i++)
				cnt[s][i]=sum[s][i]=0;
			q[s][++R[s]]=node(n,n,1);
			for(int i=n;i;i--){
				int l=L[s],r=R[s];
				for(int j=1;j<=c&&i+j<=n;j++){
					ll w=cal(n-i-j,s-j);
					if(a[i+j]<a[i]){
						q[s][--L[s]]=node(i,i+j,w);
						cnt[s][i]++;
					}
					else
						q[s][++R[s]]=node(i,i+j,w);
				}
				std::sort(q[s]+L[s],q[s]+l,cmp);
				std::sort(q[s]+r+1,q[s]+R[s]+1,cmp);
			}
			for(int i=1;i<=n;i++)
				cnt[s][i]+=cnt[s][i-1];
			for(int i=L[s];i<=R[s];i++)
				sum[s][i]=sum[s][i-1]+q[s][i].w;
		}
		ll tmp=cal(n,c);
		while(m--){
			int pos;
			ll x;
			scanf("%d%lld",&pos,&x);
			if(x>tmp){
				puts("-1");
				continue;
			}
			int p=1,s=c,ans=a[pos];
			while(s&&p<=n){
				node t=sch(s,p,x);
				if(t.l<=pos&&pos<=t.r)
					ans=a[t.l+t.r-pos];
				x-=t.w;
				s-=t.r-t.l;
				p=t.r+1;
			}
			printf("%d\n",ans);
		}
	}
}