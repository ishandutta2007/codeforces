#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int n = 1024*1024;

ll N, K, M;
ll L[n], R[n], C[n], P[n];
vector<pair<ll, int>> RS, LS;

const ll off = n-1;

ll S[n*2], PS[n*2];

ll left(ll cur){
	return 2*cur+1;
}
ll right(ll cur){
	return 2*cur+2;
}
ll par(ll cur){
	return (cur-1)/2;
}

void update(ll ind, ll add){
	ind += off;
	S[ind] += add;
	PS[ind] = S[ind] * (ind-off);
	do{
		ind = par(ind);
		S[ind] = S[left(ind)] + S[right(ind)];
		PS[ind] = PS[left(ind)] + PS[right(ind)];
	}while(ind != 0);
}

ll query(ll rem, ll cur=0){
	if(rem == 0)
		return 0;
	if(S[cur] <= rem)
		return PS[cur];
	if(cur >= off){
		return rem * (cur-off);
	}
	if(S[left(cur)] <= rem){
		return PS[left(cur)] + query(rem-S[left(cur)], right(cur));
	}
	else{
		return query(rem, left(cur));
	}
}


int main(){
	cin >> N >> K >> M;
	for(int i=0; i<M; i++){
		cin >> L[i] >> R[i] >> C[i] >> P[i];
		RS.push_back(make_pair(R[i], i));
		LS.push_back(make_pair(L[i], i));
	}
	RS.push_back({N+4, -1});
	LS.push_back({N+4, -1});
	sort(RS.begin(), RS.end());
	sort(LS.begin(), LS.end());

	ll res = 0;
	int li = 0, ri = 0;
	for(int t=1; t<=N; t++){
		while(LS[li].first == t){
			int ind = LS[li].second;
			update(P[ind], C[ind]);
			li++;
		}

		res += query(K);
		
		while(RS[ri].first == t){
			int ind = RS[ri].second;
			update(P[ind], -C[ind]);
			ri++;
		}
	}
	cout << res << endl;

	return 0;
}