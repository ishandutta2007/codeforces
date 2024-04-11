#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100 + 4;
const double EPS = 1e-8;

int signum(double x, double eps = EPS) {
	return x < -eps ? -1 : x > eps;
}

// {{{ Point class
struct Point {
	double x, y;

	Point(double x = 0, double y = 0) : x(x), y(y) {}

	Point &operator += (Point o) {
		x += o.x;
		y += o.y;
		return *this;
	}

	Point &operator -= (Point o) {
		x -= o.x;
		y -= o.y;
		return *this;
	}

	Point &operator *= (double k) {
		x *= k;
		y *= k;
		return *this;
	}

	Point &operator /= (double k) {
		x /= k;
		y /= k;
		return *this;
	}

	double norm2() {
		return x * x + y * y;
	}

	double norm() {
		return sqrt(norm2());
	}

	double arg() {
		return atan2(y, x);
	}

	bool on(Point , Point );
	bool in(const vector <Point> &);
};

bool operator <(Point a, Point b) {
	return signum(a.x - b.x) < 0 || signum(a.x - b.x) == 0 && signum(a.y - b.y) < 0;
}

bool operator ==(Point a, Point b) {
	return signum(a.x - b.x) == 0 && signum(a.y - b.y) == 0;
}

Point operator +(Point a, Point b) {
	return a += b;
}

Point operator -(Point a, Point b) {
	return a -= b;
}

Point operator *(double k, Point a) {
	return a *= k;
}

Point operator *(Point a, double k) {
	return a *= k;
}

Point operator /(Point a, double k) {
	return a /= k;
}

double det(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}

double dot(Point a, Point b) {
	return a.x * b.x + a.y * b.y;
}

bool parallel(Point a, Point b, Point c, Point d) {
	return signum(det(b - a, d - c)) == 0;
}

Point intersect(Point a,  Point b, Point c, Point d) {
	double s1 = det(b - a, c - a);
	double s2 = det(b - a, d - a);
	return (c * s2 - d * s1) / (s2 - s1);
}

bool Point::on(Point a, Point b) {
	Point p = *this;
	return signum(det(p - a, p - b)) == 0 && signum(dot(p - a, p - b)) <= 0;
}

bool Point::in(const vector <Point> &polygon) {
	Point p = *this;
	int n = polygon.size();
	int count = 0;
	for (int i = 0; i < n; ++i) {
		Point a = polygon[i];
		Point b = polygon[(i + 1) % n];
		if (p.on(a, b)) {
			return false;
		}
		int t0 = signum(det(a - p, b - p));
		int t1 = signum(a.y - p.y);
		int t2 = signum(b.y - p.y);
		count += t0 > 0 && t1 <= 0 && t2 > 0;
		count -= t0 < 0 && t2 <= 0 && t1 > 0;
	}
	return count != 0;
}

// }}}

int width, height, n;
Point segments[N][2];

void addSegment (Point a, Point b) {
	segments[n][0] = a;
	segments[n][1] = b;
	++n;
}

vector<Point> points;

int getPointID(Point p) {
	return lower_bound(points.begin(), points.end(), p) - points.begin();
}

const int V = N * 2 + N * (N - 1) / 2;
const int E = V * 3 * 2;

int edgeCount, firstEdge[V], to[E], nextEdge[E], next[E];
bool visit[E];
set<pair<int, int> > geometricEdges;

void addGeometricEdge(int u, int v) {
	if (!geometricEdges.count(make_pair(u, v))) {
		geometricEdges.insert(make_pair(u, v));
		to[edgeCount] = v;
		nextEdge[edgeCount] = firstEdge[u];
		firstEdge[u] = edgeCount++;
	}
}

vector<double> areas, allAreas;
vector<vector<Point> > regions;

const int VERTEX = 0;
const int EDGE = 1;
const int REGION = 2;

int getID(int type, int id) {
	if (type == VERTEX) {
		return id;
	}
	if (type == EDGE) {
		return points.size() + id;
	}
	if (type == REGION) {
		return points.size() + (edgeCount >> 1) + id;
	}
}


double getArea(int id) {
	id -= points.size() + (edgeCount >> 1);
	return id < 0 ? 0 : areas[id];
}

int locate(Point p) {
	for (int i = 0; i < edgeCount; i += 2) {
		if (p.on(points[to[i]], points[to[i ^ 1]])) {
			return getID(EDGE, i >> 1);
		}
	}
	int best = -1;
	for (int i = 0; i < (int)regions.size(); ++i) {
		if (p.in(regions[i]) && (best == -1 || allAreas[best] > allAreas[i])) {
			best = i;
		}
	}
	return getID(REGION, best);
}

const int VV = V * 5;

vector<int> edges[VV];

void addTopologicalEdge(int u, int v) {
	edges[u].push_back(v);
	edges[v].push_back(u);
}

vector<string> colorNames;
map<string, int> colorIDs;

int getColorID(const char *color) {
	if (!colorIDs.count(color)) {
		colorNames.push_back(color);
		int newID = colorIDs.size();
		colorIDs[color] = newID;
	}
	return colorIDs[color];
}

int color[VV];

void paint(Point p, const char *c) {
	int start = locate(p);
	int old = color[start];
	int cid = getColorID(c);
	if (old != cid) {
		queue<int> queue;
		queue.push(start);
		color[start] = cid;
		while (!queue.empty()) {
			int u = queue.front();
			queue.pop();
			for (int i = 0; i < (int)edges[u].size(); ++i) {
				int v = edges[u][i];
				if (color[v] == old) {
					color[v] = cid;
					queue.push(v);
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &width, &height, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf%lf%lf", &segments[i][0].x, &segments[i][0].y, &segments[i][1].x, &segments[i][1].y);
	}
	addSegment(Point(0, 0), Point(width, 0));
	addSegment(Point(width, 0), Point(width, height));
	addSegment(Point(width, height), Point(0, height));
	addSegment(Point(0, height), Point(0, 0));

	//farmland
	for (int i = 0; i < n; ++i) {
		points.push_back(segments[i][0]);
		points.push_back(segments[i][1]);
		for (int j = 0; j < i; ++j) {
			if (!parallel(segments[i][0], segments[i][1], segments[j][0], segments[j][1])) {
				Point p = intersect(segments[i][0], segments[i][1], segments[j][0], segments[j][1]);
				if (p.on(segments[i][0], segments[i][1]) && p.on(segments[j][0], segments[j][1])) {
					points.push_back(p);
				}
			}
		}
	}
	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());

	edgeCount = 0;
	memset(firstEdge, -1, sizeof(firstEdge));
	for (int i = 0; i < n; ++i) {
		vector<pair<double, int> > pairs;
		Point a = segments[i][0];
		Point b = segments[i][1];
		for (int j = 0; j < (int)points.size(); ++ j) {
			if (points[j].on(a, b)) {
				pairs.push_back(make_pair((points[j] - a).norm(), j));
			}
		}
		sort(pairs.begin(), pairs.end());
		for (int j = 1; j < (int)pairs.size(); ++j) {
			int u = pairs[j - 1].second;
			int v = pairs[j].second;
			addGeometricEdge(u, v);
			addGeometricEdge(v, u);
		}
	}

	for (int u = 0; u < (int)points.size(); ++u) {
		vector<pair<double, int> > pairs;
		for (int iter = firstEdge[u]; ~iter; iter = nextEdge[iter]) {
			pairs.push_back(make_pair((points[to[iter]] - points[u]).arg(), iter));
		}
		sort(pairs.begin(), pairs.end());
		for (int i = 0; i < (int)pairs.size(); ++i) {
			next[pairs[(i + 1) % (int)pairs.size()].second ^ 1] = pairs[i].second;
		}
	}

	vector<pair<Point, double> > waits;
	memset(visit, 0, sizeof(visit));
	for (int start = 0; start < edgeCount; ++start) {
		if (!visit[start]) {
			int e = start;
			double totalArea = 0;
			vector<Point> region;
			for (; !visit[e]; e = next[e]) {
				visit[e] = true;
				totalArea += det(points[to[e ^ 1]], points[to[e]]);
				region.push_back(points[to[e]]);
			}
			if (signum(totalArea) > 0) {
				regions.push_back(region);
				areas.push_back(totalArea);
				allAreas.push_back(totalArea);
			} else {
				waits.push_back(make_pair(region.front(), -totalArea));
			}
		}
	}
	
	for (int i = 0; i < edgeCount; ++ i) {
		addTopologicalEdge(getID(EDGE, i >> 1), getID(VERTEX, to[i]));
	}
	for (int i = 0; i < (int)regions.size(); ++i) {
		addTopologicalEdge(getID(REGION, i), getID(VERTEX, getPointID(regions[i].front())));
	}
	for (int _ = 0; _ < waits.size(); ++_) {
		Point p = waits[_].first;
		int best = -1;
		for (int i = 0; i < (int)regions.size(); ++i) {
			if (p.in(regions[i]) && (best == -1 || allAreas[best] > allAreas[i])) {
				best = i;
			}
		}
		if (best != -1) {
			areas[best] -= waits[_].second;
			addTopologicalEdge(getID(REGION, best), getID(VERTEX, getPointID(p)));
		}
	}

	getColorID("white");
	getColorID("black");
	getColorID("__COLOR__");
	
	for (int i = 0; i < (int)points.size(); ++i) {
		color[getID(VERTEX, i)] = getColorID("black");
	}
	for (int i = 0; i < edgeCount >> 1; ++i) {
		color[getID(EDGE, i)] = getColorID("black");
	}
	for (int i = 0; i < (int)regions.size(); ++i) {
		color[getID(REGION, i)] = getColorID("white");
	}
	paint(Point(0, 0), "__COLOR__");
	int m;
	scanf("%d", &m);
	while (m--) {
		Point p;
		char buffer[16];
		scanf("%lf%lf%s", &p.x, &p.y, buffer);
		paint(p, buffer);
	}

	map<string, double> answer;
	for (int i = 0; i < (int)points.size() + (edgeCount >> 1) + (int)regions.size(); ++ i) {
		string name = colorNames[color[i]];
		if (name != "__COLOR__") {
			answer[name] += getArea(i);
		}
	}

	for (map<string, double>::iterator it = answer.begin(); it != answer.end(); ++it) {
		printf("%s %.8lf\n", it->first.c_str(), it->second * 0.5);
	}
	
	return 0;
}