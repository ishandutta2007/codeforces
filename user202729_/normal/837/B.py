import itertools

def check(lst):
	if not all(row.count(row[0]) == len(row) for row in lst): return False
	_ = [[k, list(g)] for k,g in itertools.groupby([x[0] for x in lst])]
	keys, groups = zip(*_)
	keys = list(keys)
	return len(keys) == len(set(keys)) == 3 \
		and \
		len(set( [len(list(x)) for x in groups] )) == 1

import sys
nrow, ncol = map(int, sys.stdin.readline().split(' '))
data = list( map(list, sys.stdin.read().split('\n')[:nrow]) )
sys.stdout.write("YES" if check(data) or check(list(zip(*data))) else "NO")