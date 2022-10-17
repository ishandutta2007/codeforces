#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one

struct BIT{
	VI A;
	BIT(int sz){
		A.resize(sz+5);
	}
	int sum(int i) // Returns the sum from index 1 to i
	{
		i++;
	    int sum = 0;
	    while (i > 0) 
	        sum += A[i], i -= LSB(i);
	    return sum;
	}
	 
	void add(int i, int k) // Adds k to element with index i
	{
		i++;
	    while (i < SZ(A)) 
	        A[i] += k, i += LSB(i);
	}	
};


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<
T,
null_type,
std::less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;

struct Event{
	bool ver;
	int where;
	int x, y;
	Event(bool v, int w, int _x, int _y){
		ver = v;
		where = w;
		x = _x;
		y = _y;
	}
};

struct CMP{
	bool operator ()(const Event &a, const Event &b){
		int ax = (a.ver ? a.where : a.x);
		int bx = (b.ver ? b.where : b.x);
		if(ax != bx) return ax < bx;
		if(a.ver != b.ver) return !a.ver;
		if(a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	}
};

int n;
std::vector<PR<int, PII> > ver, hor;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::vector<Event> events;
	FOR(i, n){
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == x2){
			if(y1 > y2) std::swap(y1, y2);
			ver.push_back(MP(x1, MP(y1, y2)));
			events.push_back(Event(true, x1, y1, y2));
		}else{
			if(x1 > x2) std::swap(x1, x2);
			hor.push_back(MP(y1, MP(x1, x2)));
			events.push_back(Event(false, y1, x1, 1));
			events.push_back(Event(false, y1, x2+1, -x1-1000000000));
		}
	}
	std::sort(events.begin(), events.end(), CMP());
	ll ans = 0;
	BIT bit(10020);
	FOR(i, SZ(ver)){
		// ll cur = 0;
		int min = ver[i].Y.X;
		int max = ver[i].Y.Y;
		int go = ver[i].X;
		ordered_set<int> set;
		TRAV(ev, events){
			if(ev.ver){
				if(go < ev.where){
					int mnwsp = std::max(min, ev.x);
					int mxwsp = std::min(max, ev.y);
					if(mnwsp < mxwsp){
						// int have = set.order_of_key(mxwsp+1)-set.order_of_key(mnwsp);
						int have = bit.sum(mxwsp+5002)-bit.sum(mnwsp+5002-1);
						ans += 1ll*have*(have-1)/2;
						// cur += 1ll*have*(have-1)/2;
					}
				}
			}else{
				if(ev.y == 1){
					if(ev.x <= go){
						bit.add(ev.where+5002, 1);
					}
				}else if(-ev.y - 1000000000 <= go){
					bit.add(ev.where+5002, -1);
				}
			}
		}
		// std::cout << ver[i].Y.X << " " << ver[i].Y.Y << " at x " << ver[i].X << " = " << cur << std::endl;
	}
	std::cout << ans;
	return 0;
}