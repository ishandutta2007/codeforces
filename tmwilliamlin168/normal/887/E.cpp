#include <bits/stdc++.h>
       
using namespace std;
       
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
 
struct pt{
    db x, y;
    pt() {}
    pt(db x1, db y1) { x = x1, y = y1; }
    pt operator- (pt nxt) const { return pt(x - nxt.x, y - nxt.y); }
    pt operator+ (pt nxt) const { return pt(x + nxt.x, y + nxt.y); }
    pt operator/ (db val) const { return pt(x / val, y / val); }
    pt operator* (db val) const { return pt(x * val, y * val); }
    db len() { return sqrt(x * x + y * y); }
    db squareLen() { return x * x + y * y; }
    pt norm(db val) const { db tmp = pt(x, y).len(); return pt(x * val / tmp, y * val / tmp); }
    db operator% (pt nxt) const { return x * nxt.y  - y * nxt.x; }
};
 
pt a, b;
int n;
pair<pt, int> q[500007];
 
bool cross(pt a, db r1, pt b, db r2){
    if (r1 < r2) swap(r1, r2);
    if ((a - b).squareLen() < r1 * r1){
        //in
        if ((a - b).squareLen() > (r1 - r2) * (r1 - r2)) return 1;
    } else {
        //out
        if ((a - b).squareLen() < (r1 + r2) * (r1 + r2)) return 1;
    }
    return 0;
}
 
bool in(pt a, db r1, pt b, db r2){
    if (r1 > r2) return 0;
    return (a - b).len() + r1 <= r2;
}
 
int sign(db val){
    if (val < 0) return -1;
    return 1;
}
 
db solve(pt v){
    vector<pair<db, int> > t;
    pt sr = a + (b - a) / 2;
 
    bool crossStart = 0;
 
    for (int i = 0; i < n; i++){
        db l, r;
        if (sign((b - a) % (q[i].x - a)) == sign((b - a) % ((sr + v) - a))){
            if (in(q[i].x, q[i].y, sr, ((b - a) / 2).len())) continue;
            if (cross(sr, ((a - b) / 2). len(), q[i].x, q[i].y)) crossStart = 1, l = 0;
            else {
                db vl = 0, vr = 1e12;
                for (int it = 0; it < 100; it++){
                    db vm = (vl + vr) / (db)2;
                    pt s2 = a + (b - a) / 2 + v.norm(vm);
                    db r2 = sqrt(vm * vm + ((a - b) / 2).squareLen());
                    if (cross(q[i].x, q[i].y, s2, r2) || in(q[i].x, q[i].y, s2, r2))
                        vr = vm;
                    else
                        vl = vm;
                }
                l = vl;
            }
            db vl = 0, vr = 1e12;
            for (int it = 0; it < 100; it++){
                db vm = (vl + vr) / (db)2;
                pt s2 = a + (b - a) / 2 + v.norm(vm);
                db r2 = sqrt(vm * vm + ((a - b) / 2).squareLen());
                if (in(q[i].x, q[i].y, s2, r2))
                    vr = vm;
                else
                    vl = vm;
            }
            r = vr;
        } else {
            if (!in(q[i].x, q[i].y, sr, ((b - a) / 2).len()) && !cross(sr, ((a - b) / 2).len(), q[i].x, q[i].y)) continue;
            if (cross(sr, ((a - b) / 2).len(), q[i].x, q[i].y)) crossStart = 1, l = 0;
            else {
                db vl = 0, vr = 1e12;
                for (int it = 0; it < 100; it++){
                    db vm = (vl + vr) / (db)2;
                    pt s2 = a + (b - a) / 2 + v.norm(vm);
                    db r2 = sqrt(vm * vm + ((a - b) / 2).squareLen());
                    if (in(q[i].x, q[i].y, s2, r2))
                        vl = vm;
                    else
                        vr = vm;
                }
                l = vl;
            }
            db vl = 0, vr = 1e12;
            for (int it = 0; it < 100; it++){
                db vm = (vl + vr) / (db)2;
                pt s2 = a + (b - a) / 2 + v.norm(vm);
                db r2 = sqrt(vm * vm + ((a - b) / 2).squareLen());
                if (cross(q[i].x, q[i].y, s2, r2) || in(q[i].x, q[i].y, s2, r2))
                    vl = vm;
                else
                    vr = vm;
            }
            r = vr;
        }
        t.pub(mp(l, -1));
        t.pub(mp(r, 1));
        //pt s2 = a + (b - a) / 2 + v.norm(r);
        //cout << i << ' ' << l << ' ' << r << ' ' << s2.x << ' ' << s2.y << ' ' << sqrt(r * r + ((a - b) / 2).squareLen()) << endl;
    }
    //cout << v.x << ' ' << v.y << endl;
 
    sort(all(t));
    db val = 0;
 
    if (crossStart){
        int bal = 0;
        for (int i = 0; i < t.size(); i++){
            bal += t[i].y;
            if (bal == 0){
                val = t[i].x;
                break;
            }
        }
    }
 
    return sqrt(val * val + ((a - b) / 2).squareLen());
}
 
//O(nlog(n));
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a.x >> a.y >> b.x >> b.y >> n;
    for (int i = 0; i < n; i++) cin >> q[i].x.x >> q[i].x.y >> q[i].y;
 
    pt w = pt(-(a - b).y, (a - b).x);
 
    cout.precision(10);
    cout << fixed << (double)min(solve(w), solve(pt(0, 0) - w));
}