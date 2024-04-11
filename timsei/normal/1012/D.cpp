#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

char s[N], t[N];

struct NODE {
	int L, c;
};

vector <NODE> A, B;

int n, m;

struct Opt {
	int l, r;
};

vector <Opt> ans;

void Swap(int a, int b) {
  vector <NODE> C, D, E, F;
  C.clear(); D.clear(); E.clear(); F.clear();
  int la = 0, lb = 0;
  for(int i = 0; i < a; ++ i) la += A[i].L, C.push_back(A[i]);
  for(int i = 0; i < b; ++ i) lb += B[i].L, D.push_back(B[i]);
  ans.push_back((Opt){la, lb});
  for(int i = a; i < (int) A.size(); ++ i) E.push_back(A[i]);
  for(int i = b; i < (int) B.size(); ++ i) F.push_back(B[i]);
  A.clear(); B.clear();
  if(E.size() && D.size()) {
    D[D.size() - 1].L += E[0].L;
  }
  if(F.size() && C.size()) {
    C[C.size() - 1].L += F[0].L;
  }
  for(int i = 1 - (!(D.size())); i < (int) E.size(); ++ i) D.push_back(E[i]);
  for(int i = 1 - (!(C.size())); i < (int) F.size(); ++ i) C.push_back(F[i]);
  A = D, B = C;
}

int calc(pair <int, int> cxt) {
  if(cxt.first > A.size() || cxt.second > B.size()) return 2e9;
  int La = 0, Lb = 0;
  La = A.size() - cxt.first + cxt.second, Lb = B.size() - cxt.second + cxt.first;
  if(cxt.second && (A.size() - cxt.first)) -- La;
  if(cxt.first && (B.size() - cxt.second)) -- Lb;
  return abs(La - Lb);
}

main(void) {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int last = 0;
	for(int i = 1; i <= n; ++ i) {
		if(s[i] != s[i + 1]) {
			A.push_back((NODE){i - last, s[i] - 'a'});
			last = i;
		}
	}
	last = 0;
	scanf("%s", t + 1);
	m = strlen(t + 1);
	for(int i = 1; i <= m; ++ i) {
		if(t[i] != t[i + 1]) {
			B.push_back((NODE){i - last, t[i] - 'a'});
			last = i;
		}
	}
	if(A.size() == 1 && B.size() == 1) {
		puts("0");
		return 0;
	}
	if(A[0].c == B[0].c) {
	  pair <int, int> now = make_pair(0, 0);
	  for(int i = 1; i <= 4e5; i += 2) {
	    if(calc(make_pair(i + 1, 1)) < calc(now)) now = make_pair(i + 1, 1);
	    if(calc(make_pair(1, i + 1)) < calc(now)) now = make_pair(1, i + 1);
	    if(calc(make_pair(0, i)) < calc(now)) now = make_pair(0, i);
	    if(calc(make_pair(i, 0)) < calc(now)) now = make_pair(i, 0);
	  }
	  if(now.first == 0 && now.second == 0) {
	  }
	  else {
	    Swap(now.first, now.second);
	  }
	}
	else {
	  pair <int, int> now = make_pair(0, 0);
	  for(int i = 0; i <= 4e5; i += 2) {
	    if(calc(make_pair(i + 1, 1)) < calc(now)) now = make_pair(i + 1, 1);
	    if(calc(make_pair(1, i + 1)) < calc(now)) now = make_pair(1, i + 1);
	    if(calc(make_pair(0, i)) < calc(now)) now = make_pair(0, i);
	    if(calc(make_pair(i, 0)) < calc(now)) now = make_pair(i, 0);
	  }
	  if(!now.first || !now.second) {
	    if(calc(now) == 0) ++ now.first, ++ now.second;
	  }
	  if(now == make_pair(0, 0)) {
	  }
	  else {
	    Swap(now.first, now.second);
	  }
	}
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	while(A.size() != 1 || B.size() != 1) {
		int La = A.size() - 1, Lb = B.size() - 1;
		if(A.size() == 1) {
			if(B.back().c == A.back().c) {
				ans.push_back((Opt){0, B.back().L});
				A[La].L += B[Lb].L;
				B.pop_back();
				continue;
			}
			else {
				ans.push_back((Opt){A.back().L, B.back().L});
				NODE C = A.back(), D = B.back();
				A.pop_back(); B.pop_back();
				A.push_back(D);
				B[B.size() - 1].L += C.L;
				continue; 
			}
			continue;
		}
		else if(B.size() == 1) {
			if(A.back().c == B.back().c) {
				ans.push_back((Opt){A.back().L, 0});
				B[Lb].L += A[La].L;
				A.pop_back();
				continue;
			}
			else {
				ans.push_back((Opt){A.back().L, B.back().L});
				NODE C = A.back(), D = B.back();
				A.pop_back(); B.pop_back();
				B.push_back(C);
				A[A.size() - 1].L += D.L;
				continue;
			}
			continue;
		}
		if(A.back().c == B.back().c) {
		  if(A.size() < B.size()) {
				NODE C = A.back(), D = B.back(), E = B[B.size() - 2];
				ans.push_back((Opt){C.L, D.L + E.L});
				A.pop_back();
				B.pop_back();
				B.pop_back();
				A[A.size() - 1].L += E.L;
				A.push_back(D);
				if(B.size()) B[B.size() - 1].L += C.L;
				else B.push_back(C);
			}
			else {
				NODE C = A.back(), D = A[A.size() - 2], E = B.back();
				ans.push_back((Opt){C.L + D.L, E.L});
				A.pop_back(); A.pop_back(); B.pop_back();
				B[B.size() - 1].L += D.L;
				B.push_back(C);
				if(A.size()) A[A.size() - 1].L += E.L;
				else A.push_back(E);
			}
		}
		else {
			NODE C = A.back(), D = B.back();
			ans.push_back((Opt){A.back().L, B.back().L});
			A.pop_back(); B.pop_back();
			A[A.size() - 1].L += D.L;
			B[B.size() - 1].L += C.L;
			continue;
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < (int) ans.size(); ++ i) {
		printf("%d %d\n", ans[i].l, ans[i].r);
	}
}