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
#define all(v) v.begin(),v.end()
using namespace std;
int n,m,f,l,fa[1<<18];
int fl[55][55];
pii fr1[55][55];
pii fr2[55][55];
void construct(int l,int len,int v){
	fa[l]=v;
	For(i,2,len)
		fa[l+i-1]=l+(i/2)-1;
}
void solve0(){
	n++;
	if (n!=(n&(-n)))
		puts("NO");
	else{
		puts("YES");
		construct(1,n-1,0);
		For(i,1,n-1) printf("%d ",fa[i]);
	}
	exit(0);
}
void solve1(int n,int flag=1){
	++n;
	if (n==(n&(-n)))
		puts("NO");
	else{
		int tmp=--n;
		for (;;){
			int m=1;
			for (;m*2<n;m<<=1);
			//cout<<m<<' '<<n<<endl;
			if (3*m/2-1==n){
				fa[++l]=f; f=l; n--;
				construct(l+1,m/2-1,f); l+=m/2-1; n-=m/2-1;
				construct(l+1,m-1,f); l+=m-1; n-=m-1;
				break;
			}
			else if (n<3*m/2-1){
				fa[++l]=f; f=l; n--;
				construct(l+1,m/2-1,f); l+=m/2-1; n-=m/2-1;
				assert(2*(m/2-1)>=n);
			}
			else{
				fa[++l]=f; f=l; n--;
				construct(l+1,m-1,f); l+=m-1; n-=m-1;
				assert(2*n>=m-1);
			}
		}
		if (flag){
			puts("YES");
			For(i,1,tmp) printf("%d ",fa[i]);
		}
	}
	//exit(0);
}
void dfs(int n,int k){
	fa[++l]=f;
	int tmp=f=l;
	if (n!=1) dfs(fr1[n][k].fi,fr1[n][k].se);
	f=tmp;
	if (n!=1) dfs(fr2[n][k].fi,fr2[n][k].se);
}
void solve2(){
	l=0; f=0;
	int tmp=n;
	for (;n>20&&m>2;){
		fa[++l]=f; f=l;
		fa[++l]=f;
		n-=2; m--;
	}
	if (n<=20){
		if (!fl[n][m]){
			puts("NO");
			exit(0);
		}
		else dfs(n,m);
	}
	else{
		//cout<<n<<' '<<m<<endl;
		For(i,1,n-1){
			int v1=i,v2=n-1-i;
			if (v1%2==1&&v2%2==1&&2*min(v1,v2)>max(v1,v2))
				if ((v1+1)!=((v1+1)&(-v1-1)))
					if ((v2+1)!=((v2+1)&(-v2-1))){
						fa[++l]=f;
						int p=f=l;
						//cout<<v1<<' '<<v2<<endl;
						solve1(v1,0);
						f=p;
						solve1(v2,0);
						//cout<<n<<endl;
						break;
					}
		}
	}
	puts("YES");
	For(i,1,tmp) printf("%d ",fa[i]);
}
int main(){
	scanf("%d%d",&n,&m);
	if (n%2==0||m>max(0,(n-3)/2))
		return puts("NO"),0;
	if (m==0) solve0();
	else if (m==1) solve1(n);
	else{
		fl[1][0]=1;
		For(i,1,20) For(j,0,10) if (fl[i][j])
			For(k,1,20) For(l,0,10) if (fl[k][l]){
				int ni=i+k+1,nj=j+l+(max(i,k)>2*min(i,k));
				fl[ni][nj]=1;
				fr1[ni][nj]=pii(i,j);
				fr2[ni][nj]=pii(k,l);
			}
		solve2();
	}
}