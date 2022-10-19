#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

char s[N];
int a , b ,nxt[N];
vector <int> A , B;
vector <int> now , f;
set <int> S , Sa , Sb;

bool vis[N];

main(void) {
	scanf("%s" , s + 1);
	int n = strlen(s + 1);
	for(int i = 1;i <= n;++ i) if(s[i] == '1') A.push_back(i); else B.push_back(i);
	if(A.size() >= B.size()) {
		puts("-1"); return 0;
	}
	int na = 0;
	for(int i = 1;i <= n;++ i) {
		if(s[i] == '1') -- na;
		if(s[i] == '0') ++ na;
		if(na < 0) return 0 * puts("-1");
	}
	int lst = n + 1;
	for(int i = n;i >= 1;-- i) {
		if(s[i] == '0') now.push_back(i);
		else {
			if(!now.size()) {
				puts("-1"); return 0;
			}
			vis[now.back()] = 1;
			nxt[i] = now.back(); now.pop_back();
		}
	}
	cout << B.size() - A.size() << endl;
	for(int i = 1;i <= n;++ i) {
		S.insert(i);
		if(s[i] == '1') Sa.insert(i);
		else if(!vis[i]) Sb.insert(i);
	}
	set <int> ::iterator it;
	for(int i = 1;i <= B.size() - A.size();++ i) {
		int num = 0;
		f.clear();
		int l = *Sb.begin();
		Sb.erase(l); f.push_back(l);
		if(!Sa.size()) {
			cout << f.size() << " ";
			for(int i = 0;i < (int) f.size(); ++ i) cout << f[i] <<" ";
			puts("");
			continue;
		}
		else {
			while(Sa.upper_bound(l) != Sa.end()) {
				it = Sa.upper_bound(l);
				f.push_back(l = *it);Sa.erase(it);
				f.push_back(nxt[l]); l = nxt[l];
			}
				cout << f.size() << " ";
				for(int i = 0;i < (int) f.size(); ++ i) cout << f[i] <<" ";
				puts("");
				continue;
		}
	}
}