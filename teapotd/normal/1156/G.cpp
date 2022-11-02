#define _USE_MATH_DEFINES
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

constexpr ll MOD = 15*(1<<27)+1;

mt19937 rnd(int(time(0)));

struct Zp {
    ll x;
    Zp(ll a = 0) {
        if (a < 0) a = a%MOD + MOD;
        else if (a >= MOD*2) a %= MOD;
        else if (a >= MOD) a -= MOD;
        x = a;
    }
    Zp operator+(Zp r) const{ return x+r.x; }
    Zp operator-(Zp r) const{ return x-r.x+MOD; }
    Zp operator*(Zp r) const{ return x*r.x; }
    Zp operator/(Zp r) const{return x*r.inv().x;}
    Zp operator-()     const{ return MOD-x; }
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const {
        Zp t = 1, m = *this;
        while (e) {
            if (e & 1) t = t*m;
            e >>= 1; m = m*m;
        }
        return t;
    }
    #define OP(c) Zp& operator c##=(Zp r){ return *this=*this c r; }
    OP(+)OP(-)OP(*)OP(/)
    void print() { cerr << x; }
    bool operator<(Zp r) const { return x < r.x; }
};

struct Info {
    string name;
    Zp a, b;
    char op{'x'};
    bool ok{0};
    DBP(name, a, b, op);
};

const Zp MULT = rnd();
map<Zp, Info> info;
map<string, Zp> vars;
vector<string> ans, names;

void dfs(Zp what, string name) {
    auto& dep = info[what];

    if (!dep.ok) {
        if (name.empty()) {
            name = names.back();
            names.pop_back();
        }

        dep.name = name;
        dep.ok = 1;
        dfs(dep.a, "");
        dfs(dep.b, "");
        ans.pb(name+"="+info[dep.a].name+dep.op+info[dep.b].name);
    } else if (name == "res") {
        ans.pb("res="+dep.name);
    }
}

void run() {
    int n; cin >> n;

    auto getVar = [&](const string& name) {
        if (vars.count(name)) {
            return vars[name];
        }
        Zp key = rnd();
        vars[name] = key;
        info[key].name = name;
        info[key].ok = 1;
        return key;
    };

    auto combine = [&](const string& a, const string& b, char op) {
        Zp va = getVar(a), vb = getVar(b);
        Zp ret = (va*MULT + vb)*MULT + op;
        info[ret].a = va;
        info[ret].b = vb;
        info[ret].op = op;
        return ret;
    };

    rep(i, 0, n) {
        string line; cin >> line;
        int sep = int(line.find("="));
        string dst = line.substr(0, sep), rest = line.substr(sep+1);
        sep = -1;

        rep(j, 0, sz(rest)) {
            char c = rest[j];
            if (c == '$' || c == '^' || c == '#' || c == '&') {
                sep = j;
                break;
            }
        }

        if (sep == -1) {
            if (dst != rest) vars[dst] = getVar(rest);
        } else {
            string a = rest.substr(0, sep), b = rest.substr(sep+1);
            char op = rest[sep];
            vars[dst] = combine(a, b, op);
        }
    }

    rep(i, 0, 26) rep(j, 0, 26) rep(k, 0, 26) rep(l, 0, 26) {
        string name = {char(i+'a'), char(j+'a'), char(k+'a'), char(l+'a')};
        if (vars.count(name)) continue;
        names.pb(name);
        if (sz(names) >= 20000) {
            goto done;
        }
    }

done:
    if (vars.count("res") && info[vars["res"]].name != "res") {
        dfs(vars["res"], "res");
    }

    cout << sz(ans) << '\n';
    each(a, ans) cout << a << '\n';
}