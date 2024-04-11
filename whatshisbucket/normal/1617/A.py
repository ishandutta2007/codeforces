import sys
inpu=sys.stdin.readline
prin=sys.stdout.write
I=lambda:[*map(int,inpu().split())]

t=I()[0]
for _ in range(t):
	s = [*inpu().strip()]
	t = inpu().strip()
	a = sorted(s)
	ass = a.count('a')
	bss = a.count('b')
	css = a.count('c')
	tot = ass + bss + css
	if t == 'abc' and ass > 0 and bss > 0 and css > 0:
		a = ['a'] * ass + ['c'] * css + ['b'] * bss + a[tot:]
	print(''.join(a))