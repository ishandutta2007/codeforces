#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
#define X first
#define Y second

const int inf=1e9+10;
const int N=1e3+10;
const double eps=1e-12;

int main(){
        int n,k;
        cin>>n>>k;
        int cur=k;
        while (n--){
                int val;
                cin>>val;
                cur=__gcd(cur,val);
        }
        cout<<k/cur<<'\n';
        for(int i=0;i<k;i+=cur) cout<<i<<" ";
}