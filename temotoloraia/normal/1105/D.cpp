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
using namespace std;

const ll N = 1005;

char a[N][N];
int n, m, p;
int s[N];
vector < int > V1[N], V2[N];
vector < int > v1, v2;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

bool OK;
int r, c, newr, newc;

int mas[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if ('1' <= a[i][j] && a[i][j] <= '9'){
                V1[a[i][j] - '0'].pb (i);
                V2[a[i][j] - '0'].pb (j);
            }
        }
    while (1){
        OK = 0;
        for (int i = 1; i <= p; i++)
            if ((int)V1[i].size() > 0)
                OK = 1;
        if (OK == 0)
            break;
        for (int i = 1; i <= p; i++){
            //cout << i << " " << (int)V1[i].size() << " " << (int)V2[i].size() << endl;
            for (int j = 0; j < s[i] && (int)V1[i].size() > 0; j++){
                v1.clear();
                v2.clear();
                for (int k = 0; k < (int)V1[i].size(); k++){
                    r = V1[i][k], c = V2[i][k];
                    for (int l = 0; l < 4; l++){
                        newr = r + dr[l];
                        newc = c + dc[l];
                        if (newr < 1 || n < newr || newc < 1 || m < newc)
                            continue;
                        if (a[newr][newc] != '.')
                            continue;
                        a[newr][newc] = a[r][c];
                        //cout << a[r][c] << endl;
                        v1.pb (newr);
                        v2.pb (newc);
                    }
                }
                V1[i] = v1;
                V2[i] = v2;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ('1' <= a[i][j] && a[i][j] <= '9')
                mas[a[i][j] - '0']++;
    for (int i = 1; i <= p; i++)
        cout << mas[i] << " ";
    cout << endl;
    return 0;
}