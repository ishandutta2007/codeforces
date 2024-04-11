#include <bits/stdc++.h>
using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef complex<double> point;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define DEBUG 1
#define dout if(DEBUG) cout


const int MAXN = 1e5 + 5;
const int D = 10;
const int MAXSIZE = 100;
typedef int digit;
const digit BASE = 10000;
#define BASE_OUTPUT "%04d"


struct BigInt{
	int size;
	digit m[MAXSIZE];
	BigInt(){
		make_zero();
	}

	void make_zero(){
		size = 0;
	}

	void make_one(){
		m[0] = 1;
		size = 1;
	}

	void make_digit(int big_digit) {
        m[0] = big_digit;
        size = 1;
    }

	void recalc_size(int lim){
		int i;
		for(i = lim - 1; i >= 0 && !m[i]; i--);
		size = i + 1;
	}

	void output(){
		if (size == 0){
			//printf("0\n");
			cout << 0 << endl;
			return;
		}
		//printf("%d", m[size - 1]);
		cout << m[size - 1];
		for(int i = size - 2; i >= 0; i--){
			//printf(BASE_OUTPUT, m[i]);
			cout << m[i];
		}
		cout << endl;
	}
};

vector<int> g[D];
vector<int> last_digit_if_not_used[D];
int lim_of_deleted[D] = {0, 0, 3, 3, 1, 0, 0, 3, 3, 1};
int d;
vi ans;

bool can_get_last_digit;
BigInt min_not_used_mul;
int opt_not_used[D];
int cur_not_used[D];
bool dont_look[D];

BigInt operator * (const BigInt &a, const digit v){
	BigInt ans;
	if (v == 0){
		ans.make_zero();
		return ans;
	}
	int i;
	digit t = 0;
	for(i = 0; i < a.size; i++){
		ans.m[i] = a.m[i] * v + t;
		t = ans.m[i] / BASE;
		ans.m[i] %= BASE;
	}
	ans.m[i] = t;
	if (t == 0){
		ans.size = i;
	}
	else {
		ans.size = i + 1;
	}
	return ans;
}

bool operator < (const BigInt &a, const BigInt &b){
	if (a.size < b.size) return 1;
	if (a.size > b.size) return 0;
	for (int i = a.size - 1; i >= 0; i--) {
        if (a.m[i] < b.m[i]) return 1;
        if (a.m[i] > b.m[i]) return 0;
	}
	return 0;
}


void rec_sol(int cur_digit, int last_of_taken, BigInt &deleted_mul) {
//    dout << cur_digit << " " << last_of_taken << " ";
//    deleted_mul.output();
//    dout << "!";
//    min_not_used_mul.output();
//    dout << "\n";
    if (cur_digit == 10) {
        if (last_of_taken == d) {
            if (!can_get_last_digit || deleted_mul < min_not_used_mul) {
                can_get_last_digit = 1;
                min_not_used_mul = deleted_mul;
                for (int i = 0; i < D; i++) {
                    opt_not_used[i] = cur_not_used[i];
                }
            }
        }
        return;
    }
    if (dont_look[cur_digit] || g[cur_digit].empty()) {
        rec_sol(cur_digit + 1, last_of_taken, deleted_mul);
        return;
    }

    BigInt ndeleted_mul = deleted_mul;
    int nlim = last_digit_if_not_used[cur_digit].size();
    for (int delete_cnt = 0; delete_cnt < nlim; delete_cnt++) {
        cur_not_used[cur_digit] = delete_cnt;
        int nlast_of_taken = last_of_taken == -1 ?
            last_digit_if_not_used[cur_digit][delete_cnt] :
            (last_of_taken * last_digit_if_not_used[cur_digit][delete_cnt]) % 10;
        rec_sol(cur_digit + 1, nlast_of_taken, ndeleted_mul);
        cur_not_used[cur_digit] = -1;
        if (delete_cnt < (int)g[cur_digit].size()) {
            ndeleted_mul = ndeleted_mul * g[cur_digit][delete_cnt];
        }
    }
}

void solve() {
    int n;
    cin >> n >> d;
    int a;

    int total_last = 1;
    for (int i = 0; i < n; i++) {
        cin >> a;
        int rem = a % D;
        g[rem].pb(a);
        total_last = (total_last * rem) % 10;
    }

    if (d) dont_look[0] = 1;
    if (d & 1) {
        for (int i = 2; i < 10; i += 2) dont_look[i] = 1;
    }
    if (d != 0 && d != 5) {
        dont_look[5] = 1;
    }

    for (int i = 0; i < D; i++) {
        sort(g[i].begin(), g[i].end());
        int cur_digit = 1;
        for (int j = 0; j <= (int)g[i].size(); j++) {
			if (j >= (int)g[i].size() - lim_of_deleted[i]) {
				last_digit_if_not_used[i].pb(cur_digit);
			}
			cur_digit = (cur_digit * i) % 10;
		}
        reverse(last_digit_if_not_used[i].begin(), last_digit_if_not_used[i].end());

//        for (int j = 0; j < (int)last_digit_if_not_used[i].size(); j++) {
//            dout << "#" << i << " " << j << " " << last_digit_if_not_used[i][j] << endl;
//        }
    }
    if (total_last == d) {
        cout << n << endl;
        for (int i = 0; i < D; i++) {
            for (auto num : g[i]) {
                cout << num << " ";
            }
        }
        return;
    }

    can_get_last_digit = 0;
    BigInt mul;
    mul.make_digit(1);
    for (int i = 0; i < D; i++) {
        cur_not_used[i] = -1;
    }
    rec_sol(0, -1, mul);

    if (can_get_last_digit) {
        for (int i = 0; i < D; i++) {
            if (opt_not_used[i] == -1) continue;
            for (int j = opt_not_used[i]; j < (int)g[i].size(); j++) {
                ans.pb(g[i][j]);
            }
        }
        if (ans.empty()) cout << -1;
        else {
            cout << (int)ans.size() << endl;
            for (auto v : ans) {
                cout << v << " ";
            }
        }
    }
    else {
        cout << -1;
    }
}

int main() {
    #ifdef NASTYA
        assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    #else
    // assert(freopen(file".in", "r", stdin)); assert(freopen(file".out", "w", stdout));
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}