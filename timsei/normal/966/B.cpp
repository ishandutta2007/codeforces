#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

#define int long long

struct NODE {
	int x , id;
	friend bool operator < (NODE a , NODE b) {
		return a.x < b.x;
	}
}Q[N];

int n , m , x , y , x1 , x2;

int now[N];

vector <int> A , B;

void print(void) {
	puts("Yes");
	cout << A.size() <<" " << B.size() << endl;
	sort(A.begin() , A.end());
	sort(B.begin() , B.end());
	for(int i = 0;i < (int) A.size();++ i) cout << A[i] <<" ";
	puts("");
	for(int i = 0;i < (int) B.size();++ i) cout << B[i] <<" ";
	puts("");
}

main(void) {
	scanf("%lld%lld%lld" , &n , &x1 , &x2);
	for(int i = 1;i <= n;++ i) {
		scanf("%lld" , &Q[i].x);
		Q[i].id = i;
	}
	sort(Q + 1 , Q + n + 1);
	now[0] = 1e18;
	for(int i = 1;i <= n;++ i) {
		now[i] = min(now[i - 1] , (x2 - 1) / Q[i].x + 1 + i);
	}
	int it = n;
	for(int i = 1;i <= n;++ i) {
		int Min = (x1 - 1) / Q[i].x + 1;
		for(int j = it;j >= i + Min;-- j) {
			if(Q[j].x * (n - j + 1) >= x2) {
				for(int k = j;k <= n;++ k)
				B.push_back(Q[k].id);
				for(int k = i;k <= i + Min - 1;++ k)
				A.push_back(Q[k].id);
				print();
				return 0;
			}
		}
		it = min(i + Min - 1 , n);
		if(i + Min - 1 <= n) {
			if((n - i - Min + 1) + i - now[i - 1] >= 0) {
				for(int k = i;k <= i + Min - 1;++ k)
				A.push_back(Q[k].id);
				for(int k = 1;k < i;++ k) {
					if((n - i - Min + 1) + i - (x2 - 1) / Q[k].x - 1 - k >= 0) {
						for(int p = k;p < i;++ p) B.push_back(Q[p].id);
						for(int p = i + Min;p <= n;++ p) B.push_back(Q[p].id);
						print();
						return 0;
					}
				}		
			}
		}
	}
	puts("No");
}