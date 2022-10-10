#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using cat = long long;

void solve(int H, int G, auto & A, auto & cnt_rem, auto & last, auto & q_id, priority_queue<int, vector<int>, greater<int> > * q, cat & sum, int cur = 0) {
	int l = (cur+1)*2-1, r = (cur+1)*2;
	if(cur >= (1<<G)-1) {
		if(q_id[cur] == -1) q_id[cur] = cur;
		last[cur] = 0;
		q[q_id[cur]].push(A[cur]);
		if(cur >= (1<<(H-1))-1) return;
		q_id[l] = q_id[r] = q_id[cur];
		solve(H, G, A, cnt_rem, last, q_id, q, sum, r);
		solve(H, G, A, cnt_rem, last, q_id, q, sum, l);
		return;
	}
	solve(H, G, A, cnt_rem, last, q_id, q, sum, r);
	solve(H, G, A, cnt_rem, last, q_id, q, sum, l);
	int stop = max(last[l], last[r]); // can't remove <= stop
	priority_queue<int, vector<int>, greater<int> > & q_l = q[q_id[l]];
	priority_queue<int, vector<int>, greater<int> > & q_r = q[q_id[r]];
	while(!q_l.empty() && q_l.top() <= stop) {
		sum -= q_l.top();
		cnt_rem[l]++;
		q_l.pop();
	}
	while(!q_r.empty() && q_r.top() <= stop) {
		sum -= q_r.top();
		cnt_rem[r]++;
		q_r.pop();
	}
	q_id[cur] = (q_l.size() > q_r.size()) ? q_id[l] : q_id[r];
	if(q_id[cur] == q_id[l]) {
		while(!q_r.empty()) {q_l.push(q_r.top()); q_r.pop();}
	}
	else {
		while(!q_l.empty()) {q_r.push(q_l.top()); q_l.pop();}
	}
	q[q_id[cur]].push(A[cur]);
	last[cur] = q[q_id[cur]].top();
	q[q_id[cur]].pop();
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	priority_queue<int, vector<int>, greater<int> > q[1<<20];
	while(T--) {
		int H, G;
		cin >> H >> G;
		int N = (1<<H)-1;
		cat sum = 0;
		vector<int> A(N);
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			sum += A[i];
		}
		vector<int> last(N), cnt_rem(N, 0), q_id(N, -1);
		for(int i = 0; i < N; i++) while(!q[i].empty()) q[i].pop();
		solve(H, G, A, cnt_rem, last, q_id, q, sum);
		cnt_rem[0] = q[q_id[0]].size();
		while(!q[q_id[0]].empty()) {
			sum -= q[q_id[0]].top();
			q[q_id[0]].pop();
		}
		cout << sum << "\n";
		bool st = true;
		for(int i = 0; i < N; i++) for(int j = 0; j < cnt_rem[i]; j++) {
			if(!st) cout << " ";
			st = false;
			cout << i+1;
			// int cur = i;
			// while(true) {
			// 	int l = 2*cur+1, r = 2*cur+2;
			// 	if(cur >= (1<<(H-1))) {A[cur] = 0; break;}
			// 	if(!A[l] && !A[r]) {A[cur] = 0; break;}
			// 	if(A[l] > A[r]) {A[cur] = A[l]; cur = l;}
			// 	else {A[cur] = A[r]; cur = r;}
			// }
		}
		cout << "\n";
		// for(int i = 0; i < (1<<G)-1; i++) if(!A[i]) cout << "FAIL\n";
	}
}