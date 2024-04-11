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

const ll N = 2007;

int n, m;
int a[N], b[N];
int mas[N];
pair < int, int > P[N];
bool F[N];

int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n * 2; i++){
        cin>>P[i].F;
        P[i].F *= -1;
        P[i].S = i;
    }
    sort (P + 1, P + n * 2 + 1);
    for (int i = 1; i <= n * 2; i++){
        P[i].F *= -1;
        mas[P[i].S] = i;
    }
    for (int i = 1; i <= m; i++){
        cin>>a[i]>>b[i];
        a[i] = mas[a[i]];
        b[i] = mas[b[i]];
        if (a[i] > b[i])
            swap (a[i], b[i]);
    }
    int T;
    cin>>T;
    if (T == 1){
        for (int i = 1; i <= m; i++){
            int x = P[a[i]].S;
            cout<<x<<endl;
            fflush (stdout);
            x = mas[x];
            F[x] = 1;
            cin>>x;
            x = mas[x];
            F[x] = 1;
        }
        for (int i = 1; i <= n * 2; i++)
            if (F[i] == 0){
                int x = P[i].S;
                cout<<x<<endl;
                fflush (stdout);
                x = mas[x];
                F[x] = 1;
                cin>>x;
                x = mas[x];
                F[x] = 1;
            }
        return 0;
    }
    for (int i = 1; i <= n; i++){
        int x;
        cin>>x;
        x = mas[x];
        F[x] = 1;
        int y = 0;
        for (int j = 1; j <= m; j++){
            if (a[j] == x && F[b[j]] == 0){
                y = P[b[j]].S;
                break;
            }
            if (b[j] == x && F[a[j]] == 0){
                y = P[a[j]].S;
                break;
            }
        }
        if (y != 0){
            cout<<y<<endl;
            fflush (stdout);
            F[mas[y]] = 1;
            continue;
        }
        for (int j = 1; j <= m; j++)
            if (F[a[j]] == 0){
                y = P[a[j]].S;
                break;
            }
        if (y != 0){
            cout<<y<<endl;
            fflush (stdout);
            F[mas[y]] = 1;
            continue;
        }
        for (int j = 1; j <= n * 2; j++)
            if (F[j] == 0){
                y = P[j].S;
                break;
            }
        cout<<y<<endl;
        fflush (stdout);
        F[mas[y]] = 1;
    }
    return 0;
}