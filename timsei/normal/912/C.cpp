#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

#define int long long

const int N = 1e5 + 5;
const int M = 1e5 + 5;

struct Upd {
	int time , HP;
	friend bool operator < (Upd xxx , Upd yyy) {
		return xxx.time < yyy.time;
	}
};

vector <Upd> U[N];

int T[N] , n , m , x , y , B , I , D , mh[N] , sh[N] , r[N] , res;

map<int , int> Map;

main(void) {
	scanf("%I64d%I64d" , &n, &m);
	scanf("%I64d%I64d%I64d" , &B, &I , &D);
	for(int i = 1;i <= n;++ i) {
		scanf("%I64d%I64d%I64d" , &mh[i] , &sh[i] , &r[i]);
		if(mh[i] <= D) {
			if(I) {
				puts("-1"); return 0;
			}
			else ++ res;
		}
	}
	int a , b , c;
	for(int i = 1;i <= m;++ i) {
		scanf("%I64d%I64d%I64d" , &a, &b , &c);
		U[b].push_back((Upd){a , c});
	}
	for(int i = 1;i <= n;++ i) U[i].push_back((Upd){0 , sh[i]}) , sort(U[i].begin() , U[i].end());
	for(int i = 1;i <= n;++ i) {
		if(mh[i] <= D) continue;
		int S = U[i].size();
		for(int j = 0;j < S;++ j) {
			Upd cur = U[i][j];
			int H = cur.HP , A = r[i];
			if(H > D) continue;
			int L , R;
			L = cur.time; 
			if(A) R = cur.time + (D - H) / A; else R = 1e11;
			if(j < S - 1) R = min(R , U[i][j + 1].time - 1);
			else {
				if(U[i][j].HP <= D && !r[i] && I) {
					puts("-1"); return 0;
				}
			}
			int l = L , r = R;
			if(l > r) continue;
			++ Map[l]; -- Map[r + 1]; Map[r] += 0; Map[l - 1] += 0;
		}
	}
	
	int cur = res;
	
	long long ans = 0;
	
	Map[0] += 0;
	
	for(map<int,int>::iterator it = Map.begin(); it != Map.end();++ it) {
		cur += it -> second;
		ans = max(ans , cur * 1ll * B + I * 1ll * (it -> first) * 1ll * cur);
	}
	cout << ans << endl;
}