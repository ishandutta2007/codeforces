#include <bits/stdc++.h>
using namespace std;

string nline() {
	static char buf[1<<4];
	scanf("%s", buf);
	return string(buf);
}
void solve();
string gen[950];
int main() {
	int test_case=1;
	//scanf("%d", &test_case);
	
	for(int i=0;i<26;i++) {
		gen[i]+=char('A'+i);
	}
	int current=26;
	for(int i=0;i<26;i++) {
		for(int j=0;j<26;j++) {
			gen[current]+=char('A'+i);
			gen[current]+=char('a'+j);
			current++;
		}
	}
	while(test_case--) {
		solve();
	}
}

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<string> track;
	for(int i=0;i<n-k+1;i++) {
		track.push_back(nline());
	}
	int current=0;
	deque<string> cur;
	for(int i=0;i<k-1;i++) {
		cur.push_back(gen[current]);
		printf("%s ", gen[current++].c_str());
	}
	
	for(int i=0;i<n-k+1;i++) {
		if(track[i]=="YES") {
			printf("%s ", gen[current].c_str());
			cur.pop_front();
			cur.push_back(gen[current++]);
		} else {
			printf("%s ", cur.front().c_str());
			cur.push_back(cur.front());
			cur.pop_front();
		}
	}
	printf("\n");
	
}