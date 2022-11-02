#include<cstdio>
#include<vector>
#include<complex>

using namespace std;

int n;
double h, f;
const double EPS = 1e-8;
typedef complex<double> pt;
typedef vector<pt> polygon;
double cross(const pt& a, const pt& b) {
  return imag(conj(a)*b);
}
double dot(const pt& a, const pt& b) {
  return real(conj(a)*b);
}
int ccw(pt a, pt b, pt c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}
enum { OUT, ON, IN };
int convex_contains(const polygon &P, const pt &p) {
  const int n = P.size();
  pt g = (P[0] + P[n/3] + P[2*n/3]) / 3.0; // inner-point
  int a = 0, b = n;
  while (a+1 < b) { // invariant: c is in fan g-P[a]-P[b]
    int c = (a + b) / 2;
    if (cross(P[a]-g, P[c]-g) > 0) { // angle < 180 deg
      if (cross(P[a]-g, p-g) > 0 && cross(P[c]-g, p-g) < 0) b = c;
      else                                                  a = c;
    } else {
      if (cross(P[a]-g, p-g) < 0 && cross(P[c]-g, p-g) > 0) a = c;
      else                                                  b = c;
    }
  }
  b %= n;
  if (cross(P[a] - p, P[b] - p) < 0) return 0;
  if (cross(P[a] - p, P[b] - p) > 0) return 2;
  return 1;
}
typedef double number;
bool intersect_1pt(const pt& a, const pt& b,
                   const pt& c, const pt& d, pt &r) {
  number D =  cross(b - a, d - c);
  if (-EPS<D && D<EPS) return false;
  number t =  cross(c - a, d - c) / D;
  number s = -cross(a - c, b - a) / D;
  r = a + t * (b - a);
  return t>=0 && t<=1 && s>=0 && s<=1;
}
polygon convex_intersect(const polygon &P, const polygon &Q) {
  const int n = P.size(), m = Q.size();
  int a = 0, b = 0, aa = 0, ba = 0;
  enum { Pin, Qin, Unknown } in = Unknown;
  polygon R;
  do {
    int a1 = (a+n-1) % n, b1 = (b+m-1) % m;
    number C = cross(P[a] - P[a1], Q[b] - Q[b1]);
    number A = cross(P[a1] - Q[b], P[a] - Q[b]);
    number B = cross(Q[b1] - P[a], Q[b] - P[a]);
    pt r;
    if (intersect_1pt(P[a1], P[a], Q[b1], Q[b], r)) {
      if (in == Unknown) aa = ba = 0;
      R.push_back( r );
      in = B > 0 ? Pin : A > 0 ? Qin : in;
    }
    if (C == 0 && B == 0 && A == 0) {
      if (in == Pin) { b = (b + 1) % m; ++ba; }
      else           { a = (a + 1) % m; ++aa; }
    } else if (C >= 0) {
      if (A > 0) { if (in == Pin) R.push_back(P[a]); a = (a+1)%n; ++aa; }
      else       { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
    } else {
      if (B > 0) { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
      else       { if (in == Pin) R.push_back(P[a]); a = (a+1)%n; ++aa; }
    }
  } while ( (aa < n || ba < m) && aa < 2*n && ba < 2*m );
  if (in == Unknown) {
    if (convex_contains(Q, P[0])) return P;
    if (convex_contains(P, Q[0])) return Q;
  }
  return R;
}
number area(const polygon& P) {
  number A = 0;
  for (int i = 0; i < P.size(); ++i) 
    A += cross(P[i], P[(i+1)%P.size()]);
  return A / 2;
}

struct daikei {
  double ux1, ux2;
  double dx1, dx2;
  daikei(double a, double b, double c, double d)
    : ux1(a), ux2(b), dx1(c), dx2(d) { }
};

double intersect(const daikei& a, const daikei& b)
{
  polygon P, Q;
  P.push_back(pt(a.ux2, h));
  P.push_back(pt(a.ux1, h));
  P.push_back(pt(a.dx1, -h));
  P.push_back(pt(a.dx2, -h));
  Q.push_back(pt(b.ux2, h));
  Q.push_back(pt(b.ux1, h));
  Q.push_back(pt(b.dx1, -h));
  Q.push_back(pt(b.dx2, -h));
  return area(convex_intersect(P, Q));
}

int main()
{
  scanf("%d%lf%lf", &n, &h, &f);
  vector<daikei> ue, st;
  for(int i=0; i<n; ++i) {
    double l, r;
    scanf("%lf%lf", &l, &r);
    ue.push_back(daikei(l, r, l*(f+h)/(f-h), r*(f+h)/(f-h)));
    st.push_back(daikei(l*(f+h)/(f-h), r*(f+h)/(f-h), l, r));
  }
  double area = 0;
  for(int i=0; i<n; ++i) {
    area += (ue[i].ux2-ue[i].ux1 + ue[i].dx2-ue[i].dx1) * h;
    area += (st[i].ux2-st[i].ux1 + st[i].dx2-st[i].dx1) * h;
  }
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      area -= intersect(ue[i], st[j]);
  printf("%.9f\n", area);
  return 0;
}