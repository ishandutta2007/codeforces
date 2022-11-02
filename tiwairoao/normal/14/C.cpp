#include<set>
#include<cmath>
#include<cstdio>
using namespace std;
const double EPS = 1E-10;
struct Point{
	double x, y;
	Point(double _x=0,double _y=0):x(_x), y(_y){}
};
typedef Point Vector;
Vector operator + (Vector a, Vector b){return Vector(a.x + b.x, a.y + b.y);}
Vector operator - (Vector a, Vector b){return Vector(a.x - b.x, a.y - b.y);}
Vector operator * (Vector a, double k){return Vector(a.x*k, a.y*k);}
Vector operator / (Vector a, double k){return Vector(a.x/k, a.y/k);}
int dcmp(double x){if( fabs(x) < EPS ) return 0; else return x < 0 ? -1 : 1;}
bool operator < (Point a, Point b){if( dcmp(a.x-b.x) == 0) return dcmp(a.y-b.y) < 0; else return dcmp(a.x-b.x) < 0;}
bool operator == (Point a, Point b){return !(a < b) && !(b < a);}
bool operator != (Point a, Point b){return !(a == b);}
double Dot(Vector a, Vector b){return a.x*b.x + a.y*b.y;}
double Cross(Vector a, Vector b){return a.x*b.y - a.y*b.x;}
double Length(Vector a){return sqrt(Dot(a, a));}
Point p[8 + 5]; Vector v[8 + 5];
set<Point>Set;
int main() {
	for(int i=1;i<=8;i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
		Set.insert(p[i]);
	}
	if( Set.size() != 4 ) {
		puts("NO");
		return 0;
	}
	Vector e1 = Vector(0, 1), e2 = Vector(1, 0);
	for(int i=1;i<=4;i++) {
		if( p[i*2] < p[i*2-1] ) swap(p[i*2], p[i*2-1]);
		v[i] = p[i*2-1] - p[i*2];
		if( dcmp(Cross(e1, v[i])) == 0 || dcmp(Cross(e2, v[i])) == 0 );
		else {
			puts("NO");
			return 0;
		}
		if( Length(v[i]) == 0 ) {
			puts("NO");
			return 0;
		}
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			for(int k=1;k<=4;k++)
				for(int l=1;l<=4;l++) {
					if( i == j || i == k || i == l ) continue;
					if( j == k || j == l ) continue;
					if( k == l ) continue;
					if( dcmp(Length(v[i])-Length(v[j])) == 0 && dcmp(Cross(v[i], v[j])) == 0 )
						if( dcmp(Length(v[k])-Length(v[l])) == 0 && dcmp(Cross(v[k], v[l])) == 0 )
							if( (p[2*i-1] != p[2*j-1] || p[2*i] != p[2*j]) && (p[2*k-1] != p[2*l-1] || p[2*k] != p[2*l]) )
								if( dcmp(Dot(v[i], v[k])) == 0 ) {
									puts("YES");
									return 0;
								}
				}
	puts("NO");
}//: