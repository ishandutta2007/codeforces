import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

def layer(guy):
	curr = guy + 1
	l = 0
	while curr % 2 == 0:
		curr //= 2
		l += 1
	return l
def lllayers(n):
	return [layer(guy) for guy in range(n)]

def main():
	n = int(inpu())
	a = list(map(int, inpu().split()))
	b = list(map(int, inpu().split()))
	layers = int(math.log2(n))
	llayers = lllayers(n)
	powers = [1]
	for i in range(layers + 2):
		powers.append(2*powers[-1])

	highest = [(i + 1 - a[i], i) for i in range(n)]
	highest.sort()
	fallto = {i: [] for i in range(1, n+1)}
	for i in range(n):
		fallto[i + 1 + b[i]].append(i + 1)
	jumpto = [None]*n
	jumps = [-1]*n
	vals = [float('inf')]*(2**(layers+1)-1)
	best = [(float('inf'), float('inf'))]*(powers[layers+1]-1)

	its = 0
	for top, i in highest:
		its += 1
		if a[i] == i + 1:
			jumpto[i] = 0
			jumps[i] = 1
			for guy in fallto[i+1]:
				l = llayers[guy - 1]
				curr = guy - 1
				vals[guy - 1] = 1
				while l <= layers:
					if curr <= guy - 1:
						best[curr] = (1, guy - 1)
					curr = curr - curr%powers[l+2] + powers[l+1]-1
					l += 1
		else:
			curr = top - 1
			l = llayers[top - 1]
			good = (vals[curr], curr)
			while l <= layers:
				if curr >= top - 1 and best[curr][0] < good[0]:
					good = best[curr]
				curr = curr - curr%powers[l+2] + powers[l+1]-1
				l += 1
			jumps[i] = good[0] + 1
			jumpto[i] = good[1] + 1
			for guy in fallto[i+1]:
				l = llayers[guy - 1]
				curr = guy - 1
				vals[guy - 1] = good[0] + 1
				while l <= layers:
					if curr <= guy - 1 and good[0] + 1 < best[curr][0]:
						best[curr] = (good[0] + 1, guy - 1)
					curr = curr - curr%powers[l+2] + powers[l+1]-1
					l += 1
	if jumps[-1] == float('inf'):
		prin(str(-1))
	else:
		prin(str(jumps[-1]) + '\n')
		curr = n
		while curr != 0:
			prin(str(jumpto[curr-1]) + ' ')
			curr = jumpto[curr-1] + b[jumpto[curr-1]-1]

main()