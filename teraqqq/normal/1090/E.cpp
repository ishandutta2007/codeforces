#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

const int N = 1000;

typedef long long ll;

int n, kcount, px[8][8], py[8][8];
bool a[8][8], u[8][8];
char s[5];
stringstream ans;

int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

void ppos(ostream& os, int x, int y) {
	os << char(x+'a') << char(y+'1');
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		a[s[0]-'a'][s[1]-'1'] = true;
	}

	for(int k = 0; k < n; ++k) {
		if(a[k%8][k/8]) continue;

		queue<int> qx, qy;
		qx.push(k%8);
		qy.push(k/8);

		for(int i = 0; i < 8; ++i) 
		for(int j = 0; j < 8; ++j)
			u[i][j] = false;
		u[k%8][k/8] = true;
		px[k%8][k/8] = -1;

		vector<int> vx, vy;

		while(!qx.empty()) {
			int cx = qx.front(); qx.pop();
			int cy = qy.front(); qy.pop();


			if(a[cx][cy] && cx+cy*8 > k) {
				// build way

				//ppos(cout, cx, cy);
				//cout << ", " << k << "!" << endl;

				vx.push_back(cx);
				vy.push_back(cy);
				for(int i = cx, j = cy; px[i][j] != -1;) {
					int di = i,  dy = j;
					vx.push_back(i = px[di][dy]);
					vy.push_back(j = py[di][dy]);
				}

				reverse(vx.begin(), vx.end());
				reverse(vy.begin(), vy.end());

				break;
			}

			for(int i = 0; i < 8; ++i) {
				int nx = cx+dx[i], ny = cy+dy[i];
				if(check(nx, ny) && !u[nx][ny]) {
					u[cx+dx[i]][cy+dy[i]] = true;
					qx.push(nx); px[nx][ny] = cx;
					qy.push(ny); py[nx][ny] = cy;
				}
			}
		}

		int to = 0;
		for(int i = 1; i < vx.size(); ++i) {
			int cx = vx[i], cy = vy[i];
			if(a[cx][cy]) {
				for(int j = i; j != to; --j) {
					a[cx][cy] = false;
					ppos(ans, cx, cy); ans << '-';
					//ppos(cout, cx, cy); cout << '-';
					cx = vx[j-1];
					cy = vy[j-1];
					ppos(ans, cx, cy); ans << endl;
					//ppos(cout, cx, cy); cout << endl;
					++kcount;
					a[cx][cy] = true;

/*
					for(int i = 7; i >= 0; --i) {
						for(int j = 0; j < 8; ++j)
							cout << (i==cx && j == cy ? 'O' : a[i][j] ? 'X' : '.');
						cout << endl;
					}
					cout << endl;
*/
				}
				to = i;
			}
		}
	}

	cout << kcount << endl << ans.str();
}