//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

struct pt{
    int x, y;
    pt(){}
    pt(int _x, int _y):x(_x), y(_y){}
    pt operator + (const pt & a)const{return pt(a.x + x, a.y + y);}
    pt operator - (const pt & a)const{return pt(x - a.x, y - a.y);}
    pt operator * (int a){return pt(x * a, y * a);}
    int64_t cross(const pt & a)const{return x * 1ll * a.y - y * 1ll * a.x;}
    int64_t cross(const pt & a, const pt & b)const{return (a - *this).cross(b - *this);}
    int half()const{
        return y > 0 || (y == 0 && x > 0);
    }
    bool operator < (const pt & a)const{
        if(half() != a.half())
            return half() > a.half();
        return this->cross(a) > 0;
    }
};

class HullInsert {
    set<pt> hull;
    int64_t area = 0;
    pt mid;
public:
    HullInsert(pt a, pt b, pt c){
       mid = a + b + c;
       hull.insert(a * 3 - mid);
       hull.insert(b * 3 - mid);
       hull.insert(c * 3 - mid);
       area = 9 * abs(a.cross(b, c));
    }
    bool insert(pt a){
        a = a * 3 - mid;
        if(a.x == 0 && a.y == 0)
            return false;
        auto it = hull.lower_bound(a);
        if(it == hull.begin())
            it = hull.end();
        --it;
        auto L = it, R = it;
        vector<pt> rm;
        auto jt = it;
        ++jt;
        if(jt == hull.end())
            jt = hull.begin();
        ll S1 = abs(it->cross(*jt));
        S1 -= abs(a.cross(*it, *jt)) + abs(a.cross(*jt, pt(0, 0))) + abs(a.cross(pt(0, 0), *it));
        if(!S1)
            return false;
        while(1){
            jt = L;
            ++jt;
            if(jt == hull.end())
                jt = hull.begin();
            if(a.cross(*L, *jt) < 0){
                rm.pb(*L);
                area += abs(a.cross(*L, *jt));
                L = jt;
            }
            else break;
        }
        while(1){
            jt = R;
            if(jt == hull.begin())
                jt = hull.end();
            --jt;
            if(a.cross(*R, *jt) > 0){
                rm.pb(*R);
                area += abs(a.cross(*R, *jt));
                R = jt;
            }
            else break;
        }
        for(auto & p : rm){
            if((p.x == L->x && p.y == L->y) || (p.x == R->x && p.y == R->y))
                continue;
            hull.erase(p);
            pt tmp = p + mid;
        }
        hull.insert(a);
        return true;
    }
    bool inside(pt a){
        a = a * 3 - mid;
        if(a.x == 0 && a.y == 0)
            return true;
        auto it = hull.lower_bound(a);
        if(it == hull.begin())
            it = hull.end();
        --it;
        auto L = it, R = it;
        auto jt = it;
        ++jt;
        if(jt == hull.end())
            jt = hull.begin();
        ll S1 = abs(it->cross(*jt));
        S1 -= abs(a.cross(*it, *jt)) + abs(a.cross(*jt, pt(0, 0))) + abs(a.cross(pt(0, 0), *it));
        if(!S1)
            return true;
        return false;
    }
    int64_t double_area()const{return area/9;}
};

signed main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int q;
    scanf("%d", &q);
    q -= 3;
    int tmp;
    pt a, b, c;
    scanf("%d %d %d", &tmp, &a.x, &a.y);
    scanf("%d %d %d", &tmp, &b.x, &b.y);
    scanf("%d %d %d", &tmp, &c.x, &c.y);
    HullInsert hull(a, b, c);
    F(i, 0, q){
        int tp;
        pt p;
        scanf("%d %d %d", &tp, &p.x, &p.y);
        if(tp == 1)
            hull.insert(p);
        else{
            if(hull.inside(p))printf("YES\n"); else printf("NO\n");
        }
    }
	return 0;
}