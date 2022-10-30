#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; i++)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; i--)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int N = 303;

struct op{
	int x1, y1, x2, y2;
};

vector<op> out;
string must[N][N];
string init[N][N];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	F(i, 0, n){
		F(j, 0, m)cin >> init[i][j];
	}
	F(i, 0, n){
		F(j, 0, m)cin >> must[i][j];
	}
	F(j, 1, m){
		int L = (int)init[0][j].length();
		DF(k, L - 1, 0){
			if(init[0][j][k] == '0'){
				out.pb(op{0, j, 0, 0});
			}
			else{
				if(j == 1){out.pb(op{0, j, 1, 1});}
				else{
					out.pb(op{0, j, 0, 1});
					out.pb(op{0, 1, 1, 1});
				}
			}
		}
	}
	F(j, 2, m){
		int L = (int)init[1][j].length();
		DF(k, L - 1, 0){
			if(init[1][j][k] == '0'){
				out.pb(op{1, j, 0, j});
				out.pb(op{0, j, 0, 0});
			}
			else{
				out.pb(op{1, j, 1, 1});
			}
		}
	}
	F(i, 2, n){
		F(j, 2, m){
			int L = (int)init[i][j].length();
			DF(k, L - 1, 0){
				if(init[i][j][k] == '0'){
					out.pb(op{i, j, 0, j});
					out.pb(op{0, j, 0, 0});
				}
				else{
					out.pb(op{i, j, 1, j});
					out.pb(op{1, j, 1, 1});
				}
			}
		}	
	}
	F(i, 1, n){
		int L = (int)init[i][0].length();
		DF(k, L - 1, 0){
			if(init[i][0][k] == '0'){
				out.pb(op{i, 0, 0, 0});
			}
			else{
				if(i == 1){out.pb(op{i, 0, 1, 1});}
				else{
					out.pb(op{i, 0, 1, 0});
					out.pb(op{1, 0, 1, 1});
				}
			}
		}
	}
	F(i, 2, n){
		int L = (int)init[i][1].length();
		DF(k, L - 1, 0){
			if(init[i][1][k] == '0'){
				out.pb(op{i, 1, i, 0});
				out.pb(op{i, 0, 0, 0});
			}
			else{
				out.pb(op{i, 1, 1, 1});
			}
		}
	}
	F(c, 0, 1){
		int L = (int)init[0][0].length();
		DF(k, L - 1, 0){
			if(init[0][0][k] == '0'){
				out.pb(op{0, 0, 1, 0});
				out.pb(op{1, 0, 0, 0});
			}
			else{
				out.pb(op{0, 0, 1, 0});
				out.pb(op{1, 0, 1, 1});
			}
		}
	}
	F(c, 0, 1){
		int L = (int)init[1][1].length();
		DF(k, L - 1, 0){
			if(init[1][1][k] == '0'){
				out.pb(op{1, 1, 1, 0});
				out.pb(op{1, 0, 0, 0});
			}
			else{
				out.pb(op{1, 1, 1, 0});
				out.pb(op{1, 0, 1, 1});
			}
		}
	}
	//SECOND HALF
	DF(j, m - 1, 2){
		DF(i, n - 1, 1){
			int L = (int)must[i][j].length();
			DF(k, L - 1, 0){
				if(must[i][j][k] == '0'){
					out.pb(op{0, 0, 0, j});
					out.pb(op{0, j, i, j});
				}
				else{
					if(i == 1){out.pb(op{1, 1, 1, j});}
					else{
						out.pb(op{1, 1, 1, j});
						out.pb(op{1, j, i, j});
					}
				}
			}
		}
	}
	DF(j, m - 1, 1){
		int L = (int)must[0][j].length();
		DF(k, L - 1, 0){
			if(must[0][j][k] == '0')
				out.pb(op{0, 0, 0, j});
			else{
				if(j == 1)out.pb(op{1, 1, 0, 1});
				else{
					out.pb(op{1, 1, 0, 1});
					out.pb(op{0, 1, 0, j});
				}
			}
		}
	}
	DF(i, n - 1, 2){
		int L = (int)must[i][1].length();
		DF(k, L - 1, 0){
			if(must[i][1][k] == '0'){
				out.pb(op{0, 0, i, 0});
				out.pb(op{i, 0, i, 1});
			}
			else
				out.pb(op{1, 1, i, 1});
		}
	}
	DF(i, n - 1, 2){
		int L = (int)must[i][0].length();
		DF(k, L - 1, 0){
			if(must[i][0][k] == '0'){
				out.pb(op{0, 0, i, 0});
			}
			else{
				out.pb(op{1, 1, 1, 0});
				out.pb(op{1, 0, i, 0});
			}
		}
	}
	F(c, 0, 1){
		int L = (int)must[0][0].length();
		DF(k, L - 1, 0){
			if(must[0][0][k] == '0'){
				out.pb(op{0, 0, 1, 0});
				out.pb(op{1, 0, 0, 0});
			}
			else{
				out.pb(op{1, 1, 1, 0});
				out.pb(op{1, 0, 0, 0});
			}
		}
	}
	F(c, 0, 1){
		int L = (int)must[1][1].length();
		DF(k, L - 1, 0){
			if(must[1][1][k] == '0'){
				out.pb(op{0, 0, 1, 0});
				out.pb(op{1, 0, 1, 1});
			}
			else{
				out.pb(op{1, 1, 1, 0});
				out.pb(op{1, 0, 1, 1});
			}
		}
	}
	F(c, 0, 1){
		int L = (int)must[1][0].length();
		DF(k, L - 1, 0){
			if(must[1][0][k] == '0')out.pb(op{0, 0, 1, 0});
			else out.pb(op{1, 1, 1, 0});
		}
	}
	cout << out.size() << endl;
	I(x, out){
		cout << x.x1 + 1 << " " << x.y1 + 1 << " " << x.x2 + 1 << " " << x.y2 + 1 << '\n';
	}
	return 0;
}