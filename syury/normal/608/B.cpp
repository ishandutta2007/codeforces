#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>

using namespace std;
typedef long long int lint;
typedef long double ldb;

#define PI 3.141592653589793

//typedef complex<double> cnum;

struct cnum {
    double re, im;
    cnum(){
        re = 0;
        im = 0;
    }
    cnum(ldb a){
        re = a;
        im = 0;
    }
    cnum(ldb a, ldb b){re = a; im = b;}
};

cnum operator + (const cnum & a, const cnum & b){
    return cnum(a.re + b.re, a.im + b.im);
}

cnum operator - (const cnum & a, const cnum & b){
    return cnum(a.re - b.re, a.im - b.im);
}

void operator *= (cnum & a, const cnum & b){
    cnum tmp(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re);
    a = tmp;
}

cnum operator * (const cnum & a, const cnum & b){
    cnum tmp = a;
    tmp *= b;
    return tmp;
}

void operator /= (cnum & a, const int & b){
    a.re /= b;
    a.im /= b;
}

typedef vector<cnum> poly;

int rev(int a, int len){
    int ans = 0;
    for(int i = 0; i < len; i++){
        if(a & (1 << i)){
            ans |= (1 << (len - 1 - i));
        }
    }
    return ans;
}

void fft(poly & a, bool inv){
    int n = a.size();
    int lg = 0;
    while((1 << lg) < n){lg++;}
    for(int i = 0; i < n; i++){
        if(i < rev(i, lg)){swap(a[i], a[rev(i, lg)]);}
    }
    for(int len = 2; len <= n; len<<=1){
        double phi = 2 * PI / len;
        if(inv){phi = (-1) * phi;}
        cnum wlen(cos(phi), sin(phi));
        for(int i = 0; i < n; i += len){
            cnum w(1, 0);
            for(int j = 0; j < len/2; j++){
                cnum u = a[i + j], v = a[i + j + len/2] * w;
                a[i + j] = u + v;
                a[i + j + len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if(inv){
        for(int i = 0; i < n; i++){
            a[i] /= n;
        }
    }
}

poly mp(poly a, poly b){
    int n = a.size();
    n *= 2;
    a.resize(n); b.resize(n);
    fft(a, false);
    fft(b, false);
    for(int i = 0; i < n; i++){
        a[i] *= b[i];
    }
    fft(a, true);
    return a;
}

/*poly smp(poly a, poly b){
    int n = a.size();
    n *= 2;
    poly res(n);
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++){
            res[i + j].re += a[i].re * b[j].re;
        }
    }
    return res;
}
*/
string a, b;
poly p1, p2;
poly na, nb;

int main(){
    ios_base::sync_with_stdio(false);
    getline(cin, a);
    getline(cin, b);
    int old = a.length();
    int ob = b.length();
    int n = 2 * b.length();
    int lg = 0;
    while((1 << lg) < n){lg++;}
    p1.resize(1 << lg);
    p2.resize(1 << lg);
    while(a.length() < b.length()){a += "2";}
    a += a;
    reverse(b.begin(), b.end());
    while(b.length() < n){b += "2";}
    for(int i = 0; i < (1 << lg); i++){
        //if((1 << lg) -  1 - i >= n){p1[i] = p2[i] = cnum(0); continue;}
        if(i >= n){p1[i] = p2[i] = cnum(0); continue;}
        if(a[i] == '0'){p1[i] = cnum(-1);}
        if(a[i] == '1'){p1[i] = cnum(1);}
        if(a[i] == '2'){p1[i] = cnum(0);}
        if(b[i] == '0'){p2[i] = cnum(-1);}
        if(b[i] == '1'){p2[i] = cnum(1);}
        if(b[i] == '2'){p2[i] = cnum(0);}
    }
    poly res = mp(p2, p1);
    //poly sr = smp(p2, p1);
    n = n/2;
    long long int ans = 0ll;
    for(int i = n - 1; i <= 2 * n - 2; i++){
        int curr = floor(res[i].re + 0.5);
        curr = curr;
        //int nc = floor(sr[i].re + 0.5);
        int bpos = i - (n - 1);
        //cout << curr /*<< " " << nc*/ << endl;
        if(bpos >= old || bpos == 0){
            ans += old - (old + curr)/2;
            //ans += curr;
        }
        //cout << ans << endl;
    }
    //int num = ob - (old - 1);
    //ans = num * 1ll * old - (num * 1ll * old + ans)/2;
    cout << ans << endl;
    return 0;
}