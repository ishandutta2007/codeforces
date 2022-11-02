#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
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
typedef double dbl;
typedef pair <int, int> pii;

const int N = 1<<15;

int f[N];
int x;
int ans = -1;
deque<string> found;
string condl[N], condr[N], retrn[N];
int sgn[N];
int sz = 0;

int add(int x, int y){
	return ((x + y)%N+N)%N;
}

int sub(int x, int y){
	return ((x - y)%N + N)%N;
}

int mul(int x, int y){
	return (x * y % N + N)%N;
}

#define div ddjfnf

int div(int x, int y){
	return x/y;
}

void parse(){
	cin >> x;
	string s;
	getline(cin, s);
	int state = 0;
	bool finished = 1;
	while(1){
		if(cin.eof())
			break;
		getline(cin, s);
		if(!state){
			size_t pos = s.find_first_of('{');
			if(pos != string::npos){
				state = 1;
				s = s.substr(pos + 1);
			}
		}
		if(state){
			size_t pos = s.find_first_of('}');
			if(pos != string::npos){
				s = s.substr(0, pos);
				state = 2;
			}
		}
		if(!state)
			continue;
		if(s.empty())
			continue;
		size_t pos = 0;
		while(1){
			size_t old = pos;
			pos = s.find_first_of(';', pos);
			if(pos == string::npos){
				if(finished)
					found.push_back(s.substr(old));
				else{
					found.back() += s.substr(old);
				}
				finished = 0;
				break;
			}
			if(finished)
				found.push_back(s.substr(old, pos - old));
			else
				found.back() += s.substr(old, pos - old);
			++pos;
			if(pos >= s.length()){
				finished = 1;
				break;
			}
		}
		if(state == 2)
			break;
	}
}

void prepare(){
	for(const auto & s : found){
		size_t kek = s.find("if");
		if(kek == string::npos){
			sgn[sz] = 228;
			kek = s.find("return");
			retrn[sz] = s.substr(kek + 6);
			++sz;
			continue;
		}
		kek = s.find_first_of('(', kek);
		int bal = 0;
		size_t lol;
		for(size_t i = kek; i < s.length(); i++){
			if(s[i] == '(')++bal;
			if(s[i] == ')')--bal;
			if(bal == 0){
				lol = i;
				break;
			}
		}
		size_t ss = s.find_first_of('<', kek);
		if(ss != string::npos){
			sgn[sz] = -1;
			condl[sz] = s.substr(kek + 1, ss - kek - 1);
			condr[sz] = s.substr(ss + 1, lol - ss - 1);
			kek = s.find("return");
			retrn[sz] = s.substr(kek + 6);
			++sz;
			continue;
		}
		ss = s.find_first_of('>', kek);
		if(ss != string::npos){
			sgn[sz] = 1;
			condl[sz] = s.substr(kek + 1, ss - kek - 1);
			condr[sz] = s.substr(ss + 1, lol - ss - 1);
			kek = s.find("return");
			retrn[sz] = s.substr(kek + 6);
			++sz;
			continue;
		}
		ss = s.find_first_of('=', kek);
		if(ss != string::npos){
			sgn[sz] = 0;
			condl[sz] = s.substr(kek + 1, ss - kek - 1);
			condr[sz] = s.substr(ss + 2, lol - ss - 2);
			kek = s.find("return");
			retrn[sz] = s.substr(kek + 6);
			++sz;
			continue;
		}
		assert(0);
	}
}

int eval(const string & s, int n){
	int bal = 0;
	int value = 0;
	int lastz = 0;
	char op = ' ';
	bool isn = false;
	vector<pair<char, int> > nums;
	F(i, 0, (int)s.length()){
		if(!isdigit(s[i]) && isn){
			nums.pb({op, value});
			isn = 0;
			value = 0;
		}
		if(s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r')
			continue;
		if(s[i] == '('){
			if(!bal)
				lastz = i;
			++bal;
			continue;
		}
		if(s[i] == ')'){
			--bal;
			if(!bal){
				int cnum = f[eval(s.substr(lastz + 1, i - lastz - 1), n)];
				nums.pb({op, cnum});
			}
			continue;
		}
		if(bal)
			continue;
		if(s[i] == 'n'){
			nums.pb({op, n});
			continue;
		}
		if(s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '-')
			op = s[i];
		if(isdigit(s[i])){
			isn = 1;
			value = value * 10 + (s[i] - '0');
		}
	}
	if(isn)
		nums.pb({op, value});
	value = 0;
	int prev = 0;
	vector<char> alive(nums.size(), 1);
	int k = nums.size();
	F(i, 1, k){
		if(nums[i].X == '+' || nums[i].X == '-'){prev = i; continue;}
		alive[i] = 0;
		if(nums[i].X == '*')
			nums[prev].Y = mul(nums[prev].Y, nums[i].Y);
		else
			nums[prev].Y = div(nums[prev].Y, nums[i].Y);
	}
	F(i, 1, k){
		if(!alive[i])continue;
		if(nums[i].X == '+')
			nums[0].Y = add(nums[0].Y, nums[i].Y);
		else
			nums[0].Y = sub(nums[0].Y, nums[i].Y);
	}
	//cout << "from " << s << " got " << nums[0].Y << " n = " << n << endl;
	return nums[0].Y;
}

void solve(int n){
	F(i, 0, sz){
		if(sgn[i] == 228){
			f[n] = eval(retrn[i], n);
			return;
		}
		int l = eval(condl[i], n), r = eval(condr[i], n);
		if((sgn[i] == -1 && l < r) || (sgn[i] == 0 && l == r) || (sgn[i] == 1 && l > r)){
			f[n] = eval(retrn[i], n);
			return;
		}
	}
	assert(0);
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sync;
	parse();
	prepare();
	/*F(i, 0, sz){
		cerr << condl[i] << " | " << sgn[i] << " | " << condr[i] << " | " << retrn[i] << endl;
	}*/
	for(int i = 0; i < N; i++){
		solve(i);
		if(f[i] == x)
			ans = i;
	}
	cout << ans;
	return 0;
}