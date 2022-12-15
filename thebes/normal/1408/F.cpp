#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 2e4+5;
int N, i, j, x, y;
vector<pii> ans;

void comp(vi vec){
	for(int j=1;j<(int)vec.size();j*=2){
		for(int i=0;i<(int)vec.size();i++){
			if(i<(i^j)){
				ans.push_back({vec[i],vec[i^j]});
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	if((N&-N)==N){
		vi hm;
		for(int i=0;i<N;i++)
			hm.push_back(i+1);
		comp(hm);
	}
	else{
		vi hm;
		int K = 1;
		while(2*K<=N) K*=2;
		for(int i=0;i<K;i++)
			hm.push_back(i+1);
		comp(hm);
		hm.clear();
		for(int i=0;i<K;i++)
			hm.push_back(N-i);
		comp(hm);
	}
	printf("%d\n",(int)ans.size());
	for(auto v : ans)
		printf("%d %d\n",v.F,v.S);
	return 0;
}