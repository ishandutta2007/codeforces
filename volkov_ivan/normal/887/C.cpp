#include <iostream>

using namespace std;

int f[2][2], l[2][2], r[2][2], b[2][2], u[2][2], d[2][2];

bool solved() {
	bool ans[6] = {0, 0, 0, 0, 0, 0};
	if (f[0][0] == f[0][1] && f[0][1] == f[1][0] && f[1][0] == f[1][1]) ans[0] = 1;
	if (l[0][0] == l[0][1] && l[0][1] == l[1][0] && l[1][0] == l[1][1]) ans[1] = 1;
	if (r[0][0] == r[0][1] && r[0][1] == r[1][0] && r[1][0] == r[1][1]) ans[2] = 1;
	if (b[0][0] == b[0][1] && b[0][1] == b[1][0] && b[1][0] == b[1][1]) ans[3] = 1;
	if (u[0][0] == u[0][1] && u[0][1] == u[1][0] && u[1][0] == u[1][1]) ans[4] = 1;
	if (d[0][0] == d[0][1] && d[0][1] == d[1][0] && d[1][0] == d[1][1]) ans[5] = 1;
	return (ans[0] & ans[1] & ans[2] & ans[3] & ans[4] & ans[5]);
}

/*void print() {
	cout << u[0][0] << u[0][1] << u[1][0] << u[1][1];
	cout << f[0][0] << f[0][1] << f[1][0] << f[1][1];
	cout << d[0][0] << d[0][1] << d[1][0] << d[1][1];
	cout << l[0][0] << l[0][1] << l[1][0] << l[1][1];
	cout << r[0][0] << r[0][1] << r[1][0] << r[1][1];
	cout << b[0][0] << b[0][1] << b[1][0] << b[1][1];
}*/

void turn_up() {
	int mem1 = f[0][0], mem2 = f[0][1], mem3 = r[0][0], mem4 = r[0][1], mem5 = b[0][0], mem6 = b[0][1], mem7 = l[0][0], mem8 = l[0][1];
	r[0][0] = mem1;
	r[0][1] = mem2;
	b[0][0] = mem3;
	b[0][1] = mem4;
	l[0][0] = mem5;
	l[0][1] = mem6;
	f[0][0] = mem7;
	f[0][1] = mem8;
}

void turn_left() {
	int mem1 = f[0][0], mem2 = f[1][0], mem3 = d[0][0], mem4 = d[1][0], mem5 = b[1][1], mem6 = b[0][1], mem7 = u[0][0], mem8 = u[1][0];
	d[0][0] = mem1;
	d[1][0] = mem2;
	b[1][1] = mem3;
	b[0][1] = mem4;
	u[0][0] = mem5;
	u[1][0] = mem6;
	f[0][0] = mem7;
	f[1][0] = mem8;
}

void turn_front() {
	int mem1 = u[1][0], mem2 = u[1][1], mem3 = r[0][0], mem4 = r[1][0], mem5 = d[0][1], mem6 = d[0][0], mem7 = l[1][1], mem8 = l[0][1];
	r[0][0] = mem1;
	r[1][0] = mem2;
	d[0][1] = mem3;
	d[0][0] = mem4;
	l[1][1] = mem5;
	l[0][1] = mem6;
	u[1][0] = mem7;
	u[1][1] = mem8;
}

bool check_up() {
	bool poss = 0;
	turn_up();
	poss |= solved();
	turn_up();
	turn_up();
	poss |= solved();
	turn_up();
	return poss;
}

bool check_left() {
	bool poss = 0;
	turn_left();
	//print();
	poss |= solved();
	turn_left();
	turn_left();
	//print();
	poss |= solved();
	turn_left();
	return poss;
}

bool check_front() {
	bool poss = 0;
	turn_front();
	poss |= solved();
	turn_front();
	turn_front();
	poss |= solved();
	turn_front();
	return poss;
}

int main() {
	cin >> u[0][0] >> u[0][1] >> u[1][0] >> u[1][1];
	cin >> f[0][0] >> f[0][1] >> f[1][0] >> f[1][1];
	cin >> d[0][0] >> d[0][1] >> d[1][0] >> d[1][1];
	cin >> l[0][0] >> l[0][1] >> l[1][0] >> l[1][1];
	cin >> r[0][0] >> r[0][1] >> r[1][0] >> r[1][1];
	cin >> b[0][0] >> b[0][1] >> b[1][0] >> b[1][1];
	cout << ((check_up() | check_left() | check_front())? "YES" : "NO") << endl;
	return 0;
}