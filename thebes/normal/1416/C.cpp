#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 3e5+5, LG = 31;
int N, i, j, arr[MN], t[MN*LG][2], sz[MN*LG], nxt, p, ord[MN];
ll tot, ans, sw[LG];

int main(){
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&arr[i]);
		p = 0;
        for(int k=LG-1;k>=0;k--){
            int cur = (arr[i]>>k)&1;
            if(!t[p][cur]) t[p][cur]=++nxt;
            if(!cur&&t[p][!cur]!=0){
                tot += sz[t[p][!cur]];
                sw[k] += sz[t[p][!cur]];
            }
            if(cur&&t[p][!cur]!=0){
                sw[k] -= sz[t[p][!cur]];
            }
            p = t[p][cur];
            sz[p]++;
        }
	}
	for(j=0;j<LG;j++){
		if(sw[j]>0){
			ans |= (1<<j);
			tot -= sw[j];
		}
	}
	printf("%lld %lld\n",tot,ans);
	return 0;
}