#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAXN = 1000000;
int n;
int l[MAXN + 5], r[MAXN + 5];
int P[MAXN + 5];
int mas[MAXN + 5];
int mass[MAXN + 5];
map<int,int>M;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; ++i){
        cin>>l[i]>>r[i];
        P[i * 3 - 2] = l[i];
        P[i * 3 - 1] = r[i];
        P[i * 3] = r[i]+1;
    }
    sort (P + 1, P + n * 3 + 1);
    int num = 0;
    for (int i = 1; i <= n * 3; ++i){
        if (P[i] > P[i - 1] || i==1)
            num++;
        M[P[i]] = num;
    }
    for (int i = 1; i <= n; ++i){
        l[i] = M[l[i]];
        r[i] = M[r[i]];
        mas[l[i]]++;
        mas[r[i]+1]--;
    }
    for (int i = 1; i <= num; ++i)
        mas[i] += mas[i-1];
    for (int i = 1; i <= num; ++i){
        mass[i]=mass[i-1];
        if (mas[i] < 2)
            mass[i]++;
    }
    for (int i = 1; i <= n; ++i)
    if (mass[r[i]] - mass[l[i] - 1] == 0){
        cout<<i<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}