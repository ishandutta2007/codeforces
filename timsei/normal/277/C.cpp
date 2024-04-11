#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 5;
const int M = 1e5 + 5;

int n , m , x , y , a , b , c , d , k , ty , len , no , ans , ts , ls , HH[M] , LL[M];

struct NODE {
    int x , l , r;
};

vector <NODE> H , L;

map <int,int>  Hs , Ls;

vector <pair<int,int> > Ph[M] , Pl[M];

map<int,int> ::iterator it;

#define Sz(x) ((int) x.size())

void init(void) {
    cin >> n >> m >> k;
    for(int i = 1;i <= k;++ i) {
	scanf("%d%d%d%d" , &a , &b ,&c , &d);
	if(a == c) {
	    if(b > d) swap(b , d);
	    H.push_back((NODE){a , b , d});
	}
	else {
	    if(a > c) swap(a , c);
	    L.push_back((NODE){b , a , c});
	}
    }
}

int Dh[M] , Dl[M];

void calc(void) {
    for(int i = 0;i < Sz(H);++ i) {
	int cur = Hs[H[i].x];
	if(!cur) Hs[H[i].x] = ++ ts , cur = ts , Dh[ts] = H[i].x;
	Ph[cur].push_back(make_pair(H[i].l , H[i].r));
    }
    for(int i = 0;i < Sz(L);++ i){
	int cur = Ls[L[i].x];
	if(!cur) Ls[L[i].x] = ++ ls , cur = ls , Dl[ls] = L[i].x;
	Pl[cur].push_back(make_pair(L[i].l , L[i].r));
    }
    for(int i = 1;i <= ts;++ i) {
	sort(Ph[i].begin() , Ph[i].end());
	ans = ans ^ m;
	int len = m;
	for(int j = 0;j < (int)Ph[i].size();++ j) {
	    if(j != Ph[i].size() - 1) {
		if(Ph[i][j].second >= Ph[i][j + 1].second) {
		    Ph[i][j + 1] = Ph[i][j]; continue;
		}
	    }
	    if(j != (int)Ph[i].size() - 1) {
		len = len - min(Ph[i][j + 1].first , Ph[i][j].second) + Ph[i][j].first;
	    }
	    else len = len - Ph[i][j].second + Ph[i][j].first;
	}
	ans = ans ^ len; HH[i] = len;
    }
    for(int i = 1;i <= ls;++ i) {
	sort(Pl[i].begin() , Pl[i].end());
	ans = ans ^ n;
	int len = n;
	for(int j = 0;j < (int)Pl[i].size();++ j) {
	    if(j != Pl[i].size() - 1) {
		if(Pl[i][j].second >= Pl[i][j + 1].second) {
		    Pl[i][j + 1] = Pl[i][j]; continue;
		}
	    }
	    if(j != Pl[i].size() - 1) {
		len = len - min(Pl[i][j + 1].first, Pl[i][j].second) + Pl[i][j].first;
	    }
	    else len = len - Pl[i][j].second + Pl[i][j].first;
	}
	ans = ans ^ len; LL[i] = len;
    }
}

void GOL(int x , int y) {
    int how = LL[x] - y;
    int l = 0 , r = n;
    while(l <= r) {
	int mid = (l + r) >> 1;
	int now = mid;
	for(int i = 0;i < (int)Pl[x].size();++ i) {
	    int l = Pl[x][i].first , r = Pl[x][i].second;
	    r = min(mid , r);
	    if(Pl[x].size() != i + 1) {
		r = min(r , Pl[x][i + 1].first);
	    }
	    if(l > r) continue;
	    now = now - (r - l);
	}
	if(now == how) {
	    cout << 0 <<" "<< Dl[x] << " " << mid << " " << Dl[x] << endl;
	    return;
	}
	if(now < how){
	    l = mid + 1;
	}
	else r = mid - 1;
    }
}

void GOH(int x , int y) {
    int how = HH[x] - y;
    int l = 0 , r = m;
    while(l <= r) {
	int mid = (l + r) >> 1;
	int now = mid;
	for(int i = 0;i < (int)Ph[x].size();++ i) {
	    int l = Ph[x][i].first , r = Ph[x][i].second;
	    r = min(mid , r);
	    if(Ph[x].size() != i + 1) {
		r = min(r , Ph[x][i + 1].first);
	    }
	    if(l > r)continue;
	    now = now - (r - l);
	}
	if(now == how) {
	    cout << Dh[x] << " " << 0  << " " << Dh[x] <<" " << mid << endl;
	    return;
	}
	if(now < how){
	    l = mid + 1;
	}
	else r = mid - 1;
    }
}

void print(int x) {
    int all = 0;
    for(int i = 1;i <= ts; ++ i) {
	all = (x ^ HH[i]);
	if(HH[i] >= all) {
	    GOH(i , all);
	    return;
	}
    }
    for(int i = 1;i <= ls;++ i) {
	all = x ^ LL[i];
	if(LL[i] >= all) {
	    GOL(i , all);
	    return;
	}
    }
    
    if(ts < n) {
	all = x ^ m;
	if(m >= all)
	    for(int i = 1;i < n; ++ i) {
		if(!Hs[i]) {
		    cout << i <<" "<< 0 <<" "<< i <<" "<< m - all << endl;
		    return;
		}
	    }
    }
    if(ls < m) {
	all = x ^ n;
	if(n >= all) {
	    for(int i = 1;i < m;++ i) {
		if(!Ls[i]) {
		    cout << 0 <<" " << i <<" " <<n - all << " " << i << endl;
		    return;
		}
	    }
	}
    }
}

int main(void) {
    init();
    ans = (((n & 1) ^ 1) * m) ^ (((m & 1) ^ 1) * n);
    calc();
    if(ans == 0) {
	puts("SECOND"); return 0;
    }
    else {
	puts("FIRST");
	print(ans);
    }
}