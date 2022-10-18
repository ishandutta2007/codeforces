#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

vector<vector<vector<int>>> hihi(10, vector<vector<int>>(10, vector<int>(10)));

void abc(int aaa){
    for(int x = 0; x < 10; x++){

        for(int y = 0; y < 10; y++){

            int temp = -1;

            for(int xc = 0; xc < 10; xc++){

                for(int yc = 0; yc < 10; yc++){

                    if(xc == 0 && yc == 0) continue;

                    if(temp != -1 && xc + yc - 1 >= temp) break;

                    if((xc * x + yc * y) % 10 == aaa){
                        if(temp == -1 || xc + yc - 1 < temp){
                            temp = xc + yc - 1;
                        }
                        break;
                    }

                }

            }

            hihi[aaa][x][y] = temp;

        }

    }
}

int main(){
    StarBurstStream

    string s;
    cin >> s;

    vector<vector<int>> a(10, vector<int>(10));

    for(int i = 0; i < 10; i++) abc(i);

    for(int x = 0; x < 10; x++) for(int y = 0; y < 10; y++)
            for(int i = 1; i < s.size(); i++){

                int t = ((s[i] - '0') - (s[i- 1] - '0') + 10) % 10;
                int b = hihi[t][x][y];

                if(b == -1){
                    a[x][y] = -1;
                    break;
                }
                else{
                    a[x][y] += b;
                }

            }

    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            cout << a[x][y] << " ";
        }
        cout << "\n";
    }

    return 0;
}