#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=200005,INF=1e9;
int n;
pair<int,int>PA[N],PB[N];
int mas[N];
int a[N];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>PA[i].fr;
        a[i]=PA[i].fr;
        PA[i].sc=i;
    }
    for (int i=1;i<=n;i++){
        cin>>PB[i].fr;
        PB[i].sc=i;
    }
    sort(PA+1,PA+n+1);
    sort(PB+1,PB+n+1);
    reverse(PB+1,PB+n+1);
    for (int i=1;i<=n;i++)
        mas[PB[i].sc]=PA[i].sc;
    for (int i=1;i<=n;i++)
        cout<<a[mas[i]]<<" ";
    return 0;
}