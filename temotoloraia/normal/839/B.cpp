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
int n,k;
priority_queue<int>Q;
int main() {
    cin>>n>>k;
    while (k--){
        int x;
        cin>>x;
        Q.push(x);
    }
    int p=0;
    for (int i=1;i<=n && Q.size()>0;i++){
        int x=Q.top();
        if (x<=2){
            p=n-i+1;
            break;
        }
        Q.pop();
        x-=4;
        if (x>0)Q.push(x);
    }
    for (int i=1;i<=n*2+p && Q.size()>0;i++){
        int x=Q.top();
        Q.pop();
        x-=2;
        if (x>0)Q.push(x);
    }
    for (int i=1;i<=p && Q.size()>0;i++){
        int x=Q.top();
        Q.pop();
        x-=1;
        if (x>0)Q.push(x);
    }
    if (Q.size()>0)cout<<"NO";
    else cout<<"YES";
    return 0;
}