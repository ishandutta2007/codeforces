#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define one first
#define two second

const int INF = 0x3f2f1f0f;

typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<string, string> pss;

const int MAX_N = 1e2 + 10;

int N, K, M, A, As[MAX_N];
int Ans[MAX_N];

struct NODE {
	int cnt, last, ix;
	NODE(int c, int l, int i) : cnt(c), last(l), ix(i) {}
	bool operator<(const NODE &o) {
		if(cnt != o.cnt) return cnt > o.cnt;
		return last < o.last;
	}
};
bool isCan(int as[], int ix) {
	vector<NODE> Ns;
	for(int i=0; i<N; i++) Ns.push_back(NODE(0, 0, i));
	for(int i=0; i<M; i++) {
		int x = as[i];
		Ns[x].cnt++;
		Ns[x].last = i;
	}
	sort(ALL(Ns));
	for(int i=0; i<K; i++) if(Ns[i].cnt != 0 && Ns[i].ix == ix) return true;
	return false;
}
int main() {
	cin >> N >> K >> M >> A;
	for(int i=0; i<A; i++) scanf("%d", &As[i]), As[i]--;
	for(int i=0; i<N; i++) {
		for(int k=A; k<M; k++) As[k] = i;
		if(isCan(As, i) == false) Ans[i] = 3;
	}
	vector<NODE> ns;
	for(int i=0; i<N; i++) ns.push_back(NODE(0, 0, i));
	for(int i=0; i<A; i++) {
		int x = As[i];
		ns[x].cnt++;
		ns[x].last = i;
	}
	sort(ALL(ns));
	if(N == K) {
		for(int i=0; i<N; i++) if(Ans[i] == 0) {
			bool found = false;
			for(int j=0; j<A; j++) if(As[j] == i) found = true;
			if(found) Ans[i] = 1; else Ans[i] = 2;
		}
	}else{
		for(int i=0; i<N; i++) if(Ans[i] == 0) {
			vector<NODE> now = ns;

			bool canNot = false;
			for(int k=A; k<M; k++) {
				int ix = -1;
				for(int j=0; j<N; j++) if(now[j].ix == i) ix = j;
				if(ix+1 == N) {canNot = true; break;}
				int x = As[k] = now[ix+1].ix;
				now[ix+1].cnt++;
				now[ix+1].last = k;
				sort(ALL(now));
			}
			if(canNot || !isCan(As, i)) Ans[i] = 2; else Ans[i] = 1;
		}
	}
	for(int i=0; i<N; i++) printf("%d ", Ans[i]); puts("");
	return 0;
}