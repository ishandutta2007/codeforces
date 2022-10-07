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
const int N=200005;
int n;
int A=-1,B=-1;
pair<int,int>P[N];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>P[i].fr>>P[i].sc;
    }
    sort(P+1,P+n+1);
    for (int i=1;i<=n;i++){
        if (A<P[i].fr)
            A=P[i].sc;
        else if (B<P[i].fr)
            B=P[i].sc;
        else {
            cout<<"NO\n";
            return 0;
        }
        if (A<B)swap(A,B);
    }
    cout<<"YES\n";
    return 0;
}