#include <cstdio>
#include <list>
using namespace std;

int n;
int k1, k2;
int v1[11], v2[11];

bool checkeq(list<int> &la, list<int> &lb) {
	if(la.size() != lb.size()) return false;
	list<int>::iterator ita, itb;
	for(ita = la.begin(), itb = lb.begin(); ita != la.end(); ++ita, ++itb)
		if(*ita != *itb)
			return false;
	return true;
}

void walk(list<int> &l1, list<int> &l2) {
	int a1 = l1.front(), a2 = l2.front();
	l1.pop_front(); l2.pop_front();
	if(a1 > a2) { l1.push_back(a2); l1.push_back(a1); }
	else { l2.push_back(a1); l2.push_back(a2); }
}

bool ok(list<int> &l1, list<int> &l2) { return !l1.empty() && !l2.empty(); }

int main() {
	int i;
	scanf("%d", &n);
	scanf("%d", &k1);
	list<int> l1, l2;
	for(i = 0; i < k1; i++) {
		scanf("%d", &v1[i]);
		l1.push_back(v1[i]);
	}
	scanf("%d", &k2);
	for(i = 0; i < k2; i++) {
		scanf("%d", &v2[i]);
		l2.push_back(v2[i]);
	}
	list<int> l3(l1), l4(l2);

	int rounds = 0;
	while(ok(l1, l2)) {
		rounds++;
		walk(l1, l2);
		if(ok(l3, l4)) walk(l3, l4);
		if(ok(l3, l4)) walk(l3, l4);
		if(ok(l1, l2) && ok(l3, l4) && checkeq(l1, l3) && checkeq(l2, l4)) {
			puts("-1");
			return 0;
		}
	}
	if(l1.empty()) printf("%d 2\n", rounds);
	else printf("%d 1\n", rounds);
	return 0;
}