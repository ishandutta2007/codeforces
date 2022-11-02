#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, bool,int,int> TII;
const int n_ = 3e5 + 5, cordOff=1e6+10;

#define MAXN 4100000
#define left(i) (2 * (i) + 1)
#define right(i) (2 * (i) + 2)
#define parent(i) (((i) - 1) / 2)

const int logmaxn = (int) log2(MAXN) + 1;
const int ts = 1 << (logmaxn + 1), to = (1 << logmaxn) - 1;

// the data with default values
typedef int data;
typedef int operation;
/*
  int v = 0;
  data():v(0){}
	data(int vv):v(vv){}
};

// the operation with default values
// this default operation applies a * v + b to every element v
struct operation {
  int b = 0;
  operation():b(0){}
  operation(int bb):a(aa), b(bb){}
};
*/
int n, a[MAXN];
data t[ts];
operation o[ts];

// combine the data from different branches
data combineD(data l, data r) {
  return max(l, r);
}

// apply an operation on top of an other operation
operation combineO(operation ot, operation ob) {
  return ot + ob;
}

// apply an operation on a range with data
data apply(operation ot, data d) {
  return d + ot;
}

data getValue(int x) {
  return apply(o[x], t[x]);
}

void calcValue(int x) {
  t[x] = combineD(getValue(left(x)), getValue(right(x)));
}

void propagate(int x) {
  o[left(x)] = combineO(o[x], o[left(x)]);
  o[right(x)] = combineO(o[x], o[right(x)]);
  o[x] = operation();
}

// query the data on the range [a, b[
data query(int a, int b, int x = 0, int l = 0, int r = 1 << logmaxn) {
  if (a <= l && r <= b)
    return getValue(x);
  if (b <= l || r <= a)
    return data();
  int m = (l + r) / 2;
  propagate(x);
  data d = combineD(query(a, b, left(x), l, m), query(a, b, right(x), m, r));
  calcValue(x);
  return d;
}

// apply an operation on the range [a, b[
void apply(int a, int b, operation v, int x = 0, int l = 0, int r = 1 << logmaxn) {
  if (a <= l && r <= b) {
    o[x] = combineO(v, o[x]);
    return;
  }
  if (b <= l || r <= a)
    return;
  int m = (l + r) / 2;
  propagate(x);
  apply(a, b, v, left(x), l, m);
  apply(a, b, v, right(x), m, r);
  calcValue(x);
}

// get the data for the i-th position
data getData(int i) {
  if (i < n)
    return a[i];
  else
    return 0;
}

void init() {
  for (int i = 0; i < (1 << logmaxn); i++)
    t[to + i] = getData(i);
  for (int x = to - 1; x >= 0; x--)
    calcValue(x);
}


int N, R;
TII E[2*n_];

int main(){
	cin >> N >> R;
	for(int i = 0; i < N; ++i){
		int x, y;
		cin >> x >> y;
		//x+=cordOff; y += cordOff;
		int t = x+y;
		int h = x-y+2*cordOff;
		E[2*i] = make_tuple(t-R, false, h-R, h+R);
		E[2*i+1] = make_tuple(t+R, true, h-R, h+R);
	}
	sort(E, E+2*N);
	int mx = 0;
	for(int i = 0; i < 2*N; ++i){
		int t, hl, hr; bool isEnd;
		tie(t, isEnd, hl, hr) = E[i];
		//cerr << "t: " << t << " apply " << hl << " to " << hr << endl;
		apply(hl, hr+1, (isEnd?-1:+1));
		int q = query(0, 1 << logmaxn);
		//cerr << "query to"<< (1<<logmaxn) << " q: "<< q << endl;
		mx = max(mx, q);
	}
	cout << mx << endl;
	return 0;
}