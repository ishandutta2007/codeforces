#include<bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define sz(s) (int)s.size()
#define pb push_back
#define all(s) s.begin(), s.end()
#define vi vector<int>

#define ll long long
#define ld long double
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>

const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int mod = 998244353;
const int T = (1 << 20);

string s;
int n;
int min_shift = N;

bool wypelnij_blokami(int pocz, int kon, int shift, vi & ans){
    int dl = kon - pocz - 1;
    if(dl == -1)
        return true;
    if(dl < -1)
        return false;
    if(dl == 0)
        return false;
    if(dl % 2 == 0){
        if(shift <= 1)
            return false;
        ans.pb(2);
        dl -= 3;
    }
    while(dl > -1){
        if(shift == 0)
            return false;
        dl -= 2;
        ans.pb(1);
    }
    return true;
}

vi zgadnij_shift(int shift){
    // cout << "ZGADUJE SHIFT  " << shift << endl;
    vi ans;
    int koniec_ost = -2;
    for(int i = 0; i < n; i++){
        if(s[i] == '#' and (i == 0 or s[i - 1] == '_')){
            int dl = 0;
            for(int j = i; j < n; j++)
                if(s[j] == '#')
                    dl++;
                else
                    break;
            // cout << "DLUGOSC " << endl;
            if(!wypelnij_blokami(koniec_ost + 1, i - 1 - shift, shift, ans))
                return {};
            ans.pb(dl + shift);
            koniec_ost = i + dl - 1;
            // cout << "DODAJE " << i << ' ' << koniec_ost << endl;
        }
    }
    // cout << "KONIEC OSTATNIEGO " << koniec_ost << endl;
    if(!wypelnij_blokami(koniec_ost + 1, n - shift, shift, ans))
        return {};
    // cout << "DZIAA DLA SHIFTA: " << shift << endl;
    return ans;
}   

string wspolne_pola(vi siema){
    string ret;
    int suma_dl = 0;
    for(auto & u : siema)
        suma_dl += u + 1;
    if(suma_dl == 0){
        for(int i = 0; i < n; i++)
            ret.pb('_');
        return ret;
    }

    int shift = n + 1 - suma_dl;
    // clog << "SUMA  " << n << ' ' << suma_dl << ' ' << shift << endl;
    for(auto & u : siema){
        if(u < shift){
            for(int i = 0; i < u + 1; i++)
                ret.pb('_');
        }
        else{
            for(int i = 0; i < shift; i++)
                ret.pb('_');
            for(int i = shift; i < u; i++)
                ret.pb('#');
            ret.pb('_');
        }
    }

    if(sz(ret) > n){
        ret.pop_back();
    }
    while(sz(ret) < n)
        ret.pb('_');
    return ret;
}

bool pusty(){
    for(int i = 0; i < n; i++)
        if(s[i] != '_')
            return false;
    return true;
}

void solve(){
    cin >> s;
    n = sz(s);

    if(pusty()){
        cout << 0 << '\n';
        exit(0);
    }

    for(int i = 0; i < n; i++)
        if(s[i] == '#' and (i == 0 or s[i - 1] == '_')){
            int dl = 0;
            for(int j = i; j < n; j++)
                if(s[j] == '#')
                    dl++;
                else
                    break;

            for(int j = i - 1; j >= -1; j--)
                if(j == -1 or s[j] == '#'){
                    int temp_shift = i - j - 1;
                    if(i + temp_shift + dl - 1 > n - 1)
                        temp_shift = n - i - dl;

                    // cout << "TEMP : " << temp_shift << ' ' << endl;
                    min_shift = min(min_shift, temp_shift);
                    break;
                }
        }

    for(int sh = min_shift; sh >= max(min_shift - 5, 0); sh--){
        auto pom = zgadnij_shift(sh);
        if(sz(pom) > 0){
            // assert(wspolne_pola(pom) == s);
            cout << sz(pom) << '\n';
            for(auto & u : pom)
                cout << u << ' ';
            cout << '\n';
            exit(0);
        }
    }

    cout << -1 << '\n';
    exit(0);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--)
        solve();
}