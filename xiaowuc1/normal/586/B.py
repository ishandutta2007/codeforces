### TEMPLATE BEGIN

from collections import defaultdict

def read_int():
	return int(raw_input())

def read_ints():
	return (int(x) for x in raw_input().split())

def read_int_list():
	return [int(x) for x in raw_input().split()]

def read_float():
	return float(raw_input())

def read_floats():
	return (float(x) for x in raw_input().split())

def read_float_list():
	return [float(x) for x in raw_input().split()]

### TEMPLATE END

def solve():
	n = read_int()
	a = read_int_list()
	b = read_int_list()
	cross = read_int_list()
	ans = []
	for i in xrange(n):
		ans.append(sum(a[0:i]) + cross[i] + sum(b[i:]))
	ans = sorted(ans)
	print ans[0] + ans[1]

qq = 1
# qq = 2**30
# qq = read_int()
for _ in xrange(qq):
	solve()