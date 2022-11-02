#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
#include<stack>

#define X first
#define Y second

using namespace std;
typedef long long int lint;
typedef long double ldb;

const lint INF = 1e18;

const int MAXN = 1e6 + 7;

int a[26];
int n;
int sum = 0;
int ans = 1e7;
//int where = 0;
//stack<int> divs;
string s = "";

void solve(int x){
    for(int i = 0; i < 26; i++){
        if(a[i] % (sum/x) != 0){return;}
    }
    int b[26];
    for(int i = 0; i < 26; i++)
        b[i] = a[i]/(sum/x);
    int odd = 0;
    for(int i = 0; i < 26; i++){
        if(b[i] % 2 != 0)
            odd++;
    }
    if(odd > 1)
        return;
    if(ans > x){ans = x;}
}

char sym(int i){
    return 'a' + i;
}

vector<lint> lh1, lh2;
vector<lint> rh1, rh2;
lint m1 = 1000000007, m2 = 1000000009;
lint p1 = 37, p2 = 53;
vector<lint> cp1, cp2;

lint gcd (lint a, lint b, lint & x, lint & y) {
	if (a == 0ll) {
		x = 0ll; y = 1ll;
		return b;
	}
	lint x1, y1;
	lint d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

lint inv(lint a, lint m){
lint x, y;
lint g = gcd (a, m, x, y);
	x = (x % m + m) % m;
	return x;
}

int calc(){
    string t = s + s;
    int tl = t.length();
    int res = 0;
    /*int res = sum/ans;
    if(sum % 2 == 0 && ans == sum){
            res++;
    }
    return res;*/
    lh1.resize(tl);
    lh2.resize(tl);
    rh1.resize(tl);
    rh2.resize(tl);
    cp1.resize(tl);
    cp2.resize(tl);
    lint cpow1 = 1ll, cpow2 = 1ll;
    for(int i = 0; i < tl; i++){
            cp1[i] = cpow1;
    cp2[i] = cpow2;
        lint x = t[i] - 'a' + 1;
        if(i == 0){
            lh1[i] = x;
            lh2[i] = x;
        }
        else{
            lh1[i] = lh1[i - 1] + x * cpow1;
            lh2[i] = lh2[i - 1] + x * cpow2;
            lh1[i] %= m1;
            lh2[i] %= m2;
        }
        cpow1 = cpow1 * p1 % m1;
        cpow2 = cpow2 * p2 % m2;
    }
    cpow1 = 1ll; cpow2 = 1ll;
    for(int i = tl - 1; i >= 0; i--){
        lint x = t[i] - 'a' + 1;
        if(i == tl - 1){
            rh1[i] = x;
            rh2[i] = x;
        }
        else{
            rh1[i] = rh1[i + 1] + x * cpow1;
            rh2[i] = rh2[i + 1] + x * cpow2;
            rh1[i] %= m1;
            rh2[i] %= m2;
        }
        cpow1 = cpow1 * p1 % m1;
        cpow2 = cpow2 * p2 % m2;
    }
    for(int i = 0; i + sum - 1 < tl; i++){
        lint cl1 = (i == 0) ? lh1[i + sum - 1] : (lh1[i + sum - 1] - lh1[i - 1]);
        lint cl2 = (i == 0) ? lh2[i + sum - 1] : (lh2[i + sum - 1] - lh2[i - 1]);
        lint cr1 = (i + sum - 1 == tl - 1) ? rh1[i] : (rh1[i] - rh1[i + sum]);
        lint cr2 = (i + sum - 1 == tl - 1) ? rh2[i] : (rh2[i] - rh2[i + sum]);
        cl1 = cl1 % m1 + m1;
        cl2 = cl2 % m2 + m2;
        cr1 = cr1 % m1 + m1;
        cr2 = cr2 % m2 + m2;
        cl1 %= m1; cl2 %= m2; cr1 %= m1; cr2 %= m2;
        /*cl1 = cl1 * inv(cp1[i], m1) % m1;
        cl2 = cl2 * inv(cp2[i], m2) % m2;
        cr1 = cr1 * inv(cp1[tl - 1 - (i + sum - 1)], m1) % m1;
        cr2 = cr2 * inv(cp2[tl - 1 - (i + sum - 1)], m2) % m2;*/
        lint id;
        if(i < (tl - 1 - (i + sum - 1)))
            id = tl - 1 - (i + sum - 1);
        else
            id = i;

        cl1 = cl1 * cp1[id - i] % m1;
        cl2 = cl2 * cp2[id - i] % m2;
        cr1 = cr1 * cp1[id - (tl - 1 - i - sum + 1)] % m1;
        cr2 = cr2 * cp2[id - (tl - 1 - i - sum + 1)] % m2;
        if(cl1 == cr1 && cl2 == cr2)
            res++;
    }
    res--;
    return res;
}

int main(){
    //ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    memset(a, 0, 26 * sizeof(int));
    for(int i = 0; i < n; i++){scanf("%d", &a[i]); sum += a[i];}
    for(int i = 1; i * i <= sum; i++){
        if(sum % i == 0){
            solve(i);
        }
        if(i * i != sum)
            solve(sum/i);
    }
    if(ans > sum){
            printf("0\n");
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < a[i]; j++){
                putc(sym(i), stdout);
            }
        }
        return 0;
    }
    int b[26];
    for(int i = 0; i < 26; i++)
        b[i] = a[i]/(sum/ans);
    int odd = -1;
    for(int i = 0; i < 26; i++){
        if(b[i] % 2 != 0)
            odd = i;
    }
    if(odd != -1){s = sym(odd); b[odd]--;}
    for(int i = 0; i < 26; i++){
        for(int j = b[i]; j > 0; j -= 2){
            s = sym(i) + s + sym(i);
        }
    }
    string tmp = s;
    for(int i = 1; i < sum/ans; i++){
        s = s + tmp;
    }
    printf("%d\n", calc());
    printf("%s", s.c_str());
    return 0;

}