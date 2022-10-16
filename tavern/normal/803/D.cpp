//orz dxm
#include<bits/stdc++.h>

using namespace std;

#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int maxn = 1e6 + 5;

int m;
vector<string> vec;

inline void process(string &buf){
	string res = "";
	buf += '.';
	for(int i = 0; i < buf.size(); ++i){
		res += buf[i];
		if(buf[i] == '-' or buf[i] == '.'){
			vec.PB(res);
			res = "";
		}
	}
	return;
}

inline bool check(int md){
	//cout << "md = " << md << endl;
	int res = 0, ret = 0;
	FOR(i, 0, vec.size()){
		if(vec[i].size() > md) return false;
		if(res + vec[i].size() > md){
			res = 0, ++ret;
			//cout << endl;
		}
		res += vec[i].size();
		//cout << vec[i];
	}
	if(ret + 1 > m) return false;
	return true;
}

int main(){
	cin >> m;
	string buf;
	while(cin >> buf) process(buf);
	buf = vec.back();
	vec.pop_back();
	vec.PB(buf.substr(0, buf.size() - 1));
	int lb = -1, rb = maxn;
	for(; lb + 1 < rb; ){
		int md = lb + rb >> 1;
		if(check(md)) rb = md;
		else lb = md;
	}
	cout << rb << endl;
	return 0;
}