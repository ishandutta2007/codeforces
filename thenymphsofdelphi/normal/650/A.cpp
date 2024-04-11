#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second

const int N = 26;

int n, b, c, d, t;
vector <pair <int, int> > a;

bool comp(pair <int, int> x, pair <int, int> y){
	if (x.se < y.se){
		return 1;
	}
	if (x.se > y.se){
		return 0;
	}
	if (x.fi < y.fi){
		return 1;
	}
	return 0;
}

signed main(){
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        a.pb({x, y});
    }
    sort(a.begin(), a.end());
    t = 1;
    for (int i = 1; i < a.size(); i++){
        if (a[i].fi != a[i - 1].fi){
            b += t * (t - 1) / 2;
            t = 1;
        }
        else{
            t++;
        }
    }
    b += t * (t - 1) / 2;
	sort(a.begin(), a.end(), comp);
	t = 1;
    for (int i = 1; i < a.size(); i++){
        if (a[i].se != a[i - 1].se){
            c += t * (t - 1) / 2;
            t = 1;
        }
        else{
            t++;
        }
    }
    c += t * (t - 1) / 2;
    t = 1;
    for (int i = 1; i < a.size(); i++){
        if (a[i] != a[i - 1]){
            d += t * (t - 1) / 2;
            t = 1;
        }
        else{
            t++;
        }
    }
    d += t * (t - 1) / 2;
    cout << b + c - d;
}