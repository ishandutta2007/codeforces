#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define pb push_back

using namespace std;

int n,m;
int niz[105];
bool b[105][105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ff(i,1,n)cin >> niz[i];
    ff(i,1,n)ff(j,1,n)b[i][j] = false;
    ff(i,1,m){
        int u, v;
        cin >> u >> v;
        b[u][v] = b[v][u] = true;
    }
    int ans = -1;
    ff(i,1,n){
        ff(j,i+1,n){
            ff(k,j+1,n){
                if(b[i][j] == true && b[i][k] == true && b[j][k] == true){
                    int s = niz[i]+niz[j]+niz[k];
                    if(ans == -1 || ans > s)ans = s;
                }
            }
        }
    }
    cout << ans;
    return 0;
}