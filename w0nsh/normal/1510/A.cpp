#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct Box {
	int h, w;
	std::vector<char> data;
	Box() : h(0), w(0) {}
	Box(int h_, int w_) : h(h_), w(w_), data(h_*w_, ' ') {}

	char& operator()(int y, int x) {
		return data[y*w + x];
	}
	const char& operator()(int y, int x) const {
		return data[y*w + x];
	}

	friend std::ostream& operator<<(std::ostream& stream, const Box& box) {
		FOR(i, box.h){
			FOR(j, box.w){
				stream << box(i, j);
			}
			stream << "\n";
		}
		return stream;
	}
};

bool is_letter(char a){
	return a >= 'A' && a <= 'Z';
}

bool is_special(char a){
	return a == '+' || a == '*' || a == '?';
}

Box apply_plus(Box b) {
	Box box(b.h + 2, b.w + 6);
	box(1, 0) = box(1, box.w-1) = box(box.h-1, box.w-1) = box(box.h-1, 0) = '+';
	REP(i, 2, box.h-1) box(i, 0) = box(i, box.w-1) = '|';
	box(box.h-1, 1) = '<';
	REP(i, 2, box.w-1) box(box.h-1, i) = '-';
	box(1, 1) = '-';
	box(1, 2) = '>';
	box(1, box.w-2) = '>';
	box(1, box.w-3) = '-';
	FOR(i, b.h){
		FOR(j, b.w){
			box(i, 3 + j) = b(i, j);
		}
	}
	return box;
}

Box apply_question(Box b) {
	Box box(b.h + 3, b.w + 6);
	box(1, 0) = box(1, box.w-1) = box(4, box.w-1) = box(4, 0) = '+';
	box(2, 0) = box(3, 0) = box(2, box.w-1) = box(3, box.w-1) = '|';

	box(4, 1) = '-';
	box(4, 2) = '>';
	box(4, 3 + b.w) = '-';
	box(4, 3 + b.w + 1) = '>';
	REP(i, 1, box.w-2) box(1, i) = '-';
	box(1, box.w-2) = '>';

	FOR(i, b.h){
		FOR(j, b.w){
			box(3 + i, 3 + j) = b(i, j);
		}
	}
	return box;
}

Box apply_mult(Box b) {
	Box box(b.h + 5, b.w + 6);
	REP(i, 2, box.h-1) box(i, 0) = box(i, box.w-1) = '|';
	box(1, 0) = box(1, box.w-1) = box(4, box.w-1) = box(4, 0) = '+';

	box(4, 1) = '-';
	box(4, 2) = '>';
	box(4, 3 + b.w) = '-';
	box(4, 3 + b.w + 1) = '>';
	REP(i, 1, box.w-2) box(1, i) = '-';
	box(1, box.w-2) = '>';

	FOR(i, b.h){
		FOR(j, b.w){
			box(3 + i, 3 + j) = b(i, j);
		}
	}

	box(box.h-1, 0) = box(box.h-1, box.w-1) = '+';
	box(box.h-2, 0) = box(box.h-3, 0) = box(box.h-2, box.w-1) = box(box.h-3, box.w-1) = '|';
	REP(i, 2, box.w-1) box(box.h-1, i) = '-';
	box(box.h-1, 1) = '<';
	return box;
}

Box join_term(const std::vector<Box>& vec){
	int mx = 0;
	int ws = 0;
	TRAV(i, vec) mx = std::max(mx, i.h), ws += i.w;
	Box box(mx, ws + (SZ(vec)-1)*2);
	int off = 0;
	FOR(ind, SZ(vec)){
		auto& b = vec[ind];
		FOR(i, b.h){
			FOR(j, b.w){
				box(i, off+j) = b(i, j);
			}
		}
		if (ind == SZ(vec) - 1) break;
		off += b.w;
		box(1, off) = '-';
		off++;
		box(1, off) = '>';
		off++;
	}
	return box;
}

Box join_expr(const std::vector<Box>& vec){
	if(SZ(vec) == 1) return vec[0];

	int mx = 0;
	int hs = 0;
	TRAV(i, vec) mx = std::max(mx, i.w), hs += i.h;
	Box box(hs + SZ(vec)-1, mx + 6);

	int last_h = hs + SZ(vec) - vec.back().h;
	REP(i, 1, last_h){
		box(i, 0) = box(i, box.w-1) = '|';
	}

	int off = 0;
	FOR(ind, SZ(vec)){
		auto& b = vec[ind];
		FOR(i, b.h){
			FOR(j, b.w){
				box(off + i, 3 + j) = b(i, j);
			}
		}
		box(off + 1, 0) = '+';
		box(off + 1, 1) = '-';
		box(off + 1, 2) = '>';
		REP(j, 3 + b.w, box.w) box(off + 1, j) = '-';
		box(off + 1, box.w - 2) = '>';
		box(off + 1, box.w - 1) = '+';

		off += b.h + 1;
	}

	return box;
}

Box letter_box(std::string str) {
	int n = SZ(str);
	auto box = Box(3, 4 + n);
	FOR(i, 3) box(i, 0) = box(i, n+3) = '+';
	REP(i, 1, n+3) box(0, i) = box(2, i) = '-';
	REP(i, 2, n+2) {
		box(1, i) = str[i-2];
	}
	return box;
}

Box parse_expr(std::string);


Box parse_atom(std::string atom) {
	assert(SZ(atom));
	if (is_special(atom.back())){
		std::string xd = atom;
		xd.pop_back();
		assert(SZ(xd));
		auto box = parse_atom(xd);
		switch(atom.back()){
			case '+':
				return apply_plus(box);
			case '?':
				return apply_question(box);
			case '*':
				return apply_mult(box);
			default:
				assert(false);
		}
		assert(false);
	}
	if (is_letter(atom[0])) {
		assert(is_letter(atom.back()));
		return letter_box(atom);
	}

	assert(atom[0] == '(' && atom.back() == ')');
	atom = atom.substr(1);
	atom.pop_back();
	return parse_expr(atom);
}

Box parse_term(std::string term) {
	std::vector<Box> vec;

	std::string have;
	std::vector<std::string> dv;
	int hehe = 0;
	FOR(i, SZ(term)) {
		if(term[i] == '(') hehe++;
		else if(term[i] == ')') hehe--;

		if(term[i] == '(' && hehe == 1) {
			if(SZ(have)) dv.push_back(have);
			have = "(";
			continue;
		}

		if(hehe >= 1) {
			have.push_back(term[i]);
			continue;
		}

		if(term[i] == ')'){
			have += ")";
			dv.push_back(have);
			have = "";
			continue;
		}

		if(is_special(term[i])){
			if((SZ(have) == 0) || (SZ(have) && is_special(have.back()))){
				have.push_back(term[i]);
				continue;
			}
			dv.push_back(have);
			have = "";
			have.push_back(term[i]);
			continue;
		}

		assert(is_letter(term[i]));
		if((SZ(have) == 0) || (SZ(have) && is_letter(have.back()))){
			have.push_back(term[i]);
			continue;
		}
		dv.push_back(have);
		have = "";
		have.push_back(term[i]);
	}

	if(SZ(have)) dv.push_back(have);

	// CHECK
	TRAV(xd, dv){
		assert(SZ(xd));
		if(is_special(xd[0])){
			TRAV(i, xd) assert(is_special(i));
		}else if(is_letter(xd[0])){
			TRAV(i, xd) assert(is_letter(i));
		}else if(xd[0] == '('){
			assert(xd.back() == ')');
		}
	}

	std::vector<std::string> real;
	FOR(i, SZ(dv)){
		if(dv[i] == "$") continue;

		if(is_letter(dv[i].back())){
			if(i+1 < SZ(dv) && is_special(dv[i+1].back())){
				std::string nw = "";
				nw.push_back(dv[i].back());
				dv[i].pop_back();
				if(SZ(dv[i])){
					real.push_back(dv[i]);
				}
				nw += dv[i+1];
				real.push_back(nw);
				dv[i+1] = "$"; // wyjebany
			}else{
				real.push_back(dv[i]);
			}
		}else if(dv[i][0] == '('){
			if(i+1 < SZ(dv) && is_special(dv[i+1].back())){
				dv[i] += dv[i+1];
				real.push_back(dv[i]);
				dv[i+1] = "$"; // wyjebany
			}else{
				real.push_back(dv[i]);
			}
		}else{
			assert(false);
		}
	}

	TRAV(r, real) vec.push_back(parse_atom(r));
	return join_term(vec);
}

Box parse_expr(std::string expr) {
	std::vector<Box> vec;
	std::string have;
	int hehe = 0;
	FOR(i, SZ(expr)){
		if(expr[i] == '(') hehe++;
		else if(expr[i] == ')') hehe--;

		if(expr[i] == '|' && hehe == 0){
			vec.push_back(parse_term(have));
			have = "";
		}else have += expr[i];
	}
	vec.push_back(parse_term(have));
	return join_expr(vec);
}

Box make_input(Box b){
	Box box(b.h, b.w + 6);
	FOR(i, b.h){
		FOR(j, b.w){
			box(i, 3 + j) = b(i, j);
		}
	}
	box(1, 0) = 'S';
	box(1, 1) = '-';
	box(1, 2) = '>';
	box(1, box.w-1) = 'F';
	box(1, box.w-2) = '>';
	box(1, box.w-3) = '-';
	return box;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string s;
	std::cin >> s;
	auto xd = make_input(parse_expr(s));
	std::cout << xd.h << " " << xd.w << std::endl;
	std::cout << xd << std::endl;

	return 0;
}