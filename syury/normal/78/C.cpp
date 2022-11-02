#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define DF(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg

vector<int> divs;
map<int, int> gr;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if(n%2 == 0){printf("Marsel"); ret 0;}
	for(ll i = 1; i * i <= m; i++){
		if(m%i != 0)cont;
		divs.pb(i);
		if(i*i != m)divs.pb(m/i);
	}
	sort(all(divs));
	F(i, 0, (int)divs.size()){
		set<int> kek;
		for(ll j = 1; j * j <= divs[i]; j++){
			if(divs[i]%j != 0)cont;
			if(j >= k && j != divs[i]){
				ll lol = divs[i]/j;
				if(lol%2 == 0){kek.ins(0);}
				else{
					kek.ins(gr[j]);
				}
			}
			if(j * j != divs[i] && j != 1){
				ll l = divs[i]/j;
				if(l < k)cont;
				if(j%2 == 0)kek.ins(0);
				else{
					kek.ins(gr[l]);
				}
			}
		}
		int last = -1;
		gr[divs[i]] = -1;
		I(c, kek){
			if(c > last + 1){gr[divs[i]] = last + 1; brk;}
			last = c;
		}
		if(gr[divs[i]] == -1)gr[divs[i]] = last + 1;
	}
	if(gr[m] == 0)printf("Marsel"); else printf("Timur");
	ret 0;
}