#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 2005;
int N, M, i, j, x, y, lo, hi, mx[MN], cur[MN], ans=1<<30;
pii a[MN], b[MN]; map<int,int> mp;
vector<pii> evt[MN*MN];

int main(){
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++){
		scanf("%d%d",&x,&y);
		a[i]={x,y};
	}
	for(i=1;i<=M;i++){
		scanf("%d%d",&x,&y);
		x++, y++;
		b[i]={x,y};
	}
	sort(b+1,b+M+1,[](pii i,pii j){return i.F<j.F;});
	for(i=M;i>=1;i--){
		mx[i] = max(mx[i+1], b[i].S);
	}
	b[M+1].F = 2e6;
	for(i=1;i<=N;i++){
		for(j=0;j<=M;j++){
            if(max(0,b[j].F-a[i].F)!=max(0,b[j+1].F-a[i].F)){
                int dh = max(0,b[j].F-a[i].F);
                int dx = max(0,mx[j+1]-a[i].S);
                evt[dh].push_back({i,dx});
            }
		}
	}
	memset(cur,-1,sizeof(cur));
	int hm = 0;
	for(i=0;i<1000005;i++){
		for(auto v : evt[i]){
			if(cur[v.F]!=-1){
				mp[cur[v.F]]--;
				if(!mp[cur[v.F]]) mp.erase(cur[v.F]);
			}
			else hm++;
			cur[v.F] = v.S;
			mp[cur[v.F]]++;
		}
		if(mp.size()&&hm==N){
            auto it=mp.end(); it--;
            ans = min(ans, i+it->F);
		}
	}
	printf("%d\n",ans);
	return 0;
}