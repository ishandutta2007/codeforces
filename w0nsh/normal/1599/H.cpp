#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define sz(s) (int)s.size()
#define pb push_back
#define all(s) s.begin(), s.end()
#define ld long double
#define ii pair<int, int>
#define vi vector<int>

const int MLD = 1000 * 1000 * 1000;
ostream & operator << (ostream & os, ii pkt) { os << pkt.f << ' ' << pkt.s; return os; }

ii rot90(ii pkt){
    return {-pkt.s, pkt.f};
}

ii flip(ii pkt, int ile){
    for(int i = 0; i < ile; i++){
        pkt = rot90(pkt);
        pkt.f += MLD + 1;
    }

    return pkt;
}

int ask(ii poz, int ile){
    poz = flip(poz, ile);
    cout << "? " << poz << endl;

    int ret;
    cin >> ret;
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vi odl_od_scjany;

    for(int i = 0; i < 4; i++){
        int a = ask({1, 1}, i);
        int b = ask({1, MLD}, i);

        ii dol = {a, 1};
        ii gora = {b, MLD};

        int diff = abs(a - b);
        if(a > b)
            dol.f -= diff, dol.s += diff;
        else
            gora.f -= diff, gora.s -= diff;

        diff = gora.s - dol.s;

        dol.f -= diff / 2, dol.s += diff / 2;
        // disregard b

        if(dol.f < 1)
            dol.f = 1;
        odl_od_scjany.pb(ask(dol, i) + dol.f); 
    }

    cout << "! " << odl_od_scjany[0] << ' ' << odl_od_scjany[1] << ' ' << MLD + 1 - odl_od_scjany[2] << ' ' << MLD + 1 - odl_od_scjany[3] << '\n'; 
}