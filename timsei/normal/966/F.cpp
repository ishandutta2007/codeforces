%:pragma GCC optimize(2)
%:pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fdevirtualize-speculatively")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-fisolate-erroneous-paths-dereference")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx") 
#include <bits/stdc++.h>
using namespace std;

const int N = 1111;
const int M = N * 15;

#define double long double
#define eps (1e-9)

int n , m , x , y , a[M] , b[M] , c[M] , d[M] , cnt = 0 , u[M] , v[M];

namespace Flow {
	int fir[N] , ne[M] , to[M] , cnt = 1 , s , t , cur[N];
	double C[M];
	
	inline void add(int x , int y , double z) {
		ne[++ cnt] = fir[x];
		fir[x] = cnt;
		to[cnt] = y;
		C[cnt] = z;
	}
	inline void link(int x , int y , double z) {
		add(x , y , z);
		add(y , x , 0);
	}
	
	#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])
	#define Forcurbegin(i , x) for(int &i = cur[x];i;i = ne[i])
	
	int dis[N];
	
	void init(void) {
		memset(fir , 0 , sizeof(fir));
		cnt = 1;
		s = 0 , t = n + 1;
	}
	
	bool BFS(int s , int t) {
		queue <int> q;
		while(!q.empty())
		q.pop();
		q.push(s);
		for(int i = s;i <= t;++ i) {
			dis[i] = 2e9;
			cur[i] = fir[i];
		}
		dis[s] = 0;
		while(!q.empty()) {
			int ind = q.front();
			q.pop();
			Foreachson(i , ind) 
			if(C[i] > eps){
				int V = to[i];
				if(dis[V] == 2e9) {
					dis[V] = dis[ind] + 1;
					q.push(V);
				}
			}
		}
		return dis[t] != 2e9;
	}
	
	double dfs(int x , double fl , int t) {
		if(x == t) 
		return fl;
		double res = 0;
		Forcurbegin(i , x) {
			int V = to[i];
			if(dis[V] != dis[x] + 1 || !C[i])
			continue;
			double now = dfs(V , min(fl , C[i]) , t);
			res += now;
			fl -= now;
			C[i] -= now;
			C[i ^ 1] += now;
			if(fl < eps) {
				return res;
			}
		}
		dis[x] = -1;
		return res;
	}
	
	double maxflow(int s , int t) {
		double ans = 0 , fl;
		while(BFS(s , t)) {
			while((fl = dfs(s , 2e9 , t)) >= eps) ans += fl;
		}
		return ans;
	}
}

double check(double t) {
	Flow::init();
	double res = 0;
	for(int i = 1;i <= cnt;++ i) {
		double l = a[i] * t + b[i] ,
		r = c[i] * t + d[i];
		res -= l;
		Flow::link(0 , v[i] , l);
		Flow::link(u[i] , n + 1 , l);
		Flow::link(u[i] , v[i] , r - l);
	}
	res += Flow::maxflow(0 , n + 1);
	return res;
}

main(void) {
	scanf("%d%d" , &n , &m);
	for(int i = 1;i <= m;++ i) {
		int A , B , C , D , U , V;
		scanf("%d%d%d%d%d%d" , &U , &V , &A , &B , &C , &D);
		++ cnt;
		a[cnt] = A;
		b[cnt] = B;
		c[cnt] = C;
		d[cnt] = D;
		u[cnt] = U;
		v[cnt] = V;
	}
	double l = 0 , r = 1 ,ans = 0;
	for(int i = 0;i < 30;++ i) {
		double len = (r - l) / 3;
		double a = check(l + len) , b = check(l + 2 * len);
		if(a > -eps) {
			l = l + len;
			break;
		}
		if(b > -eps) {
			l = l + 2 * len;
			break;
		}
		if(a > b) {
			r = l + 2 * len;
		}
		else l = l + len;
	}
	if(check(l) <= -eps) {
		puts("0");
		return 0;
	}
	double L = 0 , R = l;
	for(int i = 0;i < 30;++ i) {
		double mid = (L + R) * 0.5;
		if(check(mid) > -eps) {
			R = mid;
		}
		else L = mid;
	}
	ans -= L;
	L = l , R = 1;
	for(int i = 0;i < 30;++ i) {
		double mid = (L + R) * 0.5;
		if(check(mid) > -eps) {
			L = mid;
		}
		else R = mid;
	}
	ans += L;
	printf("%.12Lf\n" , ans);
}