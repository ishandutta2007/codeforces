#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n, m; cin >> n >> m;
 
		int x[n], d[n];
		vector<int> ans(n, -1), done(n, 0);
		char inp;
 
		vector<int> parity[2];
 
		for(int i=0; i<n; ++i) cin >> x[i], parity[x[i] & 1].push_back(i);
		for(int &i : d) cin >> inp, i = inp == 'R';
 
		for(vector<int> &v : parity){
			sort(v.begin(), v.end(), [&](int aa, int bb){
				return x[aa] < x[bb];
			});
			set<array<int, 2>> s;
			int sz = v.size();
			for(int i=0; i<sz; ++i) s.insert({x[v[i]], v[i]});
			vector<int> q;
			for(int i=0; i+1<sz; ++i) if(d[v[i]] && !d[v[i+1]]) q.push_back(v[i]);
			while(!q.empty()){
				int i = q.back(); q.pop_back();
				array<int, 2> r = {x[i], i};
				auto f = s.find(r);
				auto g = f;
				++g;
				auto left = f, right = g;
				++right;
				if(left != s.begin() && right != s.end()){
					--left;
					int aa = (*left)[1];
					int bb = (*right)[1];
					if(d[aa] && !d[bb]) q.push_back(aa);
				}

				int j = (*g)[1];

				s.erase(f);
				s.erase(g);

				int diff = x[j] - x[i];
				diff = abs(diff/2LL);
				ans[i] = diff;
				ans[j] = diff;
				done[i] = done[j] = 1;
			}


			// cout nl;
			vector<int> remdi;
			for(auto &i : s) if(!done[i[1]]) remdi.push_back(i[1]);
			sz = remdi.size();
 
			for(int i=0; i+1<sz; i+=2){
				if(d[remdi[i+1]]) break;
				int aaa = remdi[i], bbb = remdi[i+1];
				int diff = abs((x[bbb]-x[aaa])/2LL);
				ans[aaa] = diff + x[aaa];
				ans[bbb] = diff + x[aaa];
				done[aaa] = done[bbb] = 1;
			}
 
			reverse(remdi.begin(), remdi.end());
 
			for(int i=0; i+1<sz; i+=2){
				if(!d[remdi[i+1]]) break;
				int aaa = remdi[i], bbb = remdi[i+1];
				int diff = abs((x[bbb]-x[aaa])/2LL);
				ans[aaa] = diff + min(m-x[aaa], m-x[bbb]);
				ans[bbb] = diff + min(m-x[aaa], m-x[bbb]);
				done[aaa] = done[bbb] = 1;
			}
 
			vector<int> z;
			for(int i : remdi) if(!done[i]) z.push_back(i);
 
			if(z.size() > 1){
				assert(z.size() == 2);
				int diff = abs(x[z[0]]-x[z[1]]) / 2LL;
				ans[z[0]] = m - diff;
				ans[z[1]] = m - diff;
			}
 
		}
		for(int i : ans) cout << i << ' ';
		cout nl;
	}
}