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
const int N=100005;
int a[30];
void solve (int k, int p){
    if (k>26)return;
    int I;
    for (I=1;I*(I-1)/2<=p;I++){}
    I--;
    if (I==1)I--;
    a[k]=I;
    solve(k+1,p-I*(I-1)/2);
}
int main() {
    int n;
    cin>>n;
    if (n==0){
        cout<<"a";
        return 0;
    }
    solve(1,n);
    char ch='a'-1;
    for (int i=1;i<=26;i++){
        ch++;
        for (int j=0;j<a[i];j++)
            cout<<ch;
    }
    return 0;
}