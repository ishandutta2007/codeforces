#include <iostream>
using namespace std;
#define ll long long
int gcd(int a,int b){
    if(b==0) return a;

    return gcd(b,a%b);
}
struct ant {
    int min;
    int freq;
    int div;
    
};
ant seg[200000];
int n;

    ant upd(ant x,ant y){
        int div, freq, min;
        div = gcd(x.div,y.div);
        if(x.min==y.min){
            freq = x.freq+y.freq;
            min = x.min;
        }
        else if(x.min<y.min){
            freq = x.freq;
            min = x.min;
        }
        else{
            freq=  y.freq;
            min = y.min;
        }
        return {min,freq,div};
    }
void build(){
    for(int i=n-1;i>=1;i--){
        seg[i] = upd(seg[2*i],seg[2*i+1]);
    }
}
int query(int l,int r){
    l+=n;
    r+=n;
    ant res = {2000000000,0,0};
    int x = r-l;
    while(l<r){
        if(l%2==1){
            res =  upd(seg[l],res);
            l++;
        }
        if(r%2==1){
            res = upd(seg[r-1],res);
        }
        l/=2;
        r/=2;
    }
    if(res.div==res.min){
        return x-res.freq;
    }
    else{
        return x;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int s;
        cin >> s;
        seg[i+n] = {s,1,s};
    }
    build();

    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int l,r;
        cin >> l >> r;
        l--;
        cout << query(l,r) << endl;

    }
}