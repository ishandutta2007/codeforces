#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e2 + 5;

int n, m;
char a[N][N];

vector <array <int, 4>> vans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int tests; cin >> tests; while (tests--){
    cin >> n >> m;
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> a[i][j];
        }
    }

    if (a[1][1] != '0'){
        cout << -1 << endl;
        continue;
    }
    vans.clear();
    FordE(j, m, 1){
        FordE(i, n, 2){
            if (a[i][j] == '1'){
                vans.emplace_back(array <int, 4>({i - 1, j, i, j}));
            }
        }
    }
    FordE(j, m, 2){
        if (a[1][j] == '1'){
            vans.emplace_back(array <int, 4>({1, j - 1, 1, j}));
        }
    }
    cout << isz(vans) << endl;
    Fora(&move, vans){
        For(i, 0, 4){
            cout << move[i] << ' ';
        } cout << endl;
    }
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
NII-CHAAAAAAAAAAN! (>w<) * I jump on you * onii-chan, I miss you :3 how was 
your class today? How was that bad? (////), oh did they make fun of you 
for the necklace I gave you? Ah don't care about them, at least you have me 
(UwU) *hugs you* and onii-chan, you know you can always count on me don't 
you? * I'm getting closer to your face * * I sit on your lap and put my ass 
on your lap * so I want you to be calm with me next to you! (.//w//.) 
W-wait onii-chan, w-what is this thing touching me down there? *I look down 
at your lap* *you're horny* O-onii-chan, w-why are you feeling this? (//w//)
y-you want a kiss-AH! * you kiss me hard with your tongue * * I 
continue the kiss * onii-chan..I want to test something I've wanted to test 
with you for a long time..* I take off your pants and underwear * let's see 
if it tastes good. .* lick and suck his dick, making him full of my drool * 
hmm..hmm..Hm... onii-chan..he's really hard..I want to put him inside..* I 
take off my fluffy skirt Kwai with heart in the middle and my panties with 
yellow polka dots and I put your dick inside my pussy * Ah..came in..* I'm 
going slowly * nya..ah... onii-chan...let's..v-let's.. Nyan..let's go 
faster~..* I'm putting my pussy in your dick while I moan your name and say 
I'm going to come * Ah..ah..ahhh~..mmm.. Onii-chan..please.. enjoy 
everything in me..I want that hot fuck of yours inside me *I feel your dick 
harder and you go faster* Ah..mmm....NYAN~... O-ONII-CHAN..AAH~.. niichaan..
~ NYAAAAAN~~* we come together *
*/