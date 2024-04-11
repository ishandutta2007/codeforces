//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   


/*
Copied from rajat1603 (fft and multiply with bit inverse(inplace precomputation))
base class taken from rajat
TESTED with: VFMUL -------(SPOJ)
             POLYMUL ------(SPOJ)

*/

const long double pi = 4.0 * atan(1.0);
//const int N = 2e5 + 5;
int P = 1 << 19;
int K = 0;
struct base{
    double x , y;
    base(){
        x = 0;
        y = 0;
    }
    base(double a){
        x = a;
        y = 0;
    }
    base(double a , double b){
        x = a;
        y = b;
    }
    base conj(){
        return base(x , -y);
    }
    base operator = (const base &o){
        x = o.x;
        y = o.y;
        return *this;
    }
    base operator + (const base &o) const {
        return base(x + o.x , y + o.y);
    }
    base operator - (const base &o) const {
        return base(x - o.x , y - o.y);
    }
    base operator * (const base &o) const {
        return base(x * o.x - y * o.y , y * o.x + x * o.y);
    }
    base operator * (const double num) const {
        return base(x * num , y * num);
    }
    base operator / (const double num) const {
        return base(x / num , y / num);
    }

};

// bit inverse permutation mathod
int rev[(1<<22)+3];
void pre(){
    int res;
    for(int i = 0 ; i < P ; ++i){
        res = 0;
        for(int j = 0 ; j < K ; ++j){
            if((i >> j) & 1){
                res |= 1 << (K - j - 1);
            }
        }
        rev[i] = res;
    }
}

// fft works 
base fa[(1<<22)+3],haha[(1<<22)+3],fb[(1<<22)+3];

void fft(base a[] , bool inv){
    for(int i = 0 ; i < P ; ++i){
        if(rev[i] > i){
            swap(a[i] , a[rev[i]]);
        }
    }
    for(int size = 2 ; size <= P ; size <<= 1){
        int m = size >> 1;
        base w(cos(2 * pi / size) , sin(2 * pi / size) * (inv ? -1 : 1));
        for(int i = 0 ; i < P ; i += size){
            base cur(1 , 0);
            for(int j = 0 ; j < m ; ++j){
                base v = a[i + j];
                base u = a[i + j + m] * cur;
                a[i + j] = v + u;
                a[i + j + m] = v - u;
                cur = cur * w;
            }
        }
    }
}


// call this to multiply two polynomials result is stored in res
void multiply (base a[],base b[]) {
	pre();
	
	fft (a, false),  fft (b, false);
	for (int i=0; i<P; ++i){
		a[i] =a[i]*b[i];
	}
	fft (a, true);
	for (int i=0; i<P; ++i){
		int lol=min((int)((a[i].x)/P + 0.5),1);
		a[i]=base(lol);
		//cout<<lol<<" ";
	}
	//int i;
	
}


int square(base a[]){

	pre();
	//cout<<"enter";
	
	//cout<<endl;
	fft(a,false);
	for (int i=0; i<P; ++i){
		a[i] =a[i]*a[i];
	}
	fft (a, true);
	for (int i=0; i<P; ++i){
		int lol=min((int)((a[i].x)/P + 0.5),1);
		a[i]=base(lol);
		//cout<<lol<<endl;
	}
	//cout<<endl;
	//cout<<"exit";

}
/*
    STEPS TO FOLLOW 
    1. SET P and K as required
    2 call pre(); then rock 
*/

int solve(int k){

	while(k>0){
		
		int i;
		if(k%2){
			rep(i,P){
				fb[i]=fa[i];
			}
			multiply(haha,fb);	

		}
		
		k/=2;
		//cout<<"boo"<<endl;
		square(fa);
		//cout<<"bum"<<endl;
		K++;
		P=(1<<K);
	}

}

int arr[10000];
int lim=(1<<22)+3;
int main(){
	std::ios::sync_with_stdio(false);
	int n,k,i;
	cin>>n>>k;
	K=0;
	while((1<<K)<1001)K++;
	K++;
	P=(1<<K);
	rep(i,lim){
		fa[i]=base();
		haha[i]=base();
	}
	haha[0]=base(1);
	rep(i,n){
		cin>>arr[i];
		fa[arr[i]]=base(1);
	}
	solve(k);
	//cout<<K<<endl;
	rep(i,P){
		if(haha[i].x!=0){
			cout<<i<<" ";
		}
	}
}