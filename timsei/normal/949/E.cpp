#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

int n , a[N] , ans;
vector <int> Vec , who , w;

int gcd(int x , int y) {
	return (y == 0) ? x : gcd(y , x % y);
}

struct A {
	vector <int> now , ans;
	int pre;
};

queue <A> q;

void dfs(vector <int> &now , vector <int> &ans , int pre) {
	int G = abs(now[0]);
	for(int i = 1;i < (int) now.size();++ i) 
	G = gcd(abs(now[i]) , G);
	int K = 0;
	while(G % (1 << (K + 1)) == 0) ++ K;
	G = (1 << K);
	for(int i = 0;i < (int) now.size();++ i) now[i] /= G;
	vector <int> newnow;
	newnow.clear();
	for(int i = 0;i < (int) now.size();++ i) {
		if((now[i] - 1)) {
			if(now[i] & 1) newnow.push_back(now[i] - 1);
			else newnow.push_back(now[i]);
		}
	}
	ans.push_back(G * pre);
	newnow.erase(unique(newnow.begin() , newnow.end()) , newnow.end());
	q.push((A){newnow , ans , pre * G});
	ans.pop_back();
	newnow.clear();
	for(int i = 0;i < (int) now.size();++ i) {
		if((now[i] + 1)) {
			if(now[i] & 1)
			newnow.push_back(now[i] + 1);
			else newnow.push_back(now[i]);
		}
	}
	newnow.erase(unique(newnow.begin() , newnow.end()) , newnow.end());
	ans.push_back(- G * pre);
	q.push((A){newnow , ans , pre * G});
}

main(void) {
	scanf("%d" , &n);
	for(int i = 1;i <= n;++ i) {
		scanf("%d" , &a[i]); if(a[i]) Vec.push_back(a[i]);
	}
	sort(Vec.begin() , Vec.end());
	Vec.erase(unique(Vec.begin() , Vec.end()) , Vec.end());
	q.push ((A){Vec , w , 1});
	int cnt = 0;
	while(!q.empty()) {
		A ind = q.front(); q.pop();
		if(!ind.now.size()) {
			who = ind.ans;
			break;
		}
		dfs(ind.now , ind.ans , ind.pre);
	}
	cout << who.size() << endl;
	for(int i = 0;i < (int) who.size();++ i) {
		cout << who[i] <<" ";
	}
}