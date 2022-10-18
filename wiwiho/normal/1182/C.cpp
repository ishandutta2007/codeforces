#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){

    StarBurstStream

    vector<bool> vowel(26);
    vowel[0] = true;
    vowel['e' - 'a'] = true;
    vowel['i' - 'a'] = true;
    vowel['o' - 'a'] = true;
    vowel['u' - 'a'] = true;

    int n;
    cin >> n;
    map<int, map<char, vector<string>>> words;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        int a = 0;
        char last;
        for(int j = 0; j < str.size(); j++){
            if(vowel[str[j] - 'a']){
                a++;
                last = str[j];
            }
        }
        words[a][last].pb(str);
    }

    vector<string> sec;
    map<int, vector<string>> l;
    for(auto it = words.begin(); it != words.end(); it++){
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
            //cerr << it2->first << " " << it2->second.size() << "\n";
            for(int i = 0; i < it2->second.size() / 2 * 2; i++){
                sec.pb(it2->second[i]);
            }
            if(it2->second.size() % 2 == 1){
                l[it->first].pb(it2->second[it2->second.size() - 1]);
            }
        }
    }
    #ifdef test
    for(int i = 0; i < sec.size(); i++){
        cerr << sec[i] << "\n";
    }
    #endif

    vector<string> fir;
    for(auto it = l.begin(); it != l.end(); it++){
        for(int i = 0; i < it->second.size() / 2 * 2; i++){
            fir.pb(it->second[i]);
        }
    }
    #ifdef test
    for(int i = 0; i < fir.size(); i++){
        cerr << fir[i] << "\n";
    }
    #endif

    int seca = sec.size();
    if(sec.size() > fir.size()){
        for(int i = seca - 1; i >= 0 && seca > fir.size(); i--){
            fir.pb(sec[i]);
            seca--;
        }
    }

    cout << min(seca, (int)fir.size()) / 2 << "\n";

    for(int i = 0; i < min(seca, (int)fir.size()) / 2 * 2; i++){
        cout << fir[i] << " " << sec[i] << "\n";
    }

    return 0;
}