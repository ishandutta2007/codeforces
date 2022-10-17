#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<PII> A(n), B(m);
    FOR(i, n) std::cin >> A[i].X >> A[i].Y;
    FOR(i, m) std::cin >> B[i].X >> B[i].Y;

    std::sort(B.begin(), B.end());
    std::vector<PII> C;
    TRAV(i, B){
        while(SZ(C) > 0 && C.back().Y <= i.Y){
            C.pop_back();
        }
        C.push_back(i);
    }

    std::vector<std::vector<PII> > og;
    TRAV(i, A){
        bool was = false;
        TRAV(j, C) if(i.X <= j.X && i.Y <= j.Y) was = true;
        if(!was) continue;

        std::vector<PII> cur;
        auto it = C.begin();
        while(it != C.end() && i.X > it->X) ++it;
        auto jt = C.end();
        while(jt != C.begin()){
            jt--;
            if(i.Y <= jt->Y) break;
        }

        assert(it <= jt);

        cur.push_back(MP(0, it->Y-i.Y+1));

        PII last = *it;
        while(it != jt){
            ++it;

            cur.push_back(MP(last.X-i.X+1, it->Y-i.Y+1));

            last = *it;
        }

        cur.push_back(MP(jt->X-i.X+1, 0));
        og.push_back(std::move(cur));
    }

    if(SZ(og) == 0){
        std::cout << 0 << "\n";
        return 0;
    }

    std::multiset<int> max;
    const int INF = 1000000666;
    VI mam(SZ(og), INF);
    std::vector<PR<int, PII> > ev;
    int ind = 0;
    TRAV(i, og){
        max.insert(INF);
        TRAV(pr, i){
            ev.push_back(MP(pr.X, MP(ind, pr.Y)));
        }
        ind++;
    }

    std::sort(ev.begin(), ev.end());
    int x = 0;
    int ans = INF;
    TRAV(e, ev){
        x = e.X;
        int i = e.Y.X;
        int val = e.Y.Y;
        max.erase(max.find(mam[i]));
        mam[i] = val;
        max.insert(val);

        ans = std::min(ans, x+*std::prev(max.end()));
    }

    std::cout << ans << "\n";

	return 0;
}