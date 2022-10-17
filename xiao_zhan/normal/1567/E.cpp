#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define md ((l+r)>>1)
#define ls (cur<<1)
#define rs ((cur<<1)+1)
#define len (r-l+1)
#define chk() if(l!=r&&sum[cur]){sum[ls]=(sum[ls]+sum[cur]);s[ls]=(s[ls]+sum[cur]*(md-l+1));sum[rs]=(sum[rs]+sum[cur]);s[rs]=(s[rs]+sum[cur]*(r-md));sum[cur]=0;}

ll s[2000500],sum[2000500];

void add(int l,int r,int nl,int nr,int cur,ll ad){
	if(l==nl&&r==nr){sum[cur]=(sum[cur]+ad);s[cur]=(s[cur]+ad*len);chk();return;}
	chk();
	if(nr<=md){add(l,md,nl,nr,ls,ad);}
	else{
		if(nl>md){add(md+1,r,nl,nr,rs,ad);}
		else{add(l,md,nl,md,ls,ad);add(md+1,r,md+1,nr,rs,ad);}
	}
	s[cur]=(s[ls]+s[rs]);
}

ll ask(int l,int r,int nl,int nr,int cur){
	chk();
	if(l==nl&&r==nr){return s[cur];}
	if(nr<=md){return ask(l,md,nl,nr,ls);}
	if(nl>md){return ask(md+1,r,nl,nr,rs);}
	return ask(l,md,nl,md,ls)+ask(md+1,r,md+1,nr,rs);
}

int i,j,k,l,r,n,m,t,a[200500],sb,tmp;
set<int> st;
int main(){
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	st.insert(n+1);
	st.insert(1);
	st.insert(0);
	for(i=1;i<=n;i++){
		if(a[i]>=a[i-1]){
			k++;
		}
		else{
			k=1;st.insert(i);
		}
		add(1,n,i,i,1,k);
	}
	//puts("a");for(i=1;i<=n;i++){printf("%d ",ask(1,n,i,i,1));}puts("");
	while(t--){
		scanf("%d",&sb);
		if(sb==1){
			scanf("%d%d",&j,&k);
			auto it=st.upper_bound(j);
			r=*it-1;
			it--;l=*it;
			
			a[j]=k;
			if(j==1){goto aaa;}
			if(a[j-1]<=a[j]){
				if(l==j){
					tmp=ask(1,n,j-1,j-1,1);
					add(1,n,j,r,1,tmp);
					st.erase(l);
				}
			}
			else{
				if(l!=j){
					tmp=ask(1,n,j-1,j-1,1);
					add(1,n,j,r,1,-tmp);
					st.insert(j);
				}
			}
			aaa:;
			//puts("a");for(i=1;i<=n;i++){printf("%d ",ask(1,n,i,i,1));}puts("");
			if(j==n){goto bbb;}
			it=st.upper_bound(j);
			r=*it-1;
			it--;l=*it;
			//printf("a%d %d %d\n",j,l,r);
			if(a[j]<=a[j+1]){
				if(r==j){
					tmp=ask(1,n,j,j,1);
					//printf("nmsl%d %d\n",j+1,*st.upper_bound(j+1)-1);
					add(1,n,j+1,*st.upper_bound(j+1)-1,1,tmp);
					st.erase(j+1);
				}
			}
			else{
				if(r!=j){
					tmp=ask(1,n,j,j,1);
					add(1,n,j+1,r,1,-tmp);
					st.insert(j+1);
				}
			}
			
			bbb:;
			//puts("b");for(i=1;i<=n;i++){printf("%d ",ask(1,n,i,i,1));}puts("");
		}
		else{
			scanf("%d%d",&j,&k);
			auto it=st.upper_bound(k);
			it--;
			if(*it<=j){
				ll sb=k-j+1;
				printf("%lld\n",sb*(sb+1)/2);continue;
			}
			r=*it;
			it=st.lower_bound(j);
			l=*it;
			ll ans=ask(1,n,j,k,1);
			
			//printf("a%d %d %d %d\n",j,l,r,k);
			
			if(l>j){
				ans-=ask(1,n,j,l-1,1);
				ll sb=l-j;
				ans+=(sb*sb+sb)/2;
			}
			printf("%lld\n",ans);
		}
	}
}