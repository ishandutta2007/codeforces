// author: xay5421
// created: Mon Oct 25 14:28:23 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
typedef long long LL;
const int N=300005;
vector<pair<int,int> >qq[N];
int a[N],st[N][20],lg[N],stl[N],str[N],val[N],id[N];
LL ans[N],s[N];
int n,q,k,top,tot;
int qry(int l,int r){
	int g=lg[r-l+1];
	return min(st[l][g],st[r-(1<<g)+1][g]);
}
void ins(int l,int r){
	int minn=qry(l,r);++tot;
	while(top&&val[top]>=minn)--top;
	++top;val[top]=minn;stl[top]=l;str[top]=r;id[top]=tot;
	s[top]=s[top-1]+1LL*minn*(id[top]-id[top-1]);
}
int main(){
	rd(n);rd(q);rd(k);
	rep(i,1,n)rd(a[i]),st[i][0]=a[i];
	lg[0]=-1;
	rep(i,1,n)lg[i]=lg[i>>1]+1;
	rep(j,1,19)rep(i,1,n-(1<<j)+1)st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	rep(i,1,q){
		int l,r;
		rd(l);rd(r);
		if(r-l+1<=k)ans[i]=a[l];
		else qq[l].emplace_back(r,i);
	}
	rep(_,1,k){
		top=tot=0;
		int l=n-_+1,r=n;
		while(l>1){
			ins(l,r);

			int res=top+1;
			int tl=l;
			{
				int l=1,r=top;
				while(l<=r){
					int mid=(l+r)>>1;
					if(a[tl-1]<=val[mid])res=mid,r=mid-1;
					else l=mid+1;
				}
			}
			--res;
			for(auto i:qq[l-1]){
				// fprintf(stderr,"l=%d,val[2]=%d,res=%d\n",l,val[2],res);
				int r=i.first;
				int idr=(n-r+1+(k-_-1))/k+1;
				int pos=res+1;
				{
					int l=1,r=res;
					while(l<=r){
						int mid=(l+r)>>1;
						if(id[mid]>=idr)pos=mid,r=mid-1;
						else l=mid+1;
					}
				}
				if(pos==res+1){
					ans[i.second]=1LL*a[l-1]*((r-(l-1)+1+k-1)/k);
					continue;
				}
				ans[i.second]=1LL*a[l-1]*(tot+1-id[res])+s[res]-s[pos]+1LL*val[pos]*(id[pos]-idr+1);
				if((r-(l-1)+1)%k!=1&&k!=1)ans[i.second]-=val[pos];
			}

			r=l-1;l=r-k+1;
		}
	}
	rep(i,1,q)printf("%lld\n",ans[i]);
	return 0;
}