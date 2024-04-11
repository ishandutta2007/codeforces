#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1e5+5;
int N, Q, i, j, arr[MN], x, y;
set<int> st; map<int,int> ans;

inline void del(int val){
	ans[val]--;
	if(!ans[val]) ans.erase(val);
}

inline void ins(int x){
	if(st.empty()){
		st.insert(x);
		return;
	}
	auto it = st.lower_bound(x);
	if(it==st.end()){
		if(it!=st.begin()){
			it--;
			int pre = *it;
			ans[x-pre]++;
		}
	}
	else{
		int val = *it;
		if(it!=st.begin()){
			it--;
			int pre = *it;
			del(val-pre);
			ans[x-pre]++;
			ans[val-x]++;
		}
		else ans[val-x]++;
	}
	st.insert(x);
}

inline void rem(int x){
	if(st.size()==1){
		st.erase(x);
		return;
	}
	st.erase(x);
	auto it=st.lower_bound(x);
	if(it==st.end()){
		if(it!=st.begin()){
			it--;
			int pre = *it;
			del(x-pre);
		}
	}
	else{
		int val = *it;
		if(it!=st.begin()){
			it--;
			int pre = *it;
			ans[val-pre]++;
			del(x-pre);
			del(val-x);
		}
		else del(val-x);
	}
}

inline int range(){
	if(st.empty()) return 0;
	else{
		auto it=st.end(); it--;
		return *it-*st.begin();
	}
}

inline void answer(){
	int mx = 0;
	if(ans.size()){
		auto it=ans.end(); it--;
		mx = it->first;
	}
	printf("%d\n",range()-mx);
}

int main(){
	scanf("%d%d",&N,&Q);
	for(i=1;i<=N;i++){
		scanf("%d",&arr[i]);
		ins(arr[i]);
	}
	answer();
	for(i=1;i<=Q;i++){
		scanf("%d%d",&x,&y);
		if(x==0) rem(y);
		else ins(y);
		answer();
	}
	return 0;
}