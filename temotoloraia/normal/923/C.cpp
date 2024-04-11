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
const int N = 300005;
int n;
int a[N];
multiset < int > S;
multiset < int >::iterator I1, I2;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n; i++){
        int x;
        cin>>x;
        S.insert (x);
    }
    for (int i = 1; i <= n; i++){
        I1 = S.begin();
        I2 = S.end();
        I2--;
        int X = 0;
        for (int j = 29; j >= 0; j--){
            if ((a[i] & (1<<j)) == 0){
                if ((*I1) < (X ^ (1<<j))){
                    I2 = S.lower_bound ((X ^ (1<<j)));
                    I2--;
                }
                else {
                    X ^= (1<<j);
                }
            }
            else {
                if ((*I2) >= (X ^ (1<<j))){
                    X ^= (1<<j);
                    I1 = S.lower_bound (X);
                }
            }
        }
        cout<<(a[i]^(*I1))<<" ";
        S.erase (S.find (*I1));
    }
    return 0;
}