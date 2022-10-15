#include<bits/stdc++.h>
using namespace std;

const int maxn=2007;
int n,k;
char s[maxn][maxn];
int l[maxn],r[maxn];
int ans[maxn][maxn];

int C[maxn];

int lowbit(int u){
	return u&(-u);
}
void update(int u,int t){
	for (int i=u;i<=n;i+=lowbit(i)){
		C[i]+=t;
	}
}

int query(int u){
	int ans=0;
	for (int i=u+1;i;i-=lowbit(i)){
		ans+=C[i];
	}
	return ans;
}
void range_update(int l,int r,int t){
	if (l>r) return;
	update(l+1,1);
	update(r+2,-1);
}


void solve(){
	for (int i=0;i<n;++i){
		l[i]=r[i]=-1;
	}
	int rt=0;
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			if (s[i][j]=='B'){
				l[i]=j;
				break;
			}
		}
		for (int j=n-1;j>-1;--j){
			if (s[i][j]=='B'){
				r[i]=j;
				break;
			}
		}
		if (l[i]==-1) rt++;
	}
	for (int i=0;i<n-k+1;++i){
		memset(C,0,sizeof(C));
		for (int j=0;j<k;++j){
			if (l[i+j]!=-1){
				range_update(max(0,l[i+j]-(k-(r[i+j]-l[i+j]+1))),l[i+j],1);
			}
		}
		for (int j=0;j<n-k+1;++j){
			ans[i][j]+=query(j)+rt;
//			cout<<ans[i][j]<<" ";
		}
//		cout<<endl;
	}
}

int main(){
	memset(ans,0,sizeof(ans));
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;++i){
		cin>>s[i];
	}
	solve();
	for (int i=0;i<n;++i){
		for (int j=0;j<i;++j){
			swap(s[i][j],s[j][i]);
			swap(ans[i][j],ans[j][i]);
		}
	}
	solve();
	int ret=0;
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			ret=max(ret,ans[i][j]);
		}
	}
	cout<<ret<<endl;
	return 0;
}