#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
const int MX = 1e5+5;
void print(complex<long double> c) {
    cout << c.real() << " " << c.imag() << "\n";
}
int main() {
    complex<long double> a, b, c;
    int x,y; cin >> x >> y;
    a = complex<long double>(x, y);
    cin >> x >> y;
    b = complex<long double>(x, y);
    cin >> x >> y;
    c = complex<long double>(x, y);
    complex<long double> div = b+b-a-c;
    if(div.real()==0 && div.imag()==0) {
        cout << "No" << "\n";
        return 0;
    }
    long double d1 = norm(a-b);
    long double d2 = norm(b-c);
    if(d1==d2) { 
        cout << "Yes" << "\n";
    }
    else cout << "No" << "\n";
    

}