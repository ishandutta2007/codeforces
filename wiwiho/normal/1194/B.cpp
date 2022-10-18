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
#define fr front()
#define po pop()
#define ba back()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
 
//#define TEST
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){
 
    StarBurstStream

    int q;
    cin >> q;
    while(q--){

        int n, m;
        cin >> n >> m;
        vector<vector<bool>> p(n, vector<bool>(m));
        vector<int> row(n), column(m);
        int rowmx = 0, columnmx = 0;

        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < m; j++){
                if(s[j] == '*'){
                    p[i][j] = true;
                    row[i]++;
                    column[j]++;
                    rowmx = max(rowmx, row[i]);
                    columnmx = max(columnmx, column[j]);
                }
            }
        }

        vector<int> rowp;

        for(int i = 0; i < n; i++){
            if(row[i] == rowmx){
                rowp.pb(i);
            }
        }
        
        bool nocross = false;
        for(int j = 0; j < m; j++){
            if(column[j] == columnmx){
                for(int i = 0; i < rowp.size(); i++){
                    if(!p[rowp[i]][j]){
                        nocross = true;
                        break;
                    }
                }
            }
            if(nocross){
                break;
            }
        }
        
        if(!nocross){
            cout << (m - columnmx + n - rowmx) << "\n";
        }
        else{
            cout << (m - columnmx + n - rowmx - 1) << "\n";
        }

    }

    return 0;
}