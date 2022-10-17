import std.stdio;

int n;
int[] a;
int[2] z;
void main()
{
	readf("%d", &n);
	a.length = n;
	for(int i = 0; i < n; i++) {
		readf(" %d", &a[i]);
		z[a[i] % 2]++;
	}
	for(int i = 0; i < n; i++) {
		if (z[a[i] % 2] == 1) {
			writeln(i + 1);
		}
	}
}