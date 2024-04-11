#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 2e5 + 5;

int N;
string S;
bool P[n];


// computes gcd (a,b)
ll gcd ( ll a , ll b) {
ll tmp ;
while (b){a %= b; tmp =a; a=b; b= tmp ;}
return a;
}

int main(){
	cin >> N >> S;
	int zc = 0;
	for(int i = 0; i < N; ++i){
		zc += (S[i] == '1')?1:0;
	}
	int c =0;
	for(int k = 0; k < N; ++k){
		//cerr << "k " << k << " %: "  << k%N << endl;
		if(k == 0){
			c += (zc == 0)?1:0;
			continue;
		}
		if(N%k == 0){
			bool val = true;
			for(int i = 0; i < k; ++i){
				int cc = 0;
				int v = i;
				for(int j = 0; j < N/k; ++j){
					cc += (S[v] == '1')? 1:0;
					v = (v+k)%N;
				}
				val = val && ((cc%2) == 0);
			}
			c += val?1:0;
			P[k] = val;
		}else{
			int g = gcd(k, N);
			if(g == 1){
				c += ((zc % 2) == 0)? 1:0;
			}else{
				//cerr <<"k= " << k << " g: "<< g << " P[g] " << P[g] << endl;
				c += P[g];
			}
		}
	}
	cout << c << endl;
	return 0;
}