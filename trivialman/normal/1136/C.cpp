#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 505;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,a[N][N],b[N][N],c[N*N*2],v[N*N*2];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&m);
	int cnt = 0;
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]),c[++cnt]=a[i][j];
	rep(i,1,n)rep(j,1,m)scanf("%d",&b[i][j]),c[++cnt]=b[i][j];
	sort(c+1,c+cnt+1);
	//rep(i,1,cnt)cout<<c[i]<<" ";cout<<endl;
	cnt = unique(c+1,c+cnt+1) - c - 1;
	unordered_map<int,int> mp;
	rep(i,1,cnt) mp[c[i]] = i;
	rep(i,1,n)rep(j,1,m)a[i][j]=mp[a[i][j]];
	rep(i,1,n)rep(j,1,m)b[i][j]=mp[b[i][j]];
	
	//rep(i,1,n)rep(j,1,m)printf("%d%c",a[i][j],j==m?'\n':' '); 
	//rep(i,1,n)rep(j,1,m)printf("%d%c",b[i][j],j==m?'\n':' ');
	
	rep(k,2,n+m){
		rep(i,1,k){
			int j = k - i;
			if(i<=n && j<=m && j>=1){
				v[a[i][j]]++;
				v[b[i][j]]--;
			}
		}
		rep(i,1,k){
			int j = k - i;
			if(i<=n && j<=m && j>=1){
				if(v[a[i][j]]!=0 || v[b[i][j]]!=0){
					cout<<"NO\n";
					return 0;
				}
			}
		}
	}
	cout<<"YES\n";
	return 0;
}