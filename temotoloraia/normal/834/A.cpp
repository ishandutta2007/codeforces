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
int main() {
    char c[2];
    ll n,x[2];
    cin>>c[0]>>c[1];
    cin>>n;
    for (int i=0;i<2;i++){
        if (c[i]=='v')
            x[i]=0;
        if (c[i]=='<')
            x[i]=1;
        if (c[i]=='^')
            x[i]=2;
        if (c[i]=='>')
            x[i]=3;
    }
    if ((x[0]+n)%4==x[1] && (x[1]+n)%4!=x[0]){
        cout<<"cw\n";
        return 0;
    }
    if ((x[0]+n)%4!=x[1] && (x[1]+n)%4==x[0]){
        cout<<"ccw\n";
        return 0;
    }
    //cout<<(x[0]+n)<<" "<<(x[1]+n)%4<<endl;
    cout<<"undefined"<<endl;
    return 0;
}