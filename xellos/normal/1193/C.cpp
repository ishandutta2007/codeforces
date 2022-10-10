#include <bits/stdc++.h>
using namespace std;

using xy_t = double;

constexpr xy_t eps = 1e-6;
constexpr double pi = 3.14159265358979323846;

struct Point {
	xy_t x, y;

	Point() {}
	Point(xy_t x_, xy_t y_) : x{x_}, y{y_} {}

	Point operator+(const Point p) const {
		return {this->x + p.x, this->y + p.y};
	}
	Point * operator+=(const Point p) {
		this->x += p.x;
		this->y += p.y;
		return this;
	}
	Point operator-(const Point p) const {
		return {this->x - p.x, this->y - p.y};
	}
	Point * operator-=(const Point p) {
		this->x -= p.x;
		this->y -= p.y;
		return this;
	}
	Point operator*(double c) const {
		return {this->x * c, this->y * c};
	}
	Point * operator*=(double c) {
		this->x *= c;
		this->y *= c;
		return this;
	}
	// rot
	Point operator^(double c) const {
		return {this->x * cos(c) - this->y * sin(c), this->y * cos(c) + this->x * sin(c)};
	}

	double get_rot(const Point p) const {
		// (*this) ^ result == p * const
		double rot_this = atan2(this->y, this->x);
		double rot_p = atan2(p.y, p.x);
		double rot = rot_p - rot_this;
		while(rot < 0) rot += 2*pi;
		while(rot > 2*pi) rot -= 2*pi;
		return rot;
	}
};

xy_t dot(Point a, Point b) { return a.x*b.x+a.y*b.y; }
xy_t dot(Point a, Point b, Point o) { return dot(a-o, b-o); }
xy_t cross(Point a, Point b) { return a.x*b.y-b.x*a.y; }
xy_t cross(Point a, Point b, Point o) { return cross(a-o, b-o); }

int sign(xy_t x) { return ((x > 0) ? 1 : ((x < 0) ? -1 : 0)); }

bool point_in_triangle(Point A, Point B, Point C, Point P) {
	if(sign(cross(A, B, C)) != sign(cross(P, B, C))) return false;
	if(sign(cross(B, C, A)) != sign(cross(P, C, A))) return false;
	if(sign(cross(C, A, B)) != sign(cross(P, A, B))) return false;
	return true;
}

struct Shape {
	vector<Point> V;

	Shape(initializer_list<Point> init) : V(init) {}
	Shape() {}
	Shape(int N) : V(N) {}
	Shape(vector<Point> V_) : V(V_) {}

	int size() { return V.size(); }

	Shape operator^(double c) {
		Shape ret(V.size());
		for(int i = 0; i < (int)V.size(); i++) ret.V[i] = V[i] ^ c;
		return ret;
	}
};

struct RectangleSequence {
	vector<xy_t> H, W;

	int size() { return H.size(); }
};

struct OperationPair { // scissors, then tape
	Shape start_shape;
	vector<Shape> parts_first;
	vector<Shape> parts_moved;
	Shape final_shape;
};

vector<OperationPair> invert(vector<OperationPair> ops) {
	reverse(begin(ops), end(ops));
	for(auto & op : ops) {
		swap(op.start_shape, op.final_shape);
		swap(op.parts_first, op.parts_moved);
	}
	return ops;
}

void rotl(Point & A, Point & B, Point & C) { Point tmp = A; A = B; B = C; C = tmp; }
void rotr(Point & A, Point & B, Point & C) { Point tmp = C; C = B; B = A; A = tmp; }

RectangleSequence triangulate_to_rectangles(Shape s, vector<OperationPair> & ops) {
	vector<Point> V = s.V;
	RectangleSequence ret;
	OperationPair op;
	op.start_shape = s;
	op.final_shape = {{0, 0}};
	double r_H = 0;
	while(V.size() > 2U) {
		int N = V.size();
		for(int i = 0; i < N; i++) {
			Point A = V[(i+N-1)%N], B = V[i], C = V[(i+1)%N];
			if(cross(B, C, A) < 0) continue; // not inside the polygon
			bool can_be_cut = true;
			for(int j = 0; j < N; j++) {
				if(i == j || (i+1-j)%N == 0 || (i-1-j)%N == 0) continue;
				if(point_in_triangle(A, B, C, V[j])) can_be_cut = false;
			}
			if(!can_be_cut) continue;
			xy_t lA = dot(B-C, B-C), lB = dot(A-C, A-C), lC = dot(A-B, A-B);
			double cos_A = (lB+lC-lA) / 2 / sqrt(lB*lC);
			double cos_B = (lA+lC-lB) / 2 / sqrt(lA*lC);
			double cos_C = (lA+lB-lC) / 2 / sqrt(lA*lB);
			if(cos_B < min(cos_A, cos_C)) rotl(A, B, C);
			else if(cos_C < min(cos_A, cos_B)) rotr(A, B, C);
			lA = dot(B-C, B-C), lB = dot(A-C, A-C), lC = dot(A-B, A-B);
			cos_A = (lB+lC-lA) / 2 / sqrt(lB*lC);
			cos_B = (lA+lC-lB) / 2 / sqrt(lA*lC);
			cos_C = (lA+lB-lC) / 2 / sqrt(lA*lB);
			Point cB = (A+B) * .5, cC = (A+C) * .5;
			xy_t dB = sqrt(lC) / 2 * cos_B, dC = sqrt(lB) / 2 * cos_C;
			xy_t w = sqrt(lC) * sqrt(1-cos_B*cos_B);
			op.parts_first.push_back({B, B + (C-B) * (dB/sqrt(lA)), cB});
			op.parts_moved.push_back({{w, r_H+dC}, {w, r_H+dC+dB}, {w/2, r_H+dC+dB}});
			op.parts_first.push_back({C, cC, C + (B-C) * (dC/sqrt(lA))});
			op.parts_moved.push_back({{w, r_H+dC}, {w/2, r_H}, {w, r_H}});
			op.parts_first.push_back({C + (B-C) * (dC/sqrt(lA)), cC, A, cB, B + (C-B) * (dB/sqrt(lA))});
			op.parts_moved.push_back({{0, r_H}, {w/2, r_H}, {w, r_H+dC}, {w/2, r_H+dC+dB}, {0, r_H+dC+dB}});
			op.final_shape.V.push_back({w, r_H});
			op.final_shape.V.push_back({w, r_H+dB+dC});
			r_H += dB+dC;
			ret.H.push_back(dB+dC);
			ret.W.push_back(w);
			V.erase(begin(V)+i);
			break;
		}
	}
	op.final_shape.V.push_back({0, r_H});
	ops.push_back(op);
	return ret;
}

RectangleSequence normalise_rectangles(RectangleSequence s, vector<OperationPair> & ops) {
	int N = s.size();
	vector<xy_t> & H = s.H;
	vector<xy_t> & W = s.W;
	xy_t area = 0;
	for(int i = 0; i < N; i++) area += H[i]*W[i];
	xy_t a = sqrt(area);
	while(true) {
		RectangleSequence nxt;
		xy_t cur_H = 0, new_H = 0;
		OperationPair op;
		op.start_shape = ops.back().final_shape;
		op.final_shape = {{0, 0}};
		bool stop = true;
		for(int i = 0; i < N; i++) {
			if(W[i] < a-eps) {
				stop = false;
				op.parts_first.push_back({{0, cur_H}, {W[i], cur_H}, {W[i], cur_H+H[i]/2}, {0, cur_H+H[i]/2}});
				op.parts_moved.push_back({{0, new_H}, {W[i], new_H}, {W[i], new_H+H[i]/2}, {0, new_H+H[i]/2}});
				op.parts_first.push_back({{0, cur_H+H[i]/2}, {W[i], cur_H+H[i]/2}, {W[i], cur_H+H[i]}, {0, cur_H+H[i]}});
				op.parts_moved.push_back({{W[i], new_H}, {2*W[i], new_H}, {2*W[i], new_H+H[i]/2}, {W[i], new_H+H[i]/2}});
				op.final_shape.V.push_back({2*W[i], new_H});
				op.final_shape.V.push_back({2*W[i], new_H+H[i]/2});
				new_H += H[i]/2;
				nxt.W.push_back(W[i]*2);
				nxt.H.push_back(H[i]/2);
			}
			else if(W[i] > 2*a+eps) {
				stop = false;
				op.parts_first.push_back({{0, cur_H}, {W[i]/2, cur_H}, {W[i]/2, cur_H+H[i]}, {0, cur_H+H[i]}});
				op.parts_moved.push_back({{0, new_H}, {W[i]/2, new_H}, {W[i]/2, new_H+H[i]}, {0, new_H+H[i]}});
				op.parts_first.push_back({{W[i]/2, cur_H}, {W[i], cur_H}, {W[i], cur_H+H[i]}, {W[i]/2, cur_H+H[i]}});
				op.parts_moved.push_back({{0, new_H+H[i]}, {W[i]/2, new_H+H[i]}, {W[i]/2, new_H+2*H[i]}, {0, new_H+2*H[i]}});
				op.final_shape.V.push_back({W[i]/2, new_H});
				op.final_shape.V.push_back({W[i]/2, new_H+2*H[i]});
				new_H += H[i]*2;
				nxt.W.push_back(W[i]/2);
				nxt.H.push_back(H[i]*2);
			}
			else {
				op.parts_first.push_back({{0, cur_H}, {W[i], cur_H}, {W[i], cur_H+H[i]}, {0, cur_H+H[i]}});
				op.parts_moved.push_back({{0, new_H}, {W[i], new_H}, {W[i], new_H+H[i]}, {0, new_H+H[i]}});
				op.final_shape.V.push_back({W[i], new_H});
				op.final_shape.V.push_back({W[i], new_H+H[i]});
				new_H += H[i];
				nxt.W.push_back(W[i]);
				nxt.H.push_back(H[i]);
			}
			cur_H += H[i];
		}
		op.final_shape.V.push_back({0, new_H});
		ops.push_back(op);
		s = nxt;
		if(stop) break;
	}
	return s;
}

void rectangles_to_unit_rectangle(RectangleSequence s, vector<OperationPair> & ops) {
	int N = s.size();
	xy_t cur_H = 0, nxt_H = 0;
	OperationPair op;
	op.start_shape = ops.back().final_shape;
	vector<xy_t> & H = s.H;
	vector<xy_t> & W = s.W;
	xy_t area = 0;
	for(int i = 0; i < N; i++) area += H[i]*W[i];
	xy_t a = sqrt(area);
	for(int i = 0; i < N; i++) {
		if(W[i] < a+eps) {
			op.parts_first.push_back({{0, cur_H}, {W[i], cur_H}, {W[i], cur_H+H[i]}, {0, cur_H+H[i]}});
			op.parts_moved.push_back({{0, nxt_H}, {1, nxt_H}, {1, nxt_H+H[i]}, {0, nxt_H+H[i]}});
			cur_H += H[i];
			nxt_H += H[i];
			continue;
		}
		xy_t d = W[i]-a;
		xy_t hr = H[i]/a;
		op.parts_first.push_back({{0, cur_H}, {a, cur_H}, {0, cur_H+H[i]}});
		op.parts_moved.push_back({{0, nxt_H}, {a, nxt_H}, {0, nxt_H+H[i]}});
		op.parts_first.push_back({{0, cur_H+H[i]}, {d, cur_H+H[i]-d*hr}, {d, cur_H+H[i]}});
		op.parts_moved.push_back({{a-d, nxt_H+d*hr}, {a, nxt_H}, {a, nxt_H+d*hr}});
		op.parts_first.push_back({{d, cur_H+H[i]}, {d, cur_H+H[i]-d*hr}, {a, cur_H}, {W[i], cur_H}, {W[i], cur_H+H[i]}});
		op.parts_moved.push_back({{0, nxt_H+W[i]*hr}, {0, nxt_H+H[i]}, {a-d, nxt_H+d*hr}, {a, nxt_H+d*hr}, {a, nxt_H+W[i]*hr}});
		cur_H += H[i];
		nxt_H += W[i]*H[i]/a;
	}
	op.final_shape = {{0, 0}, {a, 0}, {a, nxt_H}, {0, nxt_H}};
	ops.push_back(op);
}

vector<OperationPair> solve(Shape start_shape) {
	// start_shape -> [1 x L] nice rectangle
	vector<OperationPair> ret;
	RectangleSequence rs = triangulate_to_rectangles(start_shape, ret);
	RectangleSequence rs_norm = normalise_rectangles(rs, ret);
	rectangles_to_unit_rectangle(rs_norm, ret);
	return ret;
}

Shape read_shape() {
	int N;
	cin >> N;
	Shape ret(N);
	for(int i = 0; i < N; i++) cin >> ret.V[i].x >> ret.V[i].y;
	return ret;
}

Shape clean_shape(Shape s) {
	vector<Point> V_clean{s.V[0]};
	int N = s.size();
	for(int i = 1; i < N; i++)
		if(sqrt(dot(s.V[i]-s.V[i-1], s.V[i]-s.V[i-1])) > eps)
			V_clean.push_back(s.V[i]);
	return Shape(V_clean);
}

void print_shape(Shape s) {
	s = clean_shape(s);
	cout << s.V.size();
	for(auto p : s.V) cout << " " << p.x << " " << p.y;
	cout << "\n";
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	Shape start = read_shape();
	Shape target = read_shape();
	vector<OperationPair> op1 = solve(start), op2 = solve(target);
	op2 = invert(op2);
	op1.insert(end(op1), begin(op2), end(op2));
	int current_id = 0;
	for(auto p : op1) {
		cout << "scissors\n";
		cout << current_id << " " << p.parts_first.size() << "\n";
		for(auto s : p.parts_first) print_shape(s);
		int new_id = current_id+p.parts_first.size()+1;
		cout << "tape\n";
		cout << p.parts_moved.size();
		for(int i = current_id+1; i < new_id; i++) cout << " " << i;
		cout << "\n";
		for(auto s : p.parts_moved) print_shape(s);
		print_shape(p.final_shape);
		current_id = new_id;
	}
	return 0;
}

// look at my code
// my code is amazing