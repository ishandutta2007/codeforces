import std.stdio;

int n, l, r, w;
int[] a;
int[2] z;
void main()
{
	readf("%d", &n);
	a.length = n;
	for(int i = 0; i < n; i++) {
		readf(" %d", &a[i]);
	}
	l = 0;
	r = n;
	w = 0;
	while(l < r) {
		if (a[l] > a[r - 1]) {
			z[w] += a[l++];
		} else {
			z[w] += a[--r];
		}
		w ^= 1;
	}
	writeln(z[0], ' ', z[1]);
}