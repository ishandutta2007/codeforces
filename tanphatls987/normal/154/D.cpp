#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int alp=27;
const int N=1e6+10;
const int MOD=1e9+7;
const int BASE[2]={2,43};




int main(){
    int xa,xb,L,R;
    cin>>xa>>xb>>L>>R;
    int sign=1;
    if (xa>xb){
        xa*=-1;xb*=-1;
        L*=-1;R*=-1;
        swap(L,R);

        sign=-1;
    }
    ///insta win

//    cout<<xa<<" "<<xb<<" "<<L<<" "<<R<<'\n';
    if (L<=xb-xa&&xb-xa<=R){
        cout<<"FIRST\n"<<sign*xb;
        return 0;
    }
    if (L<=0) cout<<"DRAW";
    else{
        int dist=xb-xa;
        if (dist%(L+R)==0) cout<<"SECOND";
        else {
            if (L<=dist%(L+R)&&dist%(L+R)<=R) cout<<"FIRST\n"<<sign*(xa+dist%(L+R));
            else cout<<"DRAW";
        }
    }
}