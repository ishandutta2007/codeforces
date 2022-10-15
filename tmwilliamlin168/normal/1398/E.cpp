#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int k=0;
	set<int> s1, s2;
	s1.insert(0);
	ll t1=0, t2=0;
	set<int> l;
	auto moveup=[&]() {
		int x=*--s1.end();
		s1.erase(x);
		s2.insert(x);
		t1-=x;
		t2+=x;
	};
	auto movedown=[&]() {
		int x=*s2.begin();
		s2.erase(x);
		s1.insert(x);
		t2-=x;
		t1+=x;
	};
	while(n--) {
		int tp, d;
		cin >> tp >> d;
		if(tp) {
			if(d>0) {
				++k;
				moveup();
				l.insert(d);
			} else {
				--k;
				movedown();
				l.erase(-d);
			}
		}
		if(d>0) {
			if(s2.size()&&*s2.begin()<d) {
				s2.insert(d);
				t2+=d;
				movedown();
			} else {
				s1.insert(d);
				t1+=d;
			}
		} else {
			if(s2.find(-d)==s2.end()) {
				s1.erase(-d);
				t1-=-d;
			} else {
				s2.erase(-d);
				t2-=-d;
				moveup();
			}
		}
		int x=*l.begin();
		bool b=0;
		if(s2.find(x)!=s2.end()) {
			b=1;
			s2.erase(x);
			t2-=x;
			t1+=x;
			moveup();
		}
		cout << t1+t2*2 << "\n";
		if(b) {
			movedown();
			s2.insert(x);
			t2+=x;
			t1-=x;
		}
	}
}