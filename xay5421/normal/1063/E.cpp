#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1005;
int n,a[N],a_[N];
bool vis[N];
char s[N][N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	bool same=1;
	rep(i,1,n)scanf("%d",&a[i]),same&=a[i]==i,a_[i]=a[i];
	if(same){
		printf("%d\n",n);
		rep(i,1,n){
			rep(j,1,n){
				putchar('.');
			}
			putchar('\n');
		}
		return 0;
	}
	rep(i,1,n){
		a[a_[i]]=i;
	}
	printf("%d\n",n-1);
	int cur=n;
	rep(i,1,n){
		rep(j,1,n)s[i][j]='.';
	}
	per(i,n,1)if(!vis[i]){
		int x=i;
		vector<int>cyc;
		while(!vis[x]){
			vis[x]=1;
			x=a[x];
			cyc.pb(x);
		}
		if(SZ(cyc)<=1)continue;
		rotate(cyc.begin(),max_element(cyc.begin(),cyc.end()),cyc.end());
		if(cyc[0]==n){
			rotate(cyc.begin(),cyc.begin()+1,cyc.end());
			rep(j,0,SZ(cyc)-2){
				s[cur][cyc[j]]=s[cur][a[cyc[j]]]=a[cyc[j]]<cyc[j]?'/':'\\';
				--cur;
			}
		}else{
			s[cur][cyc[0]]='/';
			s[cur][cyc[1]]='/';
			s[cur][n]='/',--cur;
			rep(j,1,SZ(cyc)-1){
				if(j==SZ(cyc)-1){
					s[cur][cyc[j]]='\\';
					s[cur][n]='\\';
					--cur;
				}else{
					s[cur][cyc[j]]=s[cur][a[cyc[j]]]=a[cyc[j]]<cyc[j]?'/':'\\';
					--cur;
				}
			}
		}
	}
	rep(i,1,n){
		rep(j,1,n)putchar(s[i][j]);
		putchar('\n');
	}
	return 0;
}