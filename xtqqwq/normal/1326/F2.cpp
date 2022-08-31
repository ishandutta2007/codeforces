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

int n,cnt;
ll tmp[300000],ans[300000],a[20][300000],d[300000][20],b[20],A[20];
char s[20][20];

void dfs(int now,int k){
	if(k==0){
//		for(int i=1;i<=cnt;i++) cout<<b[i]<<' ';
//		cout<<endl;
		for(int i=0;i<(1<<n);i++) tmp[i]=1;
		for(int i=1;i<=cnt;i++) for(int j=0;j<(1<<n);j++) tmp[j]=tmp[j]*a[b[i]][j];
		for(int i=0;i<n;i++) for(int j=0;j<(1<<n);j++) if(j&(1<<i)) tmp[j]-=tmp[j^(1<<i)];
		reverse(b+1,b+cnt+1);
//		cout<<"ans "<<tmp[(1<<n)-1]<<endl;
		do{
			int now=0;
			for(int i=1;i<=cnt;i++) now=(now<<b[i])+(1<<(b[i]-1))-1;
//			cout<<"test "<<now<<endl;
			ans[now]+=tmp[(1<<n)-1];
		}while(next_permutation(b+1,b+cnt+1));
		reverse(b+1,b+cnt+1);
		return;
	}
	if(now==0) return;
	int g=k/now;
	for(int i=0;i<=g;i++){
		dfs(min(now-1,k),k);
		if(k<now) break;
		k-=now;
		b[++cnt]=now;
	}
	cnt-=g;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) d[1<<(i-1)][i]=1;
	for(int i=1;i<(1<<n)-1;i++){
		for(int j=1;j<=n;j++){
			if(!((i>>(j-1))&1)) continue;
			for(int k=1;k<=n;k++){
				if((i>>(k-1))&1) continue;
				if(s[j][k]=='1') d[i|(1<<(k-1))][k]+=d[i][j];
			}
		}
	}
	for(int i=1;i<(1<<n);i++){
		int num=0;
		for(int j=1;j<=n;j++) num+=(i>>(j-1))&1;
		for(int j=1;j<=n;j++){
			if(!((i>>(j-1))&1)) continue;
			a[num][i]+=d[i][j];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<(1<<n);k++)
				if(k&(1<<j)) a[i][k]+=a[i][k^(1<<j)];
	dfs(n,n);
	for(int i=0;i<n-1;i++)
		for(int j=0;j<(1<<(n-1));j++)
			if(j&(1<<i)) ans[j^(1<<i)]-=ans[j];
	for(int i=0;i<(1<<(n-1));i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}