#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const long double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 4e5 + 5;

// OOP - based convex hull.
// Uses Graham algorithm.
// Complexity - O(n log n), where n - number of points in convex hull.
// Use: fill pts.n 9number of points), pts.pt (array of points).
// Call pts.build_convex_hull()
// Answer will be in array pts.pt_conv, number of points in convex hull - in n_conv.

template<typename T> struct point {
	T x, y;
	
	point() { }
	
	point(T _x, T _y) {
		x = _x, y = _y;
	}
	
	bool operator == (const point<T> &b) {
		return (this->x == b.x) && (this->y == b.y);
	}
	
	// First by y, then by x
	bool operator < (const point<T> &b) {
		return (this->y != b.y) ? (this->y < b.y) : (this->x < b.x);
	}
	
	static T cross (const point<T> &o, const point<T> &a, const point<T> &b) {
		return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
	}
	
	static T dis2 (const point<T> &a, const point<T> &b) {
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}
};

template<typename T> struct point_sorter {
	// Special point for sorting by angle
	static point<T> pt0;

	// Comparator for sorting by angle 
	static bool cmp_by_angle(const point<T> &a, const point<T> &b) {
		T tmp = point<T>::cross(pt0, a, b);
		if (tmp){
			return tmp > (T)0;
		}
		return point<T>::dis2(pt0, a) < point<T>::dis2(pt0, b);
	}
};

// ATTENTION! 
// This is C++ feature - static variables are defined separately,
// while non-static are defined when declared.
template<typename T> point<T> point_sorter<T>::pt0;

template<typename T> struct point_set {
	// Points count
	int n;
	
	// Initial array of points
	point<T> pt[MAXN];
	
	// Arrays of points for convex hull
	point<T> pt1[MAXN], pt2[MAXN];
	
	// Number of points in convex hull
	int n_conv;
	
	// Array of points for convex hull
	point<T> pt_conv[MAXN];
	
	
	
	// Get index of minimal point 
	int get_minimal_point_index() {
		int min_index = 0;
		for (int i = 1; i < n; i++) {
			if (pt[i] < pt[min_index]) {
				min_index = i;
			}
		}
		return min_index;
	}
	
	// Sort by coordinates (first by y, then by x)
	void sort_by_coordinates() {
		sort(pt, pt + n);
	}
	
	// Sort by angle
	void sort_by_angle() {
		int min_index = get_minimal_point_index();
		swap(pt[0], pt[min_index]);
		point_sorter<T>::pt0 = pt[0];
		sort(pt + 1, pt + n, point_sorter<T>::cmp_by_angle);
	}
	
	// Conveh hull - Graham
	void build_convex_hull() {
		int i, top1, top2;
		sort_by_coordinates();
		if (pt[0] == pt[n - 1]){
			n_conv = 0;
			pt_conv[n_conv++] = pt[0];
			return;
		}
		pt1[0] = pt2[0] = pt[n - 1];
		pt1[1] = pt2[1] = pt[0];
		top1 = top2 = 2;
		for(i = 1; i < n; i++){
			T d = point<T>::cross(pt[0], pt[n - 1], pt[i]);
			if (i == n - 1 || d < (T)0){
			for(; top1 > 2 && point<T>::cross(pt1[top1 - 2], pt1[top1 - 1], pt[i]) <= (T)0; top1--);
				pt1[top1++] = pt[i];
			}
			if (i == n - 1 || d > (T)0){
				for(; top2 > 2 && point<T>::cross(pt2[top2 - 2], pt2[top2 - 1], pt[i]) >= (T)0; top2--);
				pt2[top2++] = pt[i];
			}
		}
		n_conv = 0;
		for(i = 1; i < top1; i++){
			pt_conv[n_conv++] = pt1[i];
		}
		for(i = top2 - 2; i > 1; i--){
			pt_conv[n_conv++] = pt2[i];
		}
	}
};

point_set<long long> pts[2];

pair<long double, long double> s[4 * MAXN];
int pf[4 * MAXN];

bool cmp_pair_d(pair<long double, long double> &p1, pair<long double, long double> &p2){
	return abs(p1._1 - p2._1) < EPS && abs(p1._2 - p2._2) < EPS;
}

bool check(int n){
	pf[0] = 0;
	for(int i = 1; i < 3 * n + 1; i++){
		int j = pf[i - 1];
		while(j > 0 && !cmp_pair_d(s[j], s[i])){
			j = pf[j - 1];
		}
		if (cmp_pair_d(s[j], s[i])){
			j++;
		}
		pf[i] = j;
		
		if (pf[i] == n){
			return true;
		}
	}
	
	return false;
}

ll xc[2], yc[2];
ll sum[2];

void solve(){
	REP(i, 0, 2){
		scanf("%d", &pts[i].n);
	}
	REP(i, 0, 2){
		REP(j, 0, pts[i].n){
			scanf("%lld%lld", &pts[i].pt[j].x, &pts[i].pt[j].y);
		}
		pts[i].build_convex_hull();
	}
	
	if (pts[0].n_conv != pts[1].n_conv){
		printf("NO\n");
		return;
	}
	
	
	REP(i, 0, 2){
		REP(j, 2, pts[i].n_conv){
			sum[i] += point<ll>::cross(pts[i].pt_conv[0], pts[i].pt_conv[j - 1], pts[i].pt_conv[j]);
		}
	}
	
	if (sum[0] != sum[1]){
		printf("NO\n");
		return;
	}
	
	REP(i, 0, 2){
		REP(j, 0, pts[i].n_conv){
			xc[i] += pts[i].pt_conv[j].x;
			yc[i] += pts[i].pt_conv[j].y;
		}
	}
	
	REP(i, 0, 2){
		
		int offset = i * (pts[0].n_conv + 1);
		
		REP(j, 0, pts[i].n_conv){
			int nxt_ind = (j + 1) % pts[i].n_conv;
			//ll dx = xc[i] - (ll)pts[i].n_conv * pts[i].pt_conv[j].x;
			//ll dy = yc[i] - (ll)pts[i].n_conv * pts[i].pt_conv[j].y;
			
			//long double dx1 = dx / pts[i].n_conv;
			//long double dy1 = dy / pts[i].n_conv;
			
			long double dx1 = xc[i] / (long double)pts[i].n_conv - pts[i].pt_conv[j].x;
			long double dy1 = yc[i] / (long double)pts[i].n_conv - pts[i].pt_conv[j].y;
			
			long double len1 = sqrt(dx1 * dx1 + dy1 * dy1);
			
			long double dx2 = xc[i] / (long double)pts[i].n_conv - pts[i].pt_conv[nxt_ind].x;
			long double dy2 = yc[i] / (long double)pts[i].n_conv - pts[i].pt_conv[nxt_ind].y;
			
			long double len2 = sqrt(dx2 * dx2 + dy2 * dy2);
			
			long double dot = dx1 * dx2 + dy1 * dy2;
			
			long double cos_ang = dot / len1 / len2;
			
			s[j + offset] = mp(len1, cos_ang);
		}	
	}
	
	REP(i, 2 * pts[0].n_conv + 1, 3 * pts[0].n_conv + 1){
		s[i] = s[i - pts[0].n_conv];
	}
	
	if (check(pts[0].n_conv)){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}