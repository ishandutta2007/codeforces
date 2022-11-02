#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pt;

#define X first
#define Y second

const int MAXN = 3e3 + 3;

bitset<MAXN> can[MAXN];
int n;
pt p[MAXN];

ll dist(pt a, pt b){return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);}

struct comp{
	bool operator () (const pair<int, int> & l, const pair<int, int> & r)const{
		return (dist(p[l.first], p[l.second]) > dist(p[r.second], p[r.first])) || (dist(p[l.first], p[l.second]) == dist(p[r.second], p[r.first]) && l < r);
	}
};

pair<int, int> s[MAXN * MAXN];

void add(int i, int j){
	can[i].set(j, true);
	can[j].set(i, true);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	int ptr = 0;
	for(int i = 0; i < n; i++){
		can[i].reset();
		scanf("%lld%lld", &p[i].first, &p[i].second);
	}
	for(int i = 0; i < n; i++)for(int j = i + 1; j < n; j++)s[ptr++] = {i, j};
	ll ans = 0;
	sort(s, s + ptr, comp());
	for(int l = 0; l < ptr; l++){
		int i = s[l].first, j = s[l].second;
		if((can[i]&can[j]).any()){
		    ans = dist(p[i], p[j]);
		    printf("%.15lf", (double)sqrt((long double)ans)/2);
		    return 0;
		}
		add(i, j);
	}
	printf("%.15lf", (double)sqrt((long double)ans)/2);
	return 0;
}