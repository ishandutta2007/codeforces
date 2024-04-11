#include <iostream>
#include <cmath>
#include <iomanip>

typedef long long ll;
typedef long double ld;

const double INF = 1e100;
const double EPS = 1e-12;
const double PI = acos(-1.0);

int cmp(double a, double b = 0.0) {
  if (fabs(a-b) < EPS) return 0;
  else if (a < b) return -1;
  return 1;
}

struct PT {
  double x,y;
  PT() {}
  PT(double x, double y) : x(x), y(y){}
  PT(const PT &p) : x(p.x), y(p.y){}
  PT operator +(const PT &p)     const { return PT(x+p.x,y+p.y); }
  PT operator -(const PT &p)     const { return PT(x-p.x,y-p.y); }
  PT operator *(double c)        const { return PT(x*c,y*c);     }
  PT operator /(double c)        const { return PT(x/c,y/c);     }
  double operator *(const PT &p) const { return x*p.x+y*p.y;     }
  double operator %(const PT &p) const { return x*p.y-y*p.x;     }
  double operator !()            const { return sqrt(x*x+y*y);   }
  double operator ^(const PT &p) const { return fabs(atan2(*this%p,*this*p)); }
  bool operator ==(const PT &p)  const { return cmp(x,p.x)==0 && cmp(y,p.y)==0; }
  bool operator <(const PT &p)   const {
    if (cmp(x,p.x)!=0) return cmp(x,p.x)==-1;
    return cmp(y,p.y)==-1;
  }
};

std::ostream &operator<<(std::ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

// projeta ponto c no segmento atravs de a e b
PT projPtSeg(PT a, PT b, PT c) {
  b = b - a; c = c - a;
  double r = b * b;
  if (cmp(r) == 0) return a;
  r = c * b / r;
  if (r < 0) return a;
  if (r > 1) return a+b;
  return a + b * r;
}

// calcula a distncia de c para o segmento entre a e b
double distPtSeg(PT a, PT b, PT c) {
  return !(c - projPtSeg(a, b, c));
}

PT cnt, a[100100];

int main()
{
	int n;
	while(std::cin >> n >> cnt.x >> cnt.y)
	{
		ld min = 1e18, max = 0;
		for(int i = 0; i < n; i++)
		{
			std::cin >> a[i].x >> a[i].y;
			ld cur_dist = !(cnt - a[i]);
			min = std::min(min, cur_dist);
			max = std::max(max, cur_dist);
			if(i)
			{
				cur_dist = distPtSeg(a[i - 1], a[i], cnt);
				//std::cout << "(" << i - 1 << ", " << i << ") got dist " << (double)cur_dist << "\n";
				min = std::min(min, cur_dist);
				max = std::max(max, cur_dist);
			}
			if(i + 1 == n)
			{
				cur_dist = distPtSeg(a[0], a[i], cnt);
				//std::cout << "(" << 0 << ", " << n - 1 << ") got dist " << (double)cur_dist << "\n";
				min = std::min(min, cur_dist);
				max = std::max(max, cur_dist);
			}
		}
		std::cout << std::fixed << std::setprecision(20);
		std::cout << (double) (PI * (max * max - min * min)) << '\n';
	}
}