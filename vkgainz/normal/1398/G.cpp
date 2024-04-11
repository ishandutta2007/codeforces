#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vector<int> multiply(vector<int> const&a,vector<int> const&b){
    vector<cd> fa(a.begin(),a.end()), fb(b.begin(),b.end());
    int pow=1;
    while(pow < (a.size()+b.size())){
      pow *= 2;
    }
    fa.resize(pow);
    fb.resize(pow);
    fft(fa,false);
    fft(fb,false);
    for(int i=0;i<pow;i++){
        fa[i]*=fb[i];
    }
    fft(fa,true);
    vector<int> result(pow);
    for(int i=0;i<pow;i++){
      result[i] = round(fa[i].real());
    }
    return result;
}
int ans[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x, y; cin >> n >> x >> y;
  vector<int> a(x + 1), b(x + 1);
  fill(a.begin(), a.end(), 0);
  fill(b.begin(), b.end(), 0);
  for(int i=0;i < n + 1;i++) {
    int r; cin >> r;
    a[r] = 1;
    b[x - r] = 1;
  }
  vector<int> res = multiply(a, b);
  vector<bool> in(2 * MX);
  fill(in.begin(), in.end(), false);
  for(int i=x + 1; i < res.size();i++) {
    if(res[i] > 0) in[i - x + y] = true;
  }
  memset(ans, -1, sizeof(ans));
  for(int i = 0; i < in.size(); i++) {
    if(!in[i]) continue;
    for(int j = 2 * i; j <= 1000000; j += 2 * i) {
      ans[j] = max(ans[j], 2 * i);
    }
  }
  int q; cin >> q;
  while(q--) {
    int l; cin >> l;
    cout << ans[l] << " ";
  }
  cout << "\n";
}