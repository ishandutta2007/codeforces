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
using namespace std;
const int N=300005;
const int B=605;
int n,Q,vis[N];
vector<int> v[N],vec[N];
bool solve(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) v[i].resize(0);
	For(i,1,Q){
		int x;
		scanf("%d",&x);
		vec[i].resize(x);
		for (auto &j:vec[i]) scanf("%d",&j);
		if (x<=B) for (auto j:vec[i]) v[j].PB(i);
	}
	For(i,1,n){
		for (auto j:v[i])
			for (auto k:vec[j])
				vis[k]=0;
		for (auto j:v[i]){
			//cout<<"C "<<i<<' '<<j<<' '<<vis[2]<<endl;
			int flag=0;
			int sz=vec[j].size();
			For(k,0,sz-1)
				if (flag)
					if (!vis[vec[j][k]])
						vis[vec[j][k]]=vec[j][flag];
					else if (vis[vec[j][k]]!=vec[j][flag])
						return 0;
					else;
				else if (vec[j][k]==i) flag=k+1;
		}
	}
	For(i,1,Q) if (vec[i].size()>B){
		For(j,1,n) vis[j]=-1;
		For(j,0,vec[i].size()-1) vis[vec[i][j]]=j;
		For(j,1,Q)
			if (j!=i&&(j>i||vec[j].size()>B)){
				int mx=-1;
				Rep(k,vec[j].size()-1,0)
					if (vis[vec[j][k]]>=0)
						if (vis[vec[j][k]]<mx)
							if (vec[i][vis[vec[j][k]]+1]!=vec[j][k+1])
								return 0;
							else;
						else mx=vis[vec[j][k]];
			}
	}
	return 1;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--)
		puts(solve()?"Robot":"Human");
}