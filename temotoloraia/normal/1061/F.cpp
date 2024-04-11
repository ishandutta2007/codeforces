#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo

using namespace std;
const ll N = 1507;
bool F[N];
ll n = 3, k = 2;
int u, v;
vector < int > V;
map < pair < pair < int, int >, int >, string > M;
int main()
{
    for (int i = 0; i < 1000; i++){}
    cin>>n>>k;
    srand (time(NULL));
    ll m = 0, p = k - 1;
    while (p < (k - 1) * n){
        p = (p + 1) * k - 1;
        m++;
    }
    //cout<<m<<endl;
    for (int ind = 0; ind < n; ind++){
        u = rand() % n + 1;
        while (F[u] == 1)
            u = rand() % n + 1;
        F[u] = 1;
        //cout<<u<<endl;
        for (int i = 0; i < n * 3; i++){
            int x = rand() % n + 1;
            while (x == u)
                x = rand() % n + 1;
            int y = rand() % n + 1;
            while (y == u || y == x)
                y = rand() % n + 1;
            if (x > y)
                swap (x, y);
            string s;
            if (M.find ({{x, u}, y}) == M.end()){
                cout<<"? "<<x<<" "<<u<<" "<<y<<endl;
                fflush (stdout);
                cin>>s;
                M[{{x, u}, y}] = s;
            }
            s = M[{{x, u}, y}];
            if (s == "Yes"){
                u = 0;
                break;
            }
        }
        if (u == 0)
            continue;
        //cout<<u<<endl;
        if (v == 0){
            v = u;
            continue;
        }
        //cout<<u<<" "<<v<<endl;
        if (u > v)
            swap (u, v);
        for (int i = 1; i <= n; i++){
            if (i == u || i == v)
                continue;
            string s;
            if (M.find ({{u, i}, v}) == M.end()){
                cout<<"? "<<u<<" "<<i<<" "<<v<<endl;
                fflush (stdout);
                cin>>s;
                M[{{u, i}, v}] = s;
            }
            s = M[{{u, i}, v}];
            if (s == "Yes")
                V.push_back (i);
        }
        //cout<<V.size()<<endl;
        if (V.size() == 2 * m - 1)
            break;
        u = 0;
        V.clear();
    }
    sort (V.begin(), V.end());
    //cout<<V.size()<<endl;
    for (int i = 0; i < V.size(); i++){
        int c = 0;
        for (int j = 0; j < V.size(); j++)
            if (j != i)
                for (int l = j + 1; l < V.size(); l++)
                    if (l != i){
                        int x = V[j], y = V[i], z = V[l];
                        string s;
                        if (M.find ({{x, y}, z}) == M.end()){
                            cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
                            fflush (stdout);
                            cin>>s;
                            M[{{x, y}, z}] = s;
                        }
                        s = M[{{x, y}, z}];
                        if (s == "Yes")
                            c++;
                    }
        if (c == (m - 1) * (m - 1)){
            cout<<"! "<<V[i]<<endl;
            fflush (stdout);
        }
    }
    return 0;
}