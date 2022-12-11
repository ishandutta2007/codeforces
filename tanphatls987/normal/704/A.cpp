#include <bits/stdc++.h>

using namespace std;

#define X first 
#define Y second 
#define FOR(i,L,R) for(auto i=(L);i<=(R);i++)
#define REP(i,L,R) for(auto i=(L);i<(R);i++)

typedef pair<int,int> ii;
typedef long long ll;

const int MOD=1e9+7;
const int N=3e5+10;

int n,n1;
queue <int> q[N];
int h[N];

void prepare(){
	int test;
	scanf("%d%d",&n,&test);

	int ans=0,bar=0;
	while (test--){
		int type,val;
		scanf("%d%d",&type,&val);
		if (type==1) q[val].push(++n1);		
		if (type==2){
			while (!q[val].empty()){
				int x=q[val].front();
				q[val].pop();
				if (!h[x]) ans++;
				h[x]=1;
			}
		}
		if (type==3){
			for(int i=bar+1;i<=val;i++) if (!h[i]){
				h[i]=1;
				ans++;
			}
			bar=max(bar,val);
		}
		printf("%d\n",n1-ans);
	}
}
int main(){
	prepare();
}