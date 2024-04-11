#include <bits/stdc++.h>

typedef long long ll;
const int N = 2010;

class P{
 public:
  int x, y, id;
  explicit P (int x = 0, int y = 0, int id = 0): x(x), y(y), id(id){}
  P operator + (const P &p)const{return P (x + p.x, y + p.y);}
  P operator - (const P &p)const{return P (x - p.x, y - p.y);}
  ll operator ^ (const P &p)const{return 1ll * x * p.y - 1ll * y * p.x;}
  ll operator % (const P &p)const{return 1ll * x * p.x + 1ll * y * p.y;}

  bool operator < (const P &p)const{
      if (x - p.x) return x < p.x;
      return y < p.y;
  }
};

class L{
 public:
  P p, v;

  L (){}
  L (P a, P b):p(a), v(b - a){}
};

ll onLeft(L l, P p){
    return l.v ^ (p - l.p);
}

std::vector <P> convexHull(std::vector <P> &ps){
    const int N = 100010;
    static P stack[N];
    std::sort(ps.begin(), ps.end());
    int n = ps.size(), top = 0;
    for (int i = 0; i < n; ++ i){
        while (top > 1 && onLeft(L (stack[top - 2], stack[top - 1]), ps[i]) <= 0){
            -- top;
        }
        stack[top ++] = ps[i];
    }
    int tmp = top;
    for (int i = n - 2; i >= 0; -- i){
        while (top > tmp && onLeft(L (stack[top - 2], stack[top - 1]), ps[i]) <= 0){
            -- top;
        }
        stack[top ++] = ps[i];
    }
    if (n > 1) -- top;
    std::vector <P> ret;
    for (int i = 0; i < top; ++ i){
        ret.push_back(stack[i]);
    }
    return ret;
}

char s[N];

int main() {
    int n;
    scanf("%d", &n);
    std::vector <P> ps(n);
    for (int i = 0, x, y; i < n; ++ i){
        scanf("%d%d", &x, &y);
        ps[i] = P(x, y, i + 1);
    }
    scanf("%s", s);
    std::vector <P> tmp = ps;
    ps = convexHull(ps);
    std::vector <int> ans(n);
    if (s[0] == 'L'){
        ans[0] = ps[0].id;
        ans[1] = ps[1].id;
    }
    else{
        ans[0] = ps[1].id;
        ans[1] = ps[0].id;
    }
    ps = tmp;
    for (int i = 0; i < n - 3; ++ i){
        std::vector <P> qs;
        for (auto u : ps){
            if (u.id != ans[i]){
                qs.push_back(u);
            }
        }
        std::vector <P> tmp = qs;
        qs = convexHull(qs);
        int sit = 0, sz = qs.size();
        for (int j = 0; j < sz; ++ j){
            if (qs[j].id == ans[i + 1]){
                sit = j;
                break;
            }
        }
        if (s[i + 1] == 'L'){
            sit = (sit + 1) % sz;
        }
        else{
            sit = (sit - 1 + sz) % sz;
        }
        ans[i + 2] = qs[sit].id;
        ps = tmp;
    }
    for (auto u : ps){
        if (u.id != ans[n - 2] && u.id != ans[n - 3]){
            ans[n - 1] = u.id;
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
    return 0;
}