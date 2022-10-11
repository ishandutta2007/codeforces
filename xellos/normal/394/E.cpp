#include <bits/stdc++.h>
using namespace std;

struct point {
	double x,y;
	point() {}
	point(double a, double b) {x =a, y =b;}
	};

double vcp(point A, point B, point O) {
	return (A.x-O.x)*(B.y-O.y)-(B.x-O.x)*(A.y-O.y);}

struct Polygon {
	int v;
	vector<point> V;
	Polygon(int N) {v =N; V.resize(N);}

	bool inPoly(point P) {
		for(int i =0; i < v; i++) {
			point X =V[i], Y =V[(i+1)%v], Z =V[(i+2)%v];
			if(vcp(Y,Z,X)*vcp(Y,P,X) < -1e-9) return false;}
		return true;}
	};

int main() {
	cin.sync_with_stdio(0);
	int N,M;
	cin >> N;
	vector<double> X(N), Y(N);
	double SSx =0, SSy =0, Sx =0, Sy =0;
	for(int i =0; i < N; i++) {
		cin >> X[i] >> Y[i];
		SSx +=X[i]*X[i];
		SSy +=Y[i]*Y[i];
		Sx +=X[i];
		Sy +=Y[i];}

	cin >> M;
	Polygon P(M);
	for(int i =0; i < M; i++) cin >> P.V[i].x >> P.V[i].y;

	double ans =1e+20;

	point p0(Sx/N,Sy/N);
	if(P.inPoly(p0))
		ans =min(ans,SSx+SSy+N*p0.x*p0.x+N*p0.y*p0.y-2*p0.x*Sx-2*p0.y*Sy);

	for(int i =0; i < M; i++) {
		if(abs(P.V[i].x-P.V[(i+1)%M].x) < 1e-9) {
			double k =(P.V[(i+1)%M].x-P.V[i].x)/(P.V[(i+1)%M].y-P.V[i].y);
			double c =P.V[i].x-k*P.V[i].y;
			point p1((k*Sx+Sy-N*c*k)/N/(1+k*k)*k+c,(k*Sx+Sy-N*c*k)/N/(1+k*k));
			if(p1.y >= min(P.V[i].y,P.V[(i+1)%M].y)-1e-9 && p1.y <= max(P.V[i].y,P.V[(i+1)%M].y)+1e-9)
				ans =min(ans,SSx+SSy+N*p1.x*p1.x+N*p1.y*p1.y-2*p1.x*Sx-2*p1.y*Sy);
			continue;}

		double k =(P.V[(i+1)%M].y-P.V[i].y)/(P.V[(i+1)%M].x-P.V[i].x);
		double c =P.V[i].y-k*P.V[i].x;
		point p1((Sx+k*Sy-N*c*k)/N/(1+k*k),(Sx+k*Sy-N*c*k)/N/(1+k*k)*k+c);
		if(p1.x >= min(P.V[i].x,P.V[(i+1)%M].x)-1e-9 && p1.x <= max(P.V[i].x,P.V[(i+1)%M].x)+1e-9)
			ans =min(ans,SSx+SSy+N*p1.x*p1.x+N*p1.y*p1.y-2*p1.x*Sx-2*p1.y*Sy);
		}

	for(int i =0; i < M; i++) {
		point p2 =P.V[i];
		ans =min(ans,SSx+SSy+N*p2.x*p2.x+N*p2.y*p2.y-2*p2.x*Sx-2*p2.y*Sy);}

	cout << fixed << setprecision(10) << ans << "\n";
	return 0;}