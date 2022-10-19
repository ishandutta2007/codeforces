%:pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct NODE {
	int a , t , id;
	friend bool operator < (NODE xxx , NODE yyy) {
		return xxx.a < yyy.a;
	}
	void input(int x) {
		scanf("%d%d" , &a , &t); id = x;
	}
}ca[N];

int n , T;

vector <NODE> AA , BB;

bool cmp(NODE xxx , NODE yyy) {
	return xxx.t < yyy.t;
}

int res , where , it;

void printans(int k) {
AA.clear();
	for(int i = 1;i <= n;++ i) if(k <= ca[i].a) {
		AA.push_back(ca[i]); 
	}
	else BB.push_back(ca[i]);
	sort(AA.begin() , AA.end() , cmp); sort(BB.begin() , BB.end() , cmp);
	for(int i = 0;i < k;++ i) printf("%d " , AA[i].id);
}

bool pd(int x) {
  AA.clear();
  for(int i = 1;i <= n;++ i) if(x <= ca[i].a) AA.push_back(ca[i]);
  sort(AA.begin() , AA.end() , cmp);
  int all = 0;
  if((int)AA.size() <(int) x) return 0;
  for(int i = 0;i < x;++ i) all += AA[i].t;
  AA.clear();
  return all <= T;
}

int main(void) {
	scanf("%d%d" , &n , &T);
	for(int i = 1;i <= n;++ i) ca[i].input(i);
	sort(ca + 1 , ca + n + 1);
        int ans = -1 , l = 0 , r = n;
        while(l <= r) {
  int mid = (l + r) >> 1;
  if(pd(mid)) {
  ans = mid , l = mid + 1;
  }
   else r = mid - 1;
        }
        cout << ans <<endl << ans << endl;
	printans(ans);
}