#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1e4+5;
int T, N, i, j, arr[MN], x, y; ll sm;
struct idk{int x, y, w;};
vector<idk> ans;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		ans.clear(); sm = 0;
		for(i=1;i<=N;i++){
			scanf("%d",&arr[i]);
			sm += arr[i];
		}
		if(sm%N!=0) printf("-1\n");
		else{
			int res = sm/N;
			for(i=2;i<=N;i++){
				int rem = i-(arr[i]%i);
				if(rem!=i) ans.pb({1,i,rem}), arr[i] += rem;
				ans.pb({i,1,(int)arr[i]/i});
			}
			for(i=2;i<=N;i++){
				ans.pb({1,i,res});
			}
			printf("%d\n",(int)ans.size());
			for(auto v : ans)
				printf("%d %d %d\n",v.x,v.y,v.w);
		}
	}
	return 0;
}